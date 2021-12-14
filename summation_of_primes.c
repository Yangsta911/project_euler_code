// program that finds the sum of all primes below two million.
// Yang Xin.

#include <stdio.h>
#include <math.h>

int is_prime(long divisor);

int main(void) {
    long current = 0;
    long loop_var = 0;
    long sum = 0;
    while (loop_var <  2000000) {
        if (is_prime(current) == 1) {
            sum = sum + current;
            loop_var ++;
        }
        current ++;
    }   
    printf("%ld\n", sum);
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
