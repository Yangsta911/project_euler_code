// Program that finds how many not necessarily distinct values of n comb r
// for 1 <=n <= 100 are greater than one-million.

#include <stdio.h>

float factorial(int number);

int main(void) {
    int result = 0;
    int current = 1;
    while (current <= 100) {
        int value = 0;
        while (value <= current) {
            if (factorial(current) / (factorial(value) * factorial(current - value)) >= 1000000) {
                result ++;
            }
            value ++;
        }
        current ++;
    }
    printf("%d\n", result);
}

float factorial(int number) {
	if (number == 0) {
		return 1;
	}
    float factorial = number;
    float multiplier = 2;
    while (multiplier < number) {
        factorial = factorial * multiplier;
        multiplier ++;
    }
    return factorial;
}
