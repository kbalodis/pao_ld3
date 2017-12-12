#include <iostream>
#include <time.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 2
#define ROWCOLS 3

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

    for (int i = 0; i < ROWCOLS; i++) {
        for (int j = 0; j < ROWCOLS; j++) {
            for (int k = 0; k < ROWCOLS; k++) {
                AB[i][j] = AB[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < ROWCOLS; i++) {
        for (int j = 0; j < ROWCOLS; j++) {
            std::cout << AB[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}