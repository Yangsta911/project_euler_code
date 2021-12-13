// A program that finds the pythagorean triplet which adds up to 1000
// Yang Xin

#include <stdio.h>

int main(void) {
    int a = 1;
    int b = 2;
    int c = 3;
    int sum = 1000;
    while (a < 1000) {
		b = 2;
        while (b < 1000) {
            c = sum - a - b;
            if (a*a + b*b == c*c) {
                printf("%d\n", a*b*c);
                return 0;
            }
            b ++;
        }
        a ++;
    }
}
