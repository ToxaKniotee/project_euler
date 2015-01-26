/* Copyright 2015 ToxaKniotee */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, b;
    for (a = 1; a < 1000; a++) {
        for (b = a + 1; b < 1000; b++) {
            if (a * a + b * b == (1000 - a - b) * (1000 - a - b)) {
                printf("Product: %i\n", a * b * (1000 - a - b));
                return 0;
            }
        }
    }
    return 0;
}
