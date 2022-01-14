// Program that funds the sum of all the primes that are truncatable from
// left to right and right to left.
// Yang Xin

#include <stdio.h>
#include <math.h>

int is_prime(long divisor);

int main(void) {
    int sum = 0;
    int current = 10;
    int count = 0;
    while (count < 11) {
        if (is_prime(current) == 1) {
            int left = 0;
            int right = current;
            int prime_check = 5;
            int multiplier = 1;
            while (right > 0 && prime_check == 5) {
                left = left + multiplier * (right % 10);
                if (is_prime(left) == 1 && is_prime(right) == 1) {
                    prime_check = 5;
                } else {
                    prime_check = 0;
                }
                right = right / 10;
                multiplier = multiplier * 10;
            }
            if (prime_check == 5) {
                count ++;
                sum = sum + current;
            }
        }
        current ++;
    }
    printf("%d\n", sum);   
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
