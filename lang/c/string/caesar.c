#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void caesar(const char *input, char *output, int shift) {
    int i = 0;
    while (input[i] != '\0') {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        output[i] = ch;
        i++;
    }
    output[i] = '\0'; 
}

int main(int argc, char const *argv[]){
    int shift = 1;
    char input[100];
    printf("Input  -> ");
    fgets(input, sizeof(input), stdin); 
    printf("Shift  -> ");
    scanf("%d", &shift);
    char output[100];
    caesar(input, output, shift);
    printf("Output -> %s\n", output);
    return 0;
}
