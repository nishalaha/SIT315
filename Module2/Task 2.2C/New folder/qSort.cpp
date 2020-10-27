/*
    This program was created for SIT315: M2.T2C by Cameron Boyd | Student #218275923
*/

#include <stdio.h> // Input and output
#include <stdlib.h> // srand() and rand()
#include <chrono> // Timing

using namespace std; // Use std as the namespace to avoid having to write std::library

#define MAX 2000000 // Set a maximum array size

int to_sort[MAX]; // Create a one-dimensional array of size MAX

/*
    This function takes an array with its lowest and highest indexes and checks if a given value in the array is less than the pivot point, if so:
        - move the value to array[i] where i is the lowest unsorted value
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

/*
    The quicksort function runs the partition function on the array (creates a partially ordered array) and then runs two quicksort functions:
    - the first uses low as its lowest index and p - 1 as its highest
    - the second uses p + 1 as its lowest index and high as its highest
*/
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

// This function is to simply print the given array to the console/terminal under the format of [x, y, z, ...]
void printArray(int arr[])
{
    printf("\n[");
    for (int i = 0; i < MAX - 1; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("%i]\n", arr[MAX-1]);
}

int main()
{
    // Use the computer's internal clock as a seed for rand()
    srand((unsigned int)time(NULL));

    // Fill the array with random values from 0 to 100
    for (int i = 0; i < MAX; i++)
    {
        to_sort[i] = rand() % 100;
    }

    // // Print unsorted array
    // printf("Unsorted array:");
    // printArray(to_sort);

    // Get a start time
    auto start = chrono::high_resolution_clock::now();

    // Run the quicksort algorithm on the randomised array
    quicksort(to_sort, 0, MAX-1);

    // Get a finish time
    auto finish = chrono::high_resolution_clock::now();

    // // Print sorted array
    // printf("\nSorted array:");
    // printArray(to_sort);

    // Calculate and print the time take to sort the array using quicksort
    auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start);
    printf("\nTime taken to sort the array via quicksort: %li milliseconds.\n", duration.count());

    return 0;
}