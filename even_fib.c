// Program that finds the sum of even-valued terms in the Fibonnaci sequence
// that do not exceed four million.
// Yang Xin

#include <stdio.h>

int main(void) {
    int a = 1;
    int b = 2;
    int c = 0;
    int sum = 1;
    while ((a+b) <= 4000000) {
        if (b % 2 == 0){
            sum = sum + b;
        }
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d\n", sum);
    
}
