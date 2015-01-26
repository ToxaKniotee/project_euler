#!/bin/bash

g++ $1 -o a libraries/BigInt/BigIntegerAlgorithms.o libraries/BigInt/BigInteger.o libraries/BigInt/BigIntegerUtils.o libraries/BigInt/BigUnsignedInABase.o libraries/BigInt/BigUnsigned.o
time ./a
rm ./a
