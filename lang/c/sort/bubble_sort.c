#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
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

    bubble_sort(arr, size);
    puts("\n After : \n");

    for (int i = 0; i < size; i+= 100){
        printf("%03d ", arr[i]);
    }

    return 0;
}
