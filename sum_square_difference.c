// A program that finds the difference between the sums of the
// squares of the first ten natural numbers and the square of the 
// sum of the fist ten natural numbers
// Yang Xin

#include <stdio.h>

int main(void) {
    int sum_squares = 0;
    int square_sum = 0;
    int current = 1;
    int difference = 0;
    while (current <= 100) {
        sum_squares = sum_squares + current * current;
        square_sum = square_sum + current;
        current ++;
    }
    square_sum = square_sum * square_sum;
    difference = square_sum - sum_squares;
    printf("%d\n", difference);
}
