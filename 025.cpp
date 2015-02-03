/* Copyright 2015 Toxa Kniotee */
#include <stdio.h>
#include "libraries/BigInt/BigIntegerLibrary.hh"

int main(int argc, char const *argv[]) {
    BigInteger previous[2] = {BigInteger(1), BigInteger(1)};
    int number = 2;
    int position = 0;

    while (bigIntegerToString(previous[position]).size() < 1000) {
        position = 1 - position;
        previous[position] = previous[0] + previous[1];
        number++;
    }

    printf("%d\n", number);
    return 0;
}
