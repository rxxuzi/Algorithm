#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(int a, int b){
    return a - b;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_sort(int arr[], int size){
    for (int j = 1; j < size; j++){
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && cmp(arr[i], key) > 0){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

int main(int argc, char const *argv[]){
    srand(time(NULL));
    const int size = 1000;
    int arr[size];
    for (int i = 0; i < size; i++){
        arr[i] = rand() % size;
    }

    for (int i = 0; i < size; i+= 100){
        printf("%03d ", arr[i]);
    }

    insert_sort(arr, size);
    puts("\n After : \n");

    for (int i = 0; i < size; i+= 100){
        printf("%03d ", arr[i]);
    }

    return 0;
}
