/* Copyright 2015 Toxa Kniotee */
#include <stdio.h>
#include <inttypes.h>

#define number 20
#define limit (number) + 1
#define cell(y, x) (y) * (limit) + (x)

int main(int argc, char const *argv[]) {
    int matrix_s = (limit) * (limit);
    uint64_t *matrix = new uint64_t[matrix_s];

    for (int i = 0; i < limit; i++) {
        matrix[cell(i, 0)] = 1;
        matrix[cell(0, i)] = 1;
    }
    for (int i = 1; i < limit; i++) {
        for (int j = 1; j < limit; j++) {
            matrix[cell(i, j)] = matrix[cell(i, j - 1)] +
                matrix[cell(i - 1, j)];
        }
    }
    printf("number of paths: %" PRIu64 "\n", matrix[matrix_s - 1]);
    delete[] matrix;
    return 0;
}
