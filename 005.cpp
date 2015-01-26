/* Copyright 2015 Toxa Kniotee */
#include <stdio.h>

inline bool is_divisible(const int num);

int main(int argc, char const *argv[]) {
    int index = 2520;
    while (!is_divisible((index += 2520)));
    printf("Minimum divisible number: %i\n", index);
    return 0;
}

inline bool is_divisible(const int num) {
    for (int i = 2; i <= 20; i++) {
        if (num % i != 0)
            return false;
    }
    return true;
}
