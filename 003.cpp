/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <cmath>    /* sqrt */

#define NUMBER 600851475143

bool isPrime(int number);

int main(int argc, char const *argv[]) {
    unsigned int factor = sqrt(NUMBER);
    if (factor % 2 == 0)
        factor--;
    for (factor; factor > 1; factor-=2) {
        if (NUMBER % factor == 0 && isPrime(factor)) {
            printf("Max factor: %u\n", factor);
            break;
        }
    }
    return 0;
}

bool isPrime(int number) {
    /* Checa si un numero es primo */
    for (int i = 2; i < sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
