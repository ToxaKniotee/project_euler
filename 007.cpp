/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <vector>
#include <cmath> /* sqrt */

void eratosthenes_sieve(unsigned const bound,
        std::vector<unsigned> *primes);

int main(int argc, char const *argv[]) {
    std::vector<unsigned> primes;
    // eratosthenes_sieve(4294967295, &primes);
    eratosthenes_sieve(500000, &primes);
    return 0;
}

void eratosthenes_sieve(unsigned const bound, std::vector<unsigned> *primes) {
    bool *sieve = new bool[bound];
    int index = 0;

    for (unsigned i = 0; i < bound; i++) {
        sieve[i] = true;
    }

    printf("%i: %u\n", ++index, 2);
    primes->push_back(2);

    for (unsigned i = 3; i < bound; i += 2) {
        if (sieve[i]) {
            sieve[i] = false;
            primes->push_back(i);
            printf("%i: %u\n", ++index, i);

            if (primes->size() == 10001) {
                printf("10001 prime number: %u\n", *(primes->end() - 1));
                delete[] sieve;
                return;
            }

            if (i <= sqrt(bound)) {
                for (unsigned j = 0; ; j++) {
                    unsigned temp;
                    temp = i * i + j * i;
                    if (temp >= bound) break;
                    sieve[temp] = false;
                }
            }
        }
    }
    delete[] sieve;
}
