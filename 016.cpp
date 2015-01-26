/* Copyright 2015 Toxa Kniotee */
#include <stdio.h>
#include <string>
#include <inttypes.h>
#include "libraries/BigInt/BigIntegerLibrary.hh"

using std::string;

int main(int argc, char const *argv[]) {
    BigInteger a(2);
    uint64_t sum = 0;

    for (int i = 1; i < 1000; i++) {
        a *= 2;
    }

    while (a != 0) {
        sum += (a % 10).toInt();
        a /= 10;
    }

    printf("Sum: %"  PRIu64 "\n", sum);
    return 0;
}
