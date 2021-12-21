// Program that finds the sum of the digits of the number 2^1000
// Yang Xin

#include <stdio.h>

int main(void) {
    int num[400] = {0};
    int power = 0;
    int current = 0;
    int carry;
    int temp_power;
    int sum = 0;
    num[0] = 1;
    while (power < 1000) {
        carry = 0;
        current = 0;
        while (current < 400) {
            temp_power = 2 * num[current] + carry;
            carry = 0;
            if (temp_power > 9) {
                num[current] = temp_power % 10;
                carry = temp_power / 10;
            } else {
                num[current] = temp_power;
            }
            current ++;
        }
        power ++;
    }
    current = 0;
    while (current < 400) {
        sum = sum + num[current];
        current ++;
    }
    printf("%d\n", sum);
}

