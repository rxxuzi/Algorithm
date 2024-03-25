#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK_SIZE 1024

int readFileToBinary(const char *filename, uint8_t **buffer, size_t *bufferSize) {
    FILE *file = fopen(filename, "rb"); 
    if (!file) {
        perror("Could not open file");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    *buffer = (uint8_t *)malloc(fileSize);
    if (!*buffer) {
        perror("Memory allocation failed.");
        fclose(file);
        return 2;
    }
    fread(*buffer, 1, fileSize, file);
    *bufferSize = fileSize; 
    fclose(file); 
    return 0; 
}

int writeBinaryToFile(const char *filename, size_t bufferSize, uint8_t *buffer) {
    FILE *file = fopen(filename, "wb"); 
    if (!file) {
        perror("Could not open file");
        return 1; 
    }
    size_t written = fwrite(buffer, 1, bufferSize, file);
    if (written != bufferSize) {
        perror("Failed to write to file");
        fclose(file);
        return 2; 
    }
    fclose(file); 
    return 0; 
}

int main() {
    const char *filename = "test.txt";
    uint8_t *buffer;
    size_t fileSize;
    int result = readFileToBinary(filename, &buffer, &fileSize);
    if (result == 0) {
        for (size_t i = 0; i < fileSize; i++) {
            printf("%02x", buffer[i]);
            if (i >= 20) {
                printf("...");
                break;
            } 
        }
    }

    result = writeBinaryToFile("out.txt", fileSize, buffer);
    if (result == 0) {
        printf("\nFile written successfully.\n");
    }
    free(buffer);

    return 0;
}
