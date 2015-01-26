/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <inttypes.h>   /* uint64_t, PRIu64 */
#include <cmath>    /* sqrt */

void eratosthenes_sieve(const int BOUND);

int main(int argc, char const *argv[]) {
    eratosthenes_sieve(2000000);
    eratosthenes_sieve(10);
    return 0;
}

void eratosthenes_sieve(const int BOUND) {
    const int SQUARE = sqrt(BOUND);
    bool sieve[BOUND];
    uint64_t sum = 2;

    for (int i = 0; i < BOUND; i++) {
        sieve[i] = true;
    }

    for (int i = 3; i < BOUND; i+= 2) {
        if (sieve[i]) {
            sum += i;
            sieve[i] = false;

            if (i <= SQUARE) {
                int temp;
                for (int j = 0; (temp = i + j * i) < BOUND; j++) {
                    sieve[temp] = false;
                }
            }
        }
    }

    printf("Sum: %" PRIu64 "\n", sum);
}
