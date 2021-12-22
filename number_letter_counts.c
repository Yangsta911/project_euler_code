// Program that finds how many letters are needed to write all the numbers
// from 1 to 1000.
// Yang Xin

#include <stdio.h>
#include <string.h>

int main(void) {
    char strings[30][10] = {
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
    "twenty",
    "thirty",
    "fourty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
    "hundred",
    "thousand",
    ""
    };
    int current = 1;
    int sum = 0;
    int tens;
    int digit;
    int hundred;
    int temp;
    int thousand;
    while (current <= 1000) {
        if (current > 19 && current < 100) {
            digit = current % 10;
            tens = current / 10;
            if (digit == 0) {
                digit = 30;
            }
            sum = sum + strlen(strings[digit - 1]) + strlen(strings[tens + 17]);
        } else if (current > 99 && current < 1000) {
            digit = current % 10;
            temp = current / 10;
            tens = temp % 10;
            hundred = temp / 10;
            if (tens == 0) {
                tens = 12;
            }
            if (digit == 0) {
                digit = 30;
            }
            sum = sum + strlen(strings[digit - 1]) + strlen(strings[tens + 17]) + strlen(strings[hundred - 1]) + strlen(strings[27]) + 3;
        } else if (current >= 1000) {
            digit = current % 10;
            temp = current / 10;
            tens = temp % 10;
            temp = current / 10;
            hundred = current % 10;
            thousand = temp / 10;
            if (tens == 0) {
                tens = 12;
            }
            if (digit == 0) {
                digit = 30;
            }
            if (hundred == 0) {
                hundred = 30;
            }
            sum = sum + strlen(strings[digit - 1]) + strlen(strings[tens + 17]) + strlen(strings[hundred - 1]) + strlen(strings[27]) + strlen(strings[thousand - 1]) + strlen(strings[28]) + 3;

        } else {
            digit = current;
            sum = strlen(strings[digit - 1]) + sum;
        }
        current  ++;
    }
    printf("%d\n", sum);
}
