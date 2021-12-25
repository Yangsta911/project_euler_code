// Program that finds the sum of the digits of 100 factorial.
// Yang Xin

#include <stdio.h>

int main(void) {
    int num[400] = {0};
    int factorial = 1;
    int current = 1;
    int carry;
    int temp_power;
    int sum = 0;
    num[0] = 1;
    while (factorial < 100) {
        carry = 0;
        current = 0;
        while (current < 400) {
            temp_power = factorial * num[current] + carry;
            carry = 0;
            if (temp_power > 9) {
                num[current] = temp_power % 10;
                carry = temp_power / 10;
            } else {
                num[current] = temp_power;
            }
            current ++;
        }
        factorial ++;
    }
    current = 0;
    while (current < 400) {
        sum = sum + num[current];
        current ++;
    }
    printf("%d\n", sum);
}
