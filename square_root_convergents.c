// In the first one-thousand expansions, how many fractions contain a
// numerator with more digits than the denominator?

#include <stdio.h>
#include <math.h>

int main(void) {
    int result = 0;
    float denominator = 2;
    float numerator = 3;
    int i = 1;
    while (i < 1000) {
        numerator = numerator + 2 * denominator;
        denominator = numerator - denominator;
        if (log10(numerator) > log10(denominator)) {
            result ++;
        }
        i ++;
    }
    printf("%d\n", result);
}
