/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <cmath>        /* sqrt */

bool is_prime(int n);
inline int form(int a, int b, int n);

int main(int argc, char const *argv[]) {
    int product, max = 0;
    int a1, b1;
    for (int a = -999; a < 1000; a++) {
        for (int b = -999; b < 1000; b++) {
            int n = 0;
            while (true) {
                if (!form(a, b, n++)) {
                    break;
                }
            }

            if (--n > max) {
                max = n;
                product = a * b;
                a1 = a;
                b1 = b;
            }
        }
    }
    printf("Product: %d, %d, %d, max: %d\n", product, a1, b1, max);
    return 0;
}

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i++) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

inline int form(int a, int b, int n) {
    if (is_prime(n * n + a * n + b)) return true;
    return false;
}
