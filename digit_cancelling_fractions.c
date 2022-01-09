// Program that finds the denominator of the product of all of the fractions
// where two digits can cancel out and still form the correct fraction.
// Yang Xin

#include <stdio.h>

int main(void) {
    int denominator_product = 1;
    int numerator_product = 1;
    int num = 1;
    while (num < 10) {
        int denominator = 1;
        while (denominator < num) {
            int numerator = 1;
            while (numerator < denominator) {
                if ((numerator * 10 + num) * denominator == numerator * (num * 10 +denominator)) {
                    denominator_product = denominator_product * denominator;
                    numerator_product = numerator * numerator_product;
                }
                numerator ++;
            }
            denominator ++;
        }
        num ++;
    }
    int factor = 1;
    int gcd = 0;
    while (factor <= denominator_product && factor <= numerator_product) {
        if (denominator_product % factor == 0 && numerator_product % factor == 0) {
            gcd = factor;
        }
        factor ++;
    }
    printf("%d\n", denominator_product / gcd);
}
