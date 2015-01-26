/* Copyright 2015 ToxaKniotee */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int sum = 0;
    for (int i = 2; i < 1000; i++) {
        if (i % 5 == 0 || i % 3 == 0) {
            sum += i;
        }
    }
    printf("Suma: %i\n", sum);
    return 0;
}
