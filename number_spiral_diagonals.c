// Program that finds the sum of the numbers on the diagonals of a 1001
// by 1001 spiral starting from number 1.
// Yang Xin

#include <stdio.h>

int main(void) {
    int current = 1;
    int loop_var = 2;
    int counter = 0;
    int sum = 0;
    while (loop_var <= 1001) {
        counter = 0;
        while (counter < 4) {
            sum = sum + current;
            current = current + loop_var;
            counter ++; 
        }
        loop_var = loop_var + 2;
    }
    printf("%d\n", sum);
}
