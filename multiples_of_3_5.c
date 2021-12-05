//A program that finds the sum of all the multiples of 3 or 5 below 1000.
// Yang Xin

#include <stdio.h>

int main(void){
    int current_number = 0;
    int sum = 0;
    while (current_number < 1000) {
        if (current_number % 3 == 0) {
            sum = sum + current_number;
        } else if (current_number % 5 == 0){
            sum = sum + current_number;
        }
        current_number ++;
    }
    printf("%d\n", sum);
}
