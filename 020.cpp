/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <inttypes.h>
#include "libraries/BigInt/BigIntegerLibrary.hh"

int main(int argc, char const *argv[]) {
    uint64_t sum = 0;
    BigInteger factorial(1);
    for (int i = 2; i <= 100; i++) {
        factorial *= i;
    }

    while (factorial > 0) {
        sum += (factorial % 10).toInt();
        factorial /= 10;
    }

    printf("Sum: %" PRIu64 "\n", sum);
    return 0;
}
