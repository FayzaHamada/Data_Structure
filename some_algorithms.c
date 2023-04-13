#include <stdio.h>
#include <stdlib.h>

void Swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void BubblSort(int arr[], int size)
{
    int counter, index;
    int sorted = 0;

    for(counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;
        for(index = 0; index < size - 1 - counter; index++)
        {
            if(arr[index] > arr[index+1])
            {
                sorted = 0;
                Swap(&arr[index], &arr[index + 1]);
            }
        }
    }
}

void SelectionSort(int arr[], int size)
{
    int counter;
    for(counter = 0; counter < size - 1; counter++)
    {
        int minIndex = counter;
        int index;

        for(index = counter + 1; index < size; index++)
        {
            if(arr[index] < arr[minIndex])
            {
                minIndex = index;
            }
        }

        Swap(&arr[counter], &arr[minIndex]);
    }

}

void InsertionSort(int arr[], int size)
{
    int index, key, current;

    for(current = 1; current < size; current++)
    {
        key = arr[current];

        index = current - 1;

        while(index >= 0 && arr[index] > key)
        {
            arr[index + 1] = arr[index];
            index--;
        }

        arr[index + 1] = key;
    }
}

int BinarySearch(int[] arr, int size, int data)
{
    int minIndex = 0, maxIndex = size -1, midIndex;

    while(minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if(data == arr[midIndex])
            return midIndex;

        if(data > arr[midIndex])
            minIndex = midIndex + 1;
        else
            maxIndex = midIndex - 1;
    }

    return -1;
}

void Display(int arr[], int size)
{
    int index;

    for(index = 0; index < size; index++)
    {
        printf("%d   ", arr[index]);
    }
}

int main()
{
    int arr[6] = {5, 2, 4, 6, 3, 1};

    SelectionSort(arr, 6);

    Display(arr, 6);

    return 0;
}
