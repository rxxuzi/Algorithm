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
/** 
 * @brief Partition function. Partition an array into two parts based on a pivot. *
 * @param arr array 
 * @param l leftmost index
 * @param r rightmost index
 * @param p pivot index
 * @return int new pivot position
 */
int partition(int arr[], int l, int r, int p){
    int idx, store;
    int pivot = arr[p]; 
    swap(&arr[r], &arr[p]); 
    store = l;
    for (idx = l; idx < r; idx++){
        if (cmp(arr[idx], pivot) <= 0){
            swap(&arr[idx], &arr[store]); 
            store++;
        }
    }

    swap(&arr[store], &arr[r]); 
    return store;
}

/**
 * @brief quick sort function
 * 
 * @param arr array
 * @param left Leftmost index
 * @param right Rightmost index
 */
void quick_sort(int arr[], int left, int right){
    if (left < right) {
        int pivot = left + (right - left) / 2; // Pivot set to center
        int newPivot = partition(arr, left, right, pivot);
        quick_sort(arr, left, newPivot - 1); // Sort left half
        quick_sort(arr, newPivot + 1, right); // Sort right half
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

    quick_sort(arr, 0, size - 1);
    puts("\n After : \n");

    for (int i = 0; i < size; i+= 100){
        printf("%03d ", arr[i]);
    }

    return 0;
}
