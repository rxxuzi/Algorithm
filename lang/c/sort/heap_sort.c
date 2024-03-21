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

static void heapify(int *arr, int idx, int max) {
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;
    int largest;
    if (l < max && cmp(arr[l], arr[idx]) > 0) {
        largest = l;
    } else {
        largest = idx;
    }
    
    if (r < max && cmp(arr[r], arr[largest]) > 0) {
        largest = r;
    }

    if (largest != idx) {
        swap(&arr[idx], &arr[largest]);
        heapify(arr, largest, max);
    }
}

static void build_heap(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, i, size);
    }
}

void heap_sort(int *arr, int size){
    build_heap(arr, size);
    for (int i = size - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i);
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

    heap_sort(arr, size);
    puts("\n After : \n");

    for (int i = 0; i < size; i+= 100){
        printf("%03d ", arr[i]);
    }

    return 0;
}
