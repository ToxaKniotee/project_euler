/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <string>

using std::string;

string numberToString(int number);

int main(int argc, char const *argv[]) {
    unsigned sum = 0;
    for (int i = 1; i<= 1000; i++) {
        sum += numberToString(i).length();
    }
    printf("sum: %u\n", sum);
    return 0;
}

string numberToString(int number) {
    if (number == 1000) return "onethousand";
    string numbers[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    };

    string preffix10[] = {
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
    };

    string result = "";


    if (number > 99) {
        result += numbers[number / 100 - 1] + "hundred";
        number %= 100;
        if (number != 0) {
            result += "and";
        }
    }

    if (number > 19) {
        result += preffix10[number / 10 - 2];
        number %= 10;
    }

    if (number - 1 != -1) {
        result += numbers[number - 1];
    }

    return result;
}
