// Program that finds the number of ciruclar primes below one million.
// Yang Xin

#include <stdio.h>
#include <math.h>

int is_prime(long number);
int check_circular(long value);

int main(void) {
    long current = 1;
    int counter = 0;
    while (current < 1000000000) {
        if (check_circular(current) == 1) {
            counter ++;
        }
        current ++;
    }
}


int is_prime(long number) {
    if (number == 1) {
        return 0;
    }
    long i = 2;
    long sqrt_val = sqrt((double)(number));
    while (i < sqrt_val) {
        if (number % i == 0) {
            return 0;
        }
        i ++;
    }
    return 1;

}

int check_circular(long value) {
    int count = 0;
    int temp = value;
    while (temp) {
        count ++;
        temp = temp / 10;
    }
    int num = value;
    while (is_prime(num)) {
        int rem = num % 10;
        int div = num / 10;
        num = (pow(10, count - 1)) * rem + div;
        if (num == value ) {
            return 1;
        }
    }
    return 0;
}

