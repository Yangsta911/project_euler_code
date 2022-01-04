// Program that finds the number of distinct powers a^b for 2<=a<100 and 
// 2<=b<=100.
// Yang Xin

#include <stdio.h>
#include <math.h>

int main(void) {
    int a = 2;
    int b = 2;
    double array[10000] = {0};
    int counter = 0;
    double current;
    while (a <= 100) {
        b = 2;
        while (b <= 100) {
           current = pow(a,b);
           int in_array = 0;
           int array_num = 0;
           while (in_array == 0) {
                in_array = 1;
                if (current != array[array_num] && array_num < counter) {
                    array_num ++;
                    in_array = 0;
                }
           }
           if (array_num == counter) {
                array[counter] = current;
                counter ++;
           }
           b ++;
        }
        a ++;
    }
    printf("%d\n", counter);
}
