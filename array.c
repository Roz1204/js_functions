#include <stdio.h>
#include "array_function_in_js.h"
#include <stdlib.h>

int main()
{
    int size = 4;
    int* arr = (int*)malloc(sizeof(int) * size);

    // for(int i = 0; i < size; ++i)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // splice1(arr, &size, -1, 2);
    // splice(arr, &size, 0);
    // for(int i = 0; i < size; ++i)
    // {
    //     printf("%d ", arr[i]);
    // }   
    // struct Entry result[size];
    // entries(arr, size, result);
    
    // for(int i = 0; i < size; ++i)
    // {
    //     printf("%d : %d\n", result[i].key, result[i].value);
    // }

    // int* tmp = with(arr, size, 2, 6);
    // printf("%d ", join(arr, size));
    // int* tmp = entry(arr, size);
    
    // int * tmp = slice2(arr, size, 2);
    // sort(arr, size);
    // printf("%d", some(arr, size, foo));
    // int* tmp = map(arr, size, callbeck);

    // // 
    int* tmp = slice1(arr, &size, 0, 1);
    // // int* tmp = slice1(arr, &size, -2);
    // // int* tmp = slice1(arr, size, 2, 4);

    // int* tmp = filter(arr, &size, foo);
    // slice(arr, size);

    for(int i = 0; i < size; ++i)
    {
        printf("%d ", tmp[i]);
    }    

    // printf("%d ", reduce1(arr, 5, f));

    // printf("%d ", reduce(arr, 5, f, 1));

    // splice(arr, &size, 2);
    // for(int i = 0; i < 5; ++i)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // int arr1[4] = {1, 5, 2, 4};
    // int arr2[5] = {5, -6, 7, 8, 9};

    // printf("%d ", find1(arr1, 4, foo, 2));

    // printf("%d ", find(arr1, 4, foo));

    // printf("%d ", findIndex1(arr1, 4, foo, 3));

    // printf("%d ", findIndex(arr1, 4, foo));

    // printf("%d ", findLastIndex1(arr1, 4, foo, 1));

    // printf("%d ", findLastIndex(arr1, 4, foo));

    // printf("%d ", includes1(arr1, 4, 3, 1));

    // printf("%d ", includes(arr1, 4, 32));

    // fill2(arr1, 4, 0, 2, 4);
    // for(int i = 0; i < size1; ++i)
    // {
    //     printf("%d ", arr1[i]);
    // }

    // fill1(arr1, 4, 0, 2);
    // for(int i = 0; i < size1; ++i)
    // {
    //     printf("%d ", arr1[i]);
    // }

    // fill(arr1, 4, 0);
    // for(int i = 0; i < size1; ++i)
    // {
    //     printf("%d ", arr1[i]);
    // }

    // reverse(arr2, 5);
    // for(int i = 0; i < 5; ++i)
    // {
    //     printf("%d ", arr2[i]);
    // }

    // printf("%d ", lastIndexOf1(arr1, 4, 4, 2));

    // printf("%d ", lastIndexOf(arr1, 4, 3));

    // printf("%d ", indexOf1(arr1, 4, 4, 2));

    // forEach(arr1, 4, print);
    
    // printf("%d \n", every1(arr2, 4, foo, 3));
    // printf("%d \n", every(arr2, 4, foo));

    // int* res = concat(arr1, arr2, 4, 4);
    // for(int i = 0; i < 8; ++i)
    // {
    //     printf("%d ", res[i]);
    // }
    // free(res);
}