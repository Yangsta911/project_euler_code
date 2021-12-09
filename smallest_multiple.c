// A program that finds the smallest positive number that is evenly divisible by all of the numbers from 1 to 20
// Yang Xin

#include <stdio.h>

int main(void) {
    int number = 0;
    int division_tracker = 0;
    while (division_tracker != 20) {
        division_tracker = 0;
        number ++;
        int divisor = 1;
        while (divisor <= 20) {
            if (number % divisor == 0) {
                division_tracker ++;
            }
            divisor ++;
        }
    }
    printf("%d\n", number);
}

