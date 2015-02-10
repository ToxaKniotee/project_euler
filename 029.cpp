/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include "libraries/OrderList/OrderList.cpp"
#include "libraries/BigInt/BigIntegerLibrary.hh"

int main(int argc, char const *argv[]) {
    OrderList<BigInteger> list;
    for (int a = 2; a <= 100; a++) {
        BigInteger temp(a);            
        for (int b = 2; b <= 100; b++) {
            temp *= a;
            list.add(temp);
        }
    }
    printf("Tamaño: %d\n", list.size());
    return 0;
}
