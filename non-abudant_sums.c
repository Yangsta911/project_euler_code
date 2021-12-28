// Program that finds the sum of all positive integers which are not the sum
// of two abundant numbers.

#include <stdio.h>

int main(void) {
    int abundant_current = 11;
    int array[28123];
    int current = 0;
    while (abundant_current <= 28123) {
        int temp_sum = 0;
        int divisor = 1;
        while (divisor < abundant_current) {
            if (abundant_current % divisor == 0) {
                temp_sum = temp_sum + divisor;
            }
            divisor ++;
        }
        if (temp_sum > abundant_current) {
            array[current] = abundant_current;
            current ++;
        }
        abundant_current ++;
    }
    int i = 0;
    int new_array[28124] = {0};
    while (i < current) {
    	int j = i;
    	while (j < current){
    		if ((array[i] + array[j]) <= 28123) {
    			new_array[array[i] + array[j]] = 1;
    		} else {
    			break;
    		}
    		j ++;
		}
    	i ++;
	}
    current = 0;
    int total_sum = 0;
    while (current < 28123) {
        if (new_array[current] == 0) {
            total_sum = total_sum + current;
        }
        current ++;
    }
    printf("%d\n", total_sum);
}
