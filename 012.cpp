/* Copyright 2014 Toxa Kniotee */
#include <stdio.h>
#include <cmath>    /* sqrt */

void triangle_numbers();
int factors_numbers(const unsigned NUMBER);

int main(int argc, char const *argv[]) {
    triangle_numbers();
    return 0;
}

void triangle_numbers() {
    unsigned sum = 1;
    int index = 1;

    while (factors_numbers(sum) <= 500) {
        sum += ++index;
    }

    printf("Result: %u\n", sum);
}

int factors_numbers(const unsigned NUMBER) {
    int total = 2;
    for (int i = 2; i < sqrt(NUMBER); i++) {
        if (NUMBER % i == 0) {
            total += 2;
        }
    }
    return total;
}
