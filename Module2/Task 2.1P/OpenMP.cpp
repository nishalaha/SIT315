
/* References:

https://www.youtube.com/watch?v=rq3ny93uyP8 

*/

// Import necessary modules
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <omp.h>

// Set the namespace
using namespace std;
using namespace std::chrono;

#define T 1000
#define MAX_THREAD 2 //no of threads

int A[T][T];
int B[T][T];
int C[T][T];

int main()
{
    int k, i, j;
    srand(time(NULL));

    cout << "Matrix A:" << endl;
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            A[i][j] = rand() % 10 + 1;
        }
    }
    cout << endl;

    cout << "Matrix B:" << endl;
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            B[i][j] = rand() % 10 + 1;
        }
    }
    cout << endl;

    // Start record time
    auto begin = chrono::high_resolution_clock::now();

#pragma omp parallel shared(A, B, C) private(i, j, k) {
#pragma omp for schedule(static)

    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            for (k = 0; k < T; k++)
            {
                C[j][i] += A[i][k] * B[k][j];
            }
        }
    }
}
// Record finishing time
auto finish = chrono::high_resolution_clock::now();

//cal and print time taken to multiply the matrices
auto duration = chrono::duration_cast<chrono::microseconds>(finish - begin);
cout << "\nDuration Time taken to multiply the matrices: %li microseconds.\n"
     << duration.count() << endl;
}
return 0;
}