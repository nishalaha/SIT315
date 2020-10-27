/*ref: https://www.softwaretestinghelp.com/quick-sort/

https://www.geeksforgeeks.org/quick-sort/
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define T 2000000 //max array size

int arr[T]; //creating 1D array

// Swap two elements - Utility function
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low + 1);

    for (int j = low; j <= high - 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            // int a = arr[i];
            // arr[i] + arr[j];
            // arr[j] = a;

            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]); 
        }
    }
    // int a = arr[1];
    // arr[i] = arr[high];
    // arr[high] = a;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //arry is partitioned
        int pivot = partition(arr, low, high);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

//printing the array to the terminal
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < T; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input Array:" << endl;
    printArray(arr, n);

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto finish = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(finish - start);

    cout << "Sorted Array with Quick sort sequentially:" << endl;
    printArray(arr, n);

    cout << "\nTime  :" << duration.count() << "microseconds\n";

    return 0;
}