// Program that finds the sum of all products whose product identity
// Can be written as a 1 through 9 pandigital.

#include <stdio.h>

int is_pandigital(int factor_1, int current);

int main(void) {
    int current = 1000;
    int sum = 0;
    while (current < 10000) {
        int factor_1 = 1;
        while (factor_1 * factor_1 < current) {
            if (current % factor_1 == 0 && is_pandigital(factor_1, current) == 1) {
                    sum = sum + factor_1 + current/factor_1 + current;
            }
            factor_1 ++;
        }
        current ++;
    }
    printf("%d\n", sum);
}

int is_pandigital(int factor_1, int current) {
    int factor_2 = current / factor_1;
    char number[100] = {'a','a','a','a','a','a','a','a','a'};
    sprintf(number, "%d%d%d", current, factor_1, factor_2);
    if (number[8] == 'a') {
    	return 0;
    } else {
    	int num = 0;
    	int one_counter = 0;
    	int two_counter = 0;
    	int three_counter = 0;
    	int four_counter = 0;
    	int five_counter = 0;
    	int six_counter = 0;
    	int seven_counter = 0;
    	int eight_counter = 0;
    	int nine_counter = 0;
    	while (num < 9) {
    		if (number[num] == '1') {
    			one_counter ++;
    		} else if (number[num] == '2') {
    			two_counter ++;
    		} else if (number[num] == '3') {
    			three_counter ++;
    		} else if (number[num] == '4') {
    			four_counter ++;
    		} else if (number[num] == '5') {
    			five_counter ++;
    		} else if (number[num] == '6') {
    			six_counter ++;
    		} else if (number[num] == '7') {
    			seven_counter ++;
    		} else if (number[num] == '8') {
    			eight_counter ++;
    		} else if (number[num] == '9') {
    			nine_counter ++;
    		}
    		num ++;
    	}
    	if (one_counter == 1 && two_counter == 1 && three_counter == 1 && four_counter == 1 && five_counter  == 1 && six_counter == 1 && seven_counter == 1 && eight_counter == 1 && nine_counter == 1) {
    	    return 1;
    	} else {
    	    return 0;
    	}
    }
}

