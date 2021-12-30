// Program that finds the index of the first term in the Fibonacci
// sequence to contain 1000 digits?

#include <stdio.h>
#include <math.h>

int main(void) {
    int index = 2;
    double fib_1 = 1;
    double fib_2 = 1;
    double fib_3 = 0;
    double digits = pow(10, 999); 
    while (fib_2 < digits) {
        fib_3 = fib_1 + fib_2;
        fib_1 = fib_2;
        fib_2 = fib_3;
        index ++;
    }
    printf("%d\n", index);
}

