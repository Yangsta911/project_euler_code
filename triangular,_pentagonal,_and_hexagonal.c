// Finds the next number after 40755 that is also pentagonal and hexagonal.
// Yang Xin

#include <stdio.h>
#include <math.h>

int is_pentagonal(long number);
int is_triangular(long number);
int is_hexagonal(long number);

int main(void) {
    long current = 40756;
    int loop_var = 1;
    long result = 0;
    while (loop_var == 1) {
        if (is_hexagonal(current) == 1 && is_pentagonal(current) == 1 && is_triangular(current) == 1) {
            result = current;
            loop_var = 0;
        } else {
            current ++;
        }
    }
    printf("%ld\n", result);
}

int is_pentagonal(long number) {
    double pentagonal_test = (sqrt(1 + 24 * number) + 1)/6;
    if (pentagonal_test == (long)pentagonal_test) {
        return 1;
    } else {
        return 0;
    }
}

int is_triangular(long number) {
    double triangular_test = (sqrt(8 * number + 1) - 1) / 2;
    if (triangular_test == (long)triangular_test) {
        return 1;
    } else {
        return 0;
    }
}

int is_hexagonal(long number) {
   double hexagonal_test = (sqrt(8 * number + 1) + 1) / 4;
    if (hexagonal_test == (long)hexagonal_test) {
        return 1;
    } else {
        return 0;
    }
}


