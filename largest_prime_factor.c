// Program that finds the largest prime factor of the number 60085147543
// Yang Xin

#include <stdio.h>
#include <math.h>
int is_prime(long divisor);

int main(void) {
    long divisor = 1;
    long largest_prime = 1;
    while (divisor < 600851475143) {
        if (600851475143 % divisor == 0) {
            if (is_prime(divisor) == 1) {
                largest_prime = divisor;
            }
        }
        divisor ++;
    }
    printf("%ld", largest_prime);
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
