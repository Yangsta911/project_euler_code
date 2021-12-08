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
    if (product >= 100000) {
        length = 6;
    } else {
        length = 5;
    }
    int beginning = 0;
    if (length == 6) {
    	length = 5;
        while (beginning <= 2) {
            if (palindrome_check[beginning] == palindrome_check[length]) {
                check_var ++;
            }
            beginning ++;
            length --;
        }
        if (check_var == 3) {
            return 1;
        }
        return 0;
    } else if (length == 5) {
		length = 4;
        while (beginning <=1) {
        if (palindrome_check[beginning] == palindrome_check[length]) {
                check_var ++;
        }
        beginning ++;
        length --;
        }
        if (check_var == 2) {
            return 1;
        }
        return 0;
    }
    return 0;
}
