// Program that finds how many Lychrel numbers there are below ten-thousand

#include <stdio.h>

int is_palindrome(long long product);
int is_lychrel(int number);
long long reverse_num(int number);

int main(void) {
    int result = 0;
    int current = 10;
    while (current < 10000) {
        if (is_lychrel(current) == 1) {
            result ++;
        }
        current ++;
    }
    printf("%d\n", result);
}

int is_palindrome(long long product) {
    char palindrome_check[1000];
    int length = 0;
    int check_var = 0;
    sprintf(palindrome_check, "%lld", product);
    while (palindrome_check[length] != '\0') {
        length ++;
    }
    int beginning = 0;
	int half = length/2 - 1;
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

int is_lychrel(int number) {
    long long temp = number;
    int loop_var = 0;
    while (loop_var < 50) {
        temp = temp + reverse_num(temp);
        if (is_palindrome(temp) == 1) {
            return 0;
        }
        loop_var ++;
    }
    return 1;
}

long long reverse_num(int number) {
    long long temp = number;
    long long reverse = 0;
    long long remainder;
    while (temp != 0) {
        remainder = temp % 10;
        reverse = reverse * 10 + remainder;
        temp = temp / 10;
    }
    return reverse;
}
