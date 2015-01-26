/* Copyright 2015 Toxa Kniotee */
#include <stdio.h>
#include <inttypes.h>   /* uint64_t */

#define NUMBER 1000000

uint64_t values[NUMBER] = {0};

uint64_t getCollatzNumber(uint64_t a);

int main(int argc, char const *argv[]) {
    uint64_t max = 0;
    uint64_t position;

    for (uint64_t i = 0; i < NUMBER; i++) {
        values[i] = 0;
    }

    values[0] = 1;

    for (uint64_t i = 2; i < NUMBER; i++) {
        uint64_t temp;
        if ((temp = getCollatzNumber(i)) > max) {
            max = temp;
            position = i;
        }
    }

    printf("Position: %" PRIu64 "\n", position);
    return 0;
}

uint64_t getCollatzNumber(uint64_t a) {
    if (a - 1 < NUMBER) {
        if (values[a - 1] != 0) return values[a-1];
        values[a - 1] = getCollatzNumber((a % 2 == 0) ? (a / 2) :
            (3 * a + 1)) + 1;
        return values[a - 1];
    } else {
        return getCollatzNumber((a % 2 == 0)?(a / 2):(3 * a + 1)) + 1;
    }
}
