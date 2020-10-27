/* References:
https://www.youtube.com/watch?v=rq3ny93uyP8 
*/

//impoting moduels
#include <ctime>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

//setting the namespace
using namespace std;
using namespace std::chrono;

#define T 1000

// Create three matrices
int A[T][T];
int B[T][T];
int C[T][T];

int main()
{
    int j, i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        { //assisgning i and j to a random number
            A[i][j] = rand() % 10 + 1;
            B[i][j] = rand() % 10 + 1;
        }
    }

    int A_rows = sizeof(A) / sizeof(A[0]);
    int A_cols = sizeof(A[0]) / sizeof(A[0][0]);

    int B_rows = sizeof(B) / sizeof(B[0]);
    int B_cols = sizeof(B[0]) / sizeof(B[0][0]);

    if (A_cols == B_rows) //if this condition is true the multiplication can be done
    {
        auto begin = high_resolution_clock::now();

        //matrix C is calculated using A and B
        for (int p = 0; p < A_rows; p++)
        {
            for (int q = 0; q < B_cols; q++)
            {

                for (int r = 0; r < B_rows; r++)
                {
                    C[p][q] += A[p][r] * B[q][r];
                }
            }
        }

        auto finish = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(finish - begin);

        cout << "\nDuration Time taken to calculate the matrix: %li microseconds.\n"
             << duration.count() << endl;
    }

    return 0;
}