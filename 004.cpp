/* Copyright 2015 ToxaKniotee */
#include <stdio.h>

bool is_palindrome(const int num);

int main(int argc, char const *argv[]) {
    int max_palindrome = 0;
    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > 99; j--) {
            if (is_palindrome(i * j)) {
                if (i * j > max_palindrome) {
                    max_palindrome = i * j;
                }
            }
        }
    }

    printf("Largest palindrome: %i\n", max_palindrome);
    return 0;
}

bool is_palindrome(const int num) {
    int reverse_num = 0;
    int temp_num = num;

    while (temp_num != 0) {
        reverse_num = reverse_num * 10 + temp_num % 10;
        temp_num /= 10;
    }

    if (reverse_num == num)
        return true;
    return false;
}
