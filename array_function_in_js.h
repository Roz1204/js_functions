#ifndef ARRAY
#define ARRAY

#include <stdlib.h>

void flatten(int* arr, int size, int result[], int* result_size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            result[(*result_size)++] = arr[i];
        } else {
            flatten(arr + i, sizeof(arr[i]) / sizeof(arr[i][0]), result, result_size);
        }
    }
}

void splice1(int* arr, int* size, int index, int deleteCount)
{
    if(index >= 0 && index < *size)
    {
        for(int i = index; i < *size - deleteCount; ++i)
        {
            arr[i] = arr[i + deleteCount];
        }
        *size = *size - deleteCount;
    }
}

void splice(int*arr, int* size, int index)
{
    if(index >= 0 && index < *size)
    {
        *size = *size - index;
    }
}

struct Entry
{
    int key;
    int value;
};

void entries(const int* arr, const int size, struct Entry* res) 
{
    for (int i = 0; i < size; ++i) {
        res[i].key = i;
        res[i].value = arr[i];
    }
}

int* with(int* arr, int size, int index, int elem)
{
    int* tmp = (int*)malloc(sizeof(int) * size);
    if(tmp == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < size; ++i)
    {
        tmp[i] = arr[i];
    }
    tmp[index] = elem;
    return tmp;
}

int join(int* arr, int size)
{
    for(int i = 0; i < size; ++ i)
    {
        if(arr[i] < 0)
        { 
            return 0;
        }
    }
    int mul = 10;
    int res = arr[0];
    for(int i = 1; i < size; ++i)
    {
        int x = arr[i];
        while(x > 10)
        {
            mul *= 10;
            x /= 10;
        }
        res = res * mul + arr[i];
    }
    return res;
}

int* slice2(const int *arr, const int size, const int start)
{
    if (start >= 0 && start < size) 
    {
        int *result = (int*)malloc((size - start) * sizeof(int));

        if (result == NULL) {
            return NULL;
        }

        for (int i = start, j = 0; i < size; ++i) 
        {
            result[j++] = arr[i];
        }
        return result;
    } 
    else if (start < 0 && abs(start) < size) 
    {
        int *result = (int*)malloc(abs(start) * sizeof(int));

        if (result == NULL) {
            return NULL;
        }

        for (int i = size - abs(start), j = 0; i < size; ++i) 
        {
            result[j++] = arr[i];
        }
        return result;
    }
    return NULL;
}

int* slice1(const int *arr, int* size, const int start, const int end)
{
    if (start >= 0 && end <= *size && start <= end) 
    {
        int *res = (int*)malloc(sizeof(int)*(end - start));

        if (res == NULL) 
        {
            return NULL;
        }

        for (int i = start, j = 0; i < end; ++i) 
        {
            res[j++] = arr[i];
        }
        *size = end - start;
        return res;

    } 
    else if (start >= 0 && end <= 0) 
    {
        int *res = (int*)malloc(sizeof(int) * (*size - start - abs(end)));

        if (res == NULL) 
        {
            return NULL;
        }

        for (int i = start, j = 0; i < *size - abs(end); ++i) 
        {
            res[j++] = arr[i];
        }
        *size = *size - abs(end);
        return res;
    }
    return NULL;
}

void slice(const int* arr, int size)
{

}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, int size)
{ 
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int some(const int* arr, int size, int(*f)(int))
{
    for(int i = 0; i < size; ++i)
    {
        if(f(arr[i]))
        {
            return 1;
        }
    }
    return 0;
}

int* map(const int *arr, const int size, int(*callback)(int))
{
    int *res = (int*)malloc(size * sizeof(int));
    if (res == NULL)
    {
        printf("%s\n", "Memory allocation failed!");
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        res[i] = callback(arr[i]);
    }
    return res;
}

int callbeck(int x)
{
    return x * 5;
}

int* filter(const int* arr, int* size, int(*f)(int))
{
    int* tmp = (int*)malloc(sizeof(int) * (*size));
    if (tmp == NULL) 
    {
        return NULL;
    }
    int j = 0;
    for(int i = 0; i < *size; ++i)
    {
        if(f(arr[i]))
        {
            tmp[j] = arr[i];
            ++j;
        }
    }
    *size = j;
    return tmp;
}

int reduce1(const int* arr, int size, int(*f)(int, int))
{
    int res = 0;
    for(int i = 0; i < size; i += 2)
    {
       res += f(arr[i], arr[i + 1]);
    }
    return res;
}

int reduce(const int* arr, int size, int(*f)(int, int), int value)
{
    int res = value;
    for(int i = 0; i < size; ++i)
    {
       res = f(res, arr[i]);
    }
    return res;
}

int f(int accumulator, int currentValue)
{
    return accumulator + currentValue;
}

int find1(const int* arr, int size, int(*f)(int), int index)
{
    if(index >= 0 && index < size)
    {
        for(int i = 0; i < index; ++i)
        {
            if(f(arr[i]))
            {
                return arr[i];
            }
        }
        return -1;
    }
}

int find(const int* arr, int size, int(*f)(int))
{
    for(int i = 0; i < size; ++i)
    {
        if(f(arr[i]))
        {
            return arr[i];
        }
    }
    return -1;
}

int findIndex1(const int* arr, int size, int(*f)(int), int index)
{
    if(index >= 0 && index <= size)
    {
        for(int i = 0; i < index; ++i)
        {
            if(f(arr[i]))
            {
                return i;
            }
        }
        return -1;
    }
}

int findIndex(const int* arr, int size, int(*f)(int))
{
    for(int i = 0; i < size ; ++i)
    {
        if(f(arr[i]))
        {
            return i;
        }
    }
    return -1;
}

int findLastIndex1(const int* arr, int size, int(*f)(int), int index)
{
    if(index >= 0 && index < size)
    {
        for(int i = size - 1; i >= index; --i)
        {
            if(f(arr[i]))
            {
                return i;
            }
        }
        return -1;
    }
}

int findLastIndex(const int* arr, int size, int(*f)(int))
{
    for(int i = size - 1; i >= 0; --i)
    {
        if(f(arr[i]))
        {
            return i;
        }
    }
    return -1;
}

int includes1(const int* arr, int size, int elem, int index)
{
    if(index >= 0 && index < size )
    {
        if(arr[index] == elem)
        {
            return 1;
        }
        return 0;
    }
}

int includes(const int* arr, int size, int elem)
{
    {
        for(int i = 0; i < size; ++i)
        {
            if(arr[i] == elem)
            {
                return 1;
            }
        }
        return 0;
    }
}

void fill2(int* arr, int size, int value, int start, int end)
{
    if(start >= 0 && start < size && end >= 0 && end <= size && end >= start)
    {
        for(int i = start; i < end; ++i)
        {
            arr[i] = value;
        }
    }
}

void fill1(int* arr, int size, int value, int start)
{
    if(start >= 0 && start < size)
    {
        for(int i = start; i < size; ++i)
        {
            arr[i] = value;
        }
    }
}

void fill(int* arr, int size, int value)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = value;
    }
}

void reverse(int* arr, int size)
{
    int tmp = 0;
    for(int i = 0; i < size / 2; ++i)
    {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}

int lastIndexOf1(const int* arr, int size, int elem, int index)
{
    int count = 0;
    int in = 0;

    if(index >= 0 && index < size)
    {
        for(int i = size - 1; i >= 0; --i)
        {
            if(arr[i] == elem)
            {
                ++count;
            }
            if(count == index)
            {
                return i;
            }
        }
        return -1;
    }
}

int lastIndexOf(const int* arr, int size, int elem)
{
   for(int i = size - 1; i >= 0; --i)
    {
        if(arr[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int indexOf1(const int* arr, int size, int elem, int index)
{
    int count = 0;
    int in = 0;

    if(index >= 0 && index < size)
    {
        for(int i = 0; i < size; ++i)
        {
            if(arr[i] == elem)
            {
                ++count;
            }
            if(count == index)
            {
                return i;
            }
        }
        return -1;
    }
}

int indexOf(const int* arr, int size, int elem)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

void forEach(const int* arr, int size, void (*callback)(int)) 
{
  for (int i = 0; i < size; ++i) 
  {
    callback(arr[i]);
  }
}

void print(int x)
{
    printf("%d ", x);
}

int foo(int x)
{
    if(x % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int every1(const int* arr, int size, int(*callback)(int), int index)
{
    if(index >= 0 && index < size)
    {
        for(int i = 0; i < index; ++i)
        {
            if(!callback(arr[i]))
            {
                return 0;
            }
        }
        return 1;
    }
}

int every(const int* arr, int size, int(*callback)(int))
{
    for(int i = 0; i < size; ++i)
    {
        if(!callback(arr[i]))
        {
            return 0;
        }
    }
    return 1;
}

int* concat(const int* arr1, int* arr2, int size1, int size2)
{
    int* arr3 = (int*)malloc(sizeof(int) * (size1 + size2));
    if (arr3 == NULL) 
    {
        return NULL;
    }
    int i = 0;
    for(; i < size1; ++i)
    {
        arr3[i] = arr1[i];
    }

    for(int j = 0; j < size2; ++j, ++i)
    {
        arr3[i] = arr2[j];
    }
    return arr3;
}

#endif