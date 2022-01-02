// Program that finds the product of the coefficients of the quadratic
// equation n^2 + an + b that produces the maximum number of primes for
// consequtive values of n, starting with n = 0.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int is_prime(long divisor);

int main(void) {
    int a;
    int a_max = 0;
    int b;
    int b_max = 0;
    long n = 0;
    long n_max = 0;
    a = -1000;
    while (a <= 1000) {
        b = -1000;
        while (b <= 1000) {
             n = 0;
            while (is_prime(labs(n*n+a*n+b)) == 1) {
                n ++;
            }
            if (n > n_max) {
                a_max = a;
                b_max = b;
                n_max = n;
            }
            b ++;
        }
        a ++;
    }
    printf("%d, %d\n", a_max, b_max);
}


int is_prime(long divisor) {
    if (divisor == 1) {
        return 0;
    }
    long i = 2;
    long sqrt_val = sqrt((double)(divisor));
    while (i < sqrt_val) {
        if (divisor % i == 0) {
            return 0;
        }
        i ++;
    }
    return 1;

}
