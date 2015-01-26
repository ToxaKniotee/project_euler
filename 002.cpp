/* Copyright 2015 ToxaKniotee */
#include <stdio.h>

#define MAX_NUMBER 4000000

int main(int argc, char const *argv[]) {
    int fibonacci_num;
    int prev_numbers[] = {1, 2};
    int sum = 2;
    int save_position = 0;

    /* Vamos creando los números de la secuencia, comprobamos si es par, en caso
     * de serlo lo agregamos a la suma total */
    while ((fibonacci_num = prev_numbers[0] + prev_numbers[1]) < MAX_NUMBER) {
        /* En caos de ser par lo sumamos al total */
        if (fibonacci_num % 2 == 0)
            sum += fibonacci_num;

        /* Lo agregamos a la lista de previos */
        prev_numbers[save_position] = fibonacci_num;
        save_position = 1 - save_position;
    }
    printf("Suma: %i\n", sum);
    return 0;
}
