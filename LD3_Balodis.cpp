#include <iostream>
#include <time.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 2

int main() {
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int AB[ROWS][COLS];

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
            AB[i][j] = 0;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout<<A[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}