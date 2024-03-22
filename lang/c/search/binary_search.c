#include <stdio.h>
#include <stdlib.h>

int search(int* list, int size, int data);
int isExist(int* list, int size, int data);

int main(int argc, char const *argv[]){
    
    int arr[7] = {1,2,3,4,5,6,7};
    int data = 5;
    int index = search(arr, 7, data);
    printf("index = %d\n", index);
    int exist = isExist(arr, 7, data);
    printf("isExist = %d\n", exist);
    return 0;
}

int search(int* list, int size, int data){
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    while (low <= high){
        if (list[mid] == data) {
            return mid;
        } else if (list[mid] > data) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
}

int isExist(int* list, int size, int data){
    return search(list, size, data) != -1;
}