// Find the last 10 digits of the series 1^1 + 2^2 + ... + 1000^1000
// Yang Xin

#include <stdio.h>
#include <math.h>

int main(void) {
    long result = 0;
    int current = 1;
    long modulo = 10000000000;
    while (current < 1000) {
        long temp = current;
        int loop_var = 1;
        while (loop_var < current) {
            temp = temp * current;
            temp = temp % modulo;
            loop_var ++;
        }
        result = result + temp;
        result = result % modulo;
        current ++;
    }
    printf("%ld\n", result);
}
