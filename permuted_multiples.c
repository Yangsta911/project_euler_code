// Finds the smallest positive integer, x, such that 2x, 3x ,4x, 5x and 6x
// contain the same digits.

#include <stdio.h>
#include <math.h>

int permutation_check(int m, int n);

int main(void) {
    int current = 1;
    int loop_var = 0;
    int result = 0;
    while (loop_var == 0) {
        current = current * 10;
        int i = current;
        while (i < (current * 10 /6)) {
            loop_var = 1;
            int j = 2;
            while (j <= 6) {
                if (permutation_check(i, j * i) == 0) {
                    loop_var = 0;
                    break;
                }
                j ++;
            }
            if (loop_var == 1) {
                result = i;
                break;
            }
            i ++;
        }
    }
    printf("%d\n", result);
}

int permutation_check(int m, int n) {
    int array[10] = {0};
    int temp = n;
    while (temp > 0) {
        array[temp % 10] = array[temp % 10] + 1;
        temp = temp / 10;
    }
    temp = m;
    while (temp > 0) {
        array[temp % 10] = array[temp % 10] - 1;
        temp = temp / 10;
    }
    int i = 0;
    while (i < 10) {
        if (array[i] != 0) {
            return 0;
        }
        i ++;
    }
    return 1;
}
