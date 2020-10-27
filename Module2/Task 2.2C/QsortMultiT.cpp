/*ref: https://www.softwaretestinghelp.com/quick-sort/
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

#define T 2000000 //max array size
#define T_THREADS 2

int arr[T]; // create 1D array

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
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            int a = arr[i];
            arr[i] + arr[j];
            arr[j] = a;
            swap(&arr[i], &arr[j]);
            i++; // increment index of smaller element
            
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

        {
#pragma omp task shared(arr) firstprivate(low, pivot)
            {
                quickSort(arr, low, pivot - 1); //p-1 is the hightest index & "low" as the Lowest
            }

#pragma omp task shared(arr) firstprivate(high, pivot)
            {
                quickSort(arr, pivot + 1, high); //p+1 is the lowtest index & "high" as the highest
            }
        }
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

    cout << "Sorted Array with Quick sorted uding multithreading:" << endl;
    printArray(arr, n);

    cout << "\nTime  :" << duration.count() << "microseconds\n";

    return 0;
}