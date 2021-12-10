// Program that finds the largest palindrome made from the product of
// two 3-digit numbers.

#include <stdio.h>

int is_palindrome(int product);

int main(void) {
    int number_1 = 100;
    int largest = 0;
    while (number_1 < 1000) {
        int number_2 = 100;
        while (number_2 < 1000) {
            if (is_palindrome(number_1 * number_2) == 1 && number_1*number_2 > largest) {
                largest = number_1 * number_2;
            }
            number_2 ++;
        }
        number_1 ++;
    }
    printf("%d\n", largest);
}

int is_palindrome(int product) {
    char palindrome_check[7];
    int length = 0;
    int check_var = 0;
    sprintf(palindrome_check, "%d", product);
    while (palindrome_check[length] != '\0') {
        length ++;
    }
    int beginning = 0;
    if (length % 2 == 0) {
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
	} else {
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
}
