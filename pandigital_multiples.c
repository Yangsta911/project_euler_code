// Program that finds the largest 1 to 9 pandigital number that can be
// formed as the concatenated product of an integer with 1 to n 
// where n > 1.
// Yang Xin

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_pandigital(int factor_1, int current);

int main(void) {
    long result = 0;
    long loop_var = 10000;
    while (loop_var > 1000) {
        if (is_pandigital(loop_var * 2, loop_var) == 1) {
            char s1[20];
            char s2[20];
            sprintf(s1, "%ld", loop_var);
            sprintf(s2, "%ld", loop_var * 2);
            strcat(s1, s2);
            result = atoi(s1);
            printf("%ld\n", result);
            break;
        }
        loop_var --;
    }
}   

int is_pandigital(int factor_1, int current) {
    char number[100] = {'a','a','a','a','a','a','a','a','a'};
    sprintf(number, "%d%d", current, factor_1);
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

