// Program that finds the sum of all numbers, less than one million, which
// are palindromic in base 10 and base 2.
// Yang Xin

#include <stdio.h>

int is_palindrome(double product);

int main(void) {
    long long current = 1;
    long long base_10;
    double base_2 = 0;
    long long temp;
    long long sum = 0;
    while (current < 1000000) {
    	base_2 = 0;
        base_10 = current;
        temp = current;
        double multiplier = 1;
        while (temp !=0) {
            base_2 = base_2 + temp % 2 * multiplier;
            temp = temp / 2;
            multiplier = multiplier * 10;
        }
        if (is_palindrome(base_10) == 1 && is_palindrome(base_2) == 1) {
            sum = sum + base_10;
        }
        current = current + 2;
    }
    printf("%lld\n", sum);
}

int is_palindrome(double product) {
    char palindrome_check[1000];
    long long length = 0;
    long long check_var = 0;
    sprintf(palindrome_check, "%f", product);
    while (palindrome_check[length] != '.') {
        length ++;
    }
    long long beginning = 0;
	long long half = length/2 - 1;
	length --;
	while (beginning <= half) {
	    if (palindrome_check[beginning] == palindrome_check[length]) {
	        check_var ++;
	    }
	    length --;
	    beginning ++;
	}
	if (check_var == half + 1) {
	    return 1;
	}
    	return 0;
}
