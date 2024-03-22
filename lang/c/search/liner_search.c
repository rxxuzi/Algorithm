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

int search(int* list, int size, int data) {
	for (int i = 0; i < size; i++) {
		if (data == list[i]) return i;
	}
	return -1;
}

int isExist(int* list, int size, int data) {
    return search(list, size, data) != -1;
}

