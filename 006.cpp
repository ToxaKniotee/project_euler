/* Copyright 2015 ToxaKniotee */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int sum_squares = 0;
    int squares_sum = 0;

    for (int i = 1; i <= 100; i++) {
        sum_squares += i * i;
        squares_sum += i;
    }

    squares_sum *= squares_sum;

    printf("Result: %i\n", squares_sum - sum_squares);
    return 0;
}
