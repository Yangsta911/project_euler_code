// Program that finds the first four consecutive integers to have four 
// distinct prime factors.
// Yang Xin

#include <stdio.h>
#include <math.h>

int is_prime(long divisor);
int number_of_prime_factors(int number);

int main(void) {
    int consecutive = 0;
    int target_consecutive = 4;
    int target_prime_factors = 4;
    int result = 1;
    int consecutive_list[5];
    int list_var = 0;
    while (consecutive < target_consecutive) {
        result ++;
        if (number_of_prime_factors(result) >= target_prime_factors) {
            consecutive ++;
            consecutive_list[list_var] = result;
            list_var ++;
        } else {
            consecutive = 0;
            list_var = 0;
        }
    }
    printf("%d\n", consecutive_list[0]);
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

int number_of_prime_factors(int number) {
    int list_prime[10000];
    int current = 1;
    int list_var = 0;
    while (current < 10000) {
        if (is_prime(current) == 1) {
            list_prime[list_var] = current;
            list_var ++;
        }
        current ++;
    }
    list_var = 0;
    int prime_factor;
    int consecutive = 0;
    int temp = number;
    while (list_var < 10000) {
        if (list_prime[list_var] * list_prime[list_var] > number) {
            return consecutive ++;
        }
        prime_factor = 0;
        while (temp % list_prime[list_var] == 0) {
            prime_factor = 1;
            temp = temp / list_prime[list_var];
        }
        if (prime_factor == 1) {
            consecutive ++;
        }
        if (temp == 1) {
            return consecutive;
        }
        list_var ++;
    }
    return consecutive;
}
