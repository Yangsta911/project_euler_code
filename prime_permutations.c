// Find the 4 digit increasing secrence of prime numbers that are 
// permutations of each other.
// Yang Xin

#include <stdio.h>
#include <math.h>

int permutation_check(int array, int var);
int is_prime(long divisor);

int main(void) {
    long list_prime[10000];
    int list_var = 0;
    int current = 1000;
    int num_of_primes = 0;
    while (current < 10000) {
        if (is_prime(current) == 1) {
            list_prime[list_var] = current;
            list_var ++;
            num_of_primes ++;
        }
        current ++;
    }
    long result = 0;
    int i = 0;
    while (i < num_of_primes) {
        int j = i + 1;
        while (j < num_of_primes) {
            int k = list_prime[j] + (list_prime[j] - list_prime[i]);
            if (k < 10000 && is_prime(k) == 1) {
                if (permutation_check(list_prime[i], list_prime[j]) == 1 && permutation_check(list_prime[i], k) == 1) {
                    result = k + list_prime[j] * 10000 + list_prime[i] * 100000000;
                    break;
                }
            }
            j ++;
            if (result > 0) {
                break;
            }
        }   
        i ++;
    }
    printf("%ld\n", result);
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

int permutation_check(int num, int var) {
    int array[10] = {0};
    int temp = var;
    while (temp > 0) {
        array[temp % 10] = array[temp % 10] + 1;
        temp = temp / 10;
    }
    temp = num;
    while (temp > 0) {
        array[temp % 10] = array[temp % 10] - 1;
        temp = temp / 10;
    }
    int i = 0;
    while (i < 10) {
        if (array[i] != 0) {
            return 0;
        }
        i ++;
    }
    return 1;
}
