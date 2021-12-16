// Program that finds the first triangle number to have over 500 divisors.
// Yang Xin

#include <stdio.h>

int main(void) {
    int factor = 0;
    int sum = 0;
    int divisor = 1;
    int loop_num = 1;
    int return_var = 0;
    while (return_var != 1) {
        sum = sum + loop_num;
        loop_num ++;
        factor = 0;
        divisor = 1;
        while (divisor < sum) {
            if (sum % divisor == 0) {
                factor ++;
            }
            if (factor == 500) {
            	return_var = 1;
            }
            divisor ++;
        }
    }
    printf("%d\n", sum);
}

