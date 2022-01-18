// Program that finds the nth digit of champernowne's constant
// Yang Xin

#include <stdio.h>

int main(void) {
    char constant[1000002] = {'a'};
    int current = 1;
    int product;
    while (current <= 1000000) {
    	int array_var = 0;
        while(constant[array_var] != 'a') {
        	array_var ++;
        }
        int temp = current;
        int temp_1 = current;
        int length = 0;
        while (temp_1 != 0) {
        	temp_1 = temp_1 / 10;
        	length ++;
        }
        while (length != 0) {
			array_var ++;
			length --;
        }
        array_var --;
        int end_pos = array_var;
        while (temp != 0) {
        	constant[array_var] = temp % 10;
        	array_var --;
        	temp = temp / 10;
        }
        constant[end_pos + 1] = 'a';
        current ++;
    }
    product = (constant[0] - 48) * (constant[9] - 48) * (constant[99] - 48) * (constant[999] - 48) * (constant[9999] - 48) * (constant[99999] - 48) * (constant[999999] - 48);
    printf("%d\n", product);
}
