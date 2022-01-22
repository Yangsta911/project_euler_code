// Program that finds all pandigital numbers where the 2nd, 3rd and 4th digits are divisible by 2, 3rd, 4th, 5th are divisible by 3 etc..
// Yang Xin.

// Program that finds the 1 millionth lexicographic permutation of 0 to 9.
// Yang Xin

#include <stdio.h>

int main(void) {
    int counter = 1;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int i;
    int j;
    int temp;
    int divisors[9] = {1,2,3,5,7,11,13,17};
    int result = 0;
    while (counter < 1000000) {
        i = 9;
        j = 9;
        while (i > 0 && array[i-1] >= array[i]) {
            i --;
        }
        while (j > 0 && array[j] <= array[i-1]) {
            j --;
        }
        temp = array[i-1];
        array[i-1] = array[j];
        array[j] = temp;
        j = 9;
        while (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i ++;
            j --;
        }
        int divisible = 1;
        int k = 1;
        while (k < 8) {
            int num = 100 * array[k] + 10 * array[k+1] + array[k+2];
            if (num % divisors[k] != 0) {
                divisible = 0;
                break;
            }
            k ++;
        }
        if (divisible == 1) {
            long num = 0;
            int d = 0;
            while (d < 9) {
                num = 10 * num + array[d];
                d ++;
            }
            result = result + num;
        }
        counter ++;
    }
    printf("%d\n", result);
}

