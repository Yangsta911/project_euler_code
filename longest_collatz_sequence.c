// Program that finds the longest collatz chain with a starting number
// under 1 million.
// Yang Xin

#include <stdio.h>

int main(void) {
    long current = 1;
    long length = 0;
    long longest_length = 0;
    long longest_num = 0;
    long start;
    while (current < 1000001) {
        start = current;
        length = 0;
        while (current > 1) {
            if (current % 2 == 0) {
                current = current/2;
                length ++;
            } else {
                current = 3*current + 1;
                length ++;
            }
        }
        if (length > longest_length) {
            longest_length = length;
            longest_num = start;
        }
        current = start;
        current ++;
    }
    printf("%ld\n", longest_num);
}

