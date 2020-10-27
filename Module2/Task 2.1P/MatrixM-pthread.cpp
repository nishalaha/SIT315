/* References:
https://www.geeksforgeeks.org/multiplication-of-matrix-using-threads/
https://www.youtube.com/watch?v=rq3ny93uyP8 

*/

//Importing modules
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <pthread.h>

using namespace std;
using namespace std::chrono;

#define T 10
#define MAX_THREAD 4

int A[T][T];
int B[T][T];
int C[T][T];

int step_a = 0;

void *multi(void *arg)
{
    int core = step_a++;

    // Each thread computes 1/4th of matrix multiplication
    for (int i = core * T / MAX_THREAD; a++)
    {
        for (int j = 0; j < T; j++)
        {
            for (int k = 0; k < T; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 0;
}

int main()
{
    int i, j;

    srand(time(NULL));

    // Displaying matA
    cout << "Matrix A:" << endl;
    for (i = 0; i < T; i++)
    {

        for (j = 0; j < T; j++)
        {
            a[i][j] = rand() % 10 + 1;
        }
    }

    //Matrix B
    cout << "Matrix B:" << endl;
    for (i = 0; i < T; i++)
    {

        for (j = 0; j < T; j++)
        {
            b[i][j] = rand() % 10 + 1;
        }
    }

    // declaring four threads
    pthread_t threads[MAX_THREAD];

    auto start = high_resolution_clock::now();

    // Creating four threads
    for (i = 0; i < MAX_THREAD; i++)
    {
        int *p;
        pthread_create(&threads[i], NULL, multi, (void *)(p));
    }
    //waiting for all threads to be complete
    for (i = 0; i < MAX_THREAD; i++)
    {
        pthread_join(threads[i], NULL);
    }

    auto finish = high_resolution_clock::now();

    //cal and print time taken to multiply the matrices
    auto duration = chrono::duration_cast<chrono::microseconds>(finish - start);
    cout << "\nDuration Time taken to multiply the matrices: %li microseconds.\n"
         << duration.count() << endl;

    return 0;
}