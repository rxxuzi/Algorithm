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

static int select_min(int arr[], int l, int r){
    int min = l;
    for (int i = l + 1; i <= r; i++){
        if (cmp(arr[i], arr[min]) < 0){
            min = i;
        }
    }
    return min;
}

void selection_sort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int min = select_min(arr, i, size - 1);
        if (min != i){
            swap(&arr[i], &arr[min]);
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

    selection_sort(arr, size);
    printf("\n After : \n");
    for (int i = 0; i < size; i+= 100){
        printf("%03d ", arr[i]);
    }

    return 0;
}
