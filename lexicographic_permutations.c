// Program that finds the 1 millionth lexicographic permutation of 0 to 9.
// Yang Xin

#include <stdio.h>

int main(void) {
    int counter = 1;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int i;
    int j;
    int temp;
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
        counter ++;
    }
    i = 0;
    while (i <= 9) {
        printf("%d", array[i]);
        i ++;
    }
    printf("\n");
}
