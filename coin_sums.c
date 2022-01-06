// Program that finds how many ways 2 dollars can be made using any number
// of coins
// Yang Xin

#include <stdio.h>

int main(void) {
    int final = 200;
    int ways = 0;
    int a = final;
    while (a >= 0) {
        int b = a;
        while (b >= 0) {
            int c = b;
            while (c >=0) {
                int d = c;
                while (d >= 0) {
                    int e = d;
                    while (e >= 0) {
                        int f = e;
                        while (f >= 0) {
                            int g = f;
                            while (g >= 0) {
                                g = g - 2;
                                ways ++;
                            }
                            f = f - 5;
                        }
                        e = e - 10;
                    }
                    d = d - 20;
                }
                c = c - 50;
            }
            b = b -100;
        }
        a = a - 200;
    }   
    printf("%d\n", ways);
}
