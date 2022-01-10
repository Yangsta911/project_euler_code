// Find the sum of all numbers which are equal to the sum of the factorial
// of their digits.
// Yang Xin

#include <stdio.h>

int factorial(int number);

int main(void) {
    int sum = 0;
    int current = 10;
    while (current < 9999999) {
        int number = current;
        int factorial_sum = 0;
        while (number > 0) {
            int digit = number % 10;
            number = number / 10;
            factorial_sum = factorial_sum + factorial(digit);
        }
        if (factorial_sum == current) {
            sum = sum + current;
        }
        current ++;
    }
    printf("%d\n", sum);
}

int factorial(int number) {
	if (number == 0) {
		return 1;
	}
    int factorial = number;
    int multiplier = 1;
    while (multiplier < number) {
        factorial = factorial * multiplier;
        multiplier ++;
    }
    return factorial;
}
