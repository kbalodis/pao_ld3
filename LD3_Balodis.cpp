#include <iostream>
#include <time.h>
#include <stdlib.h>

#define ROWCOLS 500

void basic_matrix_multiple(float A[ROWCOLS][ROWCOLS], float B[ROWCOLS][ROWCOLS], float AB[ROWCOLS][ROWCOLS]) {
    for (int i = 0; i < ROWCOLS; i++) {
        for (int j = 0; j < ROWCOLS; j++) {
            for (int k = 0; k < ROWCOLS; k++) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// https://stackoverflow.com/questions/4300663/how-to-speed-up-matrix-multiplication-in-c
void advanced_matrix_multiple(float A[ROWCOLS][ROWCOLS], float B[ROWCOLS][ROWCOLS], float AB[ROWCOLS][ROWCOLS]) {
    for (int i = 0; i < ROWCOLS; i++) {
        for (int k = 0; k < ROWCOLS; k++) {
            for (int j = 0; j < ROWCOLS; j++) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

template<typename T>
void Transpose(int size, T** m)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            std::swap(m[i][j], m[j][i]);
        }
    }
}

// https://blogs.msdn.microsoft.com/xiangfan/2009/04/28/optimize-your-code-matrix-multiplication/
void transpose_matrix_multiple(float A[ROWCOLS][ROWCOLS], float B[ROWCOLS][ROWCOLS], float AB[ROWCOLS][ROWCOLS])
{
    for (int i = 0; i < ROWCOLS; i++) {
        for (int j = i + 1; j < ROWCOLS; j++) {
            std::swap(B[i][j], B[j][i]);
        }
    }
    for (int i = 0; i < ROWCOLS; i++) {
        for (int j = 0; j < ROWCOLS; j++) {
            for (int k = 0; k < ROWCOLS; k++) {
                AB[i][j] += A[i][k] * B[j][k];
            }
        }
    }
}

int main() {
    float A[ROWCOLS][ROWCOLS];
    float B[ROWCOLS][ROWCOLS];
    float AB[ROWCOLS][ROWCOLS];

    srand(time(NULL));

    for (int i = 0; i < ROWCOLS; i++) {
        for (int j = 0; j < ROWCOLS; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
            AB[i][j] = 0;
        }
    }

    // basic_matrix_multiple(A, B, AB);
    // advanced_matrix_multiple(A, B, AB);
    transpose_matrix_multiple(A, B, AB);

    return 0;
}