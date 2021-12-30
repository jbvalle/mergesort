#include <stdio.h>
#include <stdlib.h>

#define max 10

void merge(int *arr, int low, int mid, int high) {

    int *temp = malloc((high - low + 1)*sizeof(int));
    int i, j, k;

    for(i = low, j = mid + 1, k = 0; (i <= mid)&&(j <= high); k++){

        if(arr[i] < arr[j]){

            temp[k] = arr[i++];
        }else{

            temp[k] = arr[j++];
        }
    }

    while(i <= mid){

        temp[k] = arr[i++];   
        k++;
    }

    while(j <= high){

        temp[k] = arr[j++];
        k++;
    }

    for(int x = low, y = 0; x <= high; x++){

        arr[x] = temp[y++];
    }

}

void mergeSort(int *arr, int l, int r){

    if(l < r){

        int mid = (l + r)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() { 

    int arr[5] = {8, 2, 5, 4, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);

}
