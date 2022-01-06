// Program that finds the sum of all the numbers that can be written
// as the sum of fifth powers of their digits.

#include <stdio.h>
#include <math.h>

int main(void) {
    int current = 2;
    int total_sum = 0;
    while (current < 10000000) {
        int number = current;
        int temp_sum = 0;
        while (number > 0) {
            int digit = number % 10;
            number = number / 10;
            int power = pow(digit, 5);
            temp_sum = temp_sum + power;
        }
        if (temp_sum == current) {
                total_sum = total_sum + current;
        }
        current ++;
    }
    printf ("%d\n", total_sum);
}
