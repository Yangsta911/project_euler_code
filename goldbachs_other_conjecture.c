// Program that finds the smallest odd  composite that cannot be written
// as the sum of a prime and twice a square.
// Yang Xin

#include <stdio.h>
#include <math.h>

int twice_squre(long number);
int is_prime(long divisor);

int main(void) {
    int list_prime[10000];
    int result = 1;
    int loop_var = 1;
    int current = 1;
    int list_var = 0;
    while (current < 10000) {
        if (is_prime(current) == 1) {
            list_prime[list_var] = current;
            list_var ++;
        }
        current ++;
    }
    while  (loop_var == 1) {
        result = result + 2;
        int prime = 0;
        loop_var = 0;
        while (result >= list_prime[prime]) {
            if (twice_squre(result - list_prime[prime]) == 1) {
                loop_var = 1;
                break;
            }
            prime ++;
        }
    }
    printf("%d\n", result);
}

int is_prime(long divisor) {
    if (divisor == 1) {
        return 0;
    }
    long i = 2;
    long sqrt_val = sqrt((double)(divisor));
    while (i <= sqrt_val) {
        if (divisor % i == 0) {
            return 0;
        }
        i ++;
    }
    return 1;

}

int twice_squre(long number) {
    double squared_test = sqrt(number/2);
    if (squared_test == (int)squared_test) {
        return 1;
    } else {
        return 0;
    }
}
