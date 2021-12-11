// Program that finds the 10001st prime
// Yang Xin

#include <stdio.h>
#include <math.h>

int is_prime(long divisor);

int main(void) {
    long current = 0;
    int counter = 0;
    long largest_prime = 0;
    while (counter <= 10001) {
        if (is_prime(current) == 1) {
            largest_prime = current;
            counter ++;
        }
        current ++; 
    }
    printf("%ld\n", largest_prime);

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
