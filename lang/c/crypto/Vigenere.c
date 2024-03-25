#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MOD(a, b) ((a % b + b) % b)

char* Cipher(char* input, char* key, bool encipher) {
	int keyLen = strlen(key);

	for (int i = 0; i < keyLen; ++i) {
		if (!isalpha(key[i])) {
			return "";
        }
    }

	int inputLen = strlen(input);
	char* output = (char*)malloc(inputLen + 1);
	int nonAlphaCharCount = 0;

	for (int i = 0; i < inputLen; i++) {
		if (isalpha(input[i])) {
			bool cIsUpper = isupper(input[i]);
			char offset = cIsUpper ? 'A' : 'a';
			int keyIndex = (i - nonAlphaCharCount) % keyLen;
			int k = (cIsUpper ? toupper(key[keyIndex]) : tolower(key[keyIndex])) - offset;
			k = encipher ? k : -k;
			char ch = (char)((MOD(((input[i] + k) - offset), 26)) + offset);
			output[i] = ch;
		} else {
			output[i] = input[i];
			nonAlphaCharCount++;
		}
	}

	output[inputLen] = '\0';
	return output;
}

char* Encipher(char* input, char* key) {
	return Cipher(input, key, true);
}

char* Decipher(char* input, char* key) {
	return Cipher(input, key, false);
}

int main(int argc, char const *argv[]) {
    char* text = "Hello World";
    char* key = "key";
    char* enciphered = Encipher(text, key);
    char* deciphered = Decipher(enciphered, key);
    printf("%s\n", enciphered);
    printf("%s\n", deciphered);
    free(enciphered);
    free(deciphered);
    return 0;
}
