#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xor(const char *str, const char *key, char *result, int len) {
    int key_len = strlen(key);
    for (int i = 0; i < len; i++) {
        result[i] = str[i] ^ key[i % key_len];
    }
}

void enc(const char *str, const char *key, char *encrypted) {
    int len = strlen(str);
    xor(str, key, encrypted, len);
}

void dec(const char *encrypted, const char *key, char *decrypted, int len) {
    xor(encrypted, key, decrypted, len);
}

int main(void) {
    char str[256];
    char key[256] = "key";
    char encrypted[256];
    char decrypted[256];
    
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin); 
    
    int len = strlen(str);
    
    // 暗号化
    enc(str, key, encrypted);
    encrypted[len] = '\0';
    printf("Encrypted: ");
    for (int i = 0; i < len; i++) {
        printf("%02x", (unsigned char)encrypted[i]);
    }
    printf("\n");
    
    // 復号化
    dec(encrypted, key, decrypted, len);
    decrypted[len] = '\0'; 
    printf("Decrypted: %s\n", decrypted);
    
    return 0;
}
