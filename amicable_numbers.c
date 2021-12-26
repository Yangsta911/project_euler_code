// Program that finds the sum of the proper divisors of n.
// Yang Xin

#include <stdio.h>

int main(void) {
    int tempsum_1 = 0;
    int tempsum_2 = 0;
    int array[5] = {0};
    int current = 2;
    int array_num = 0;
    int skip = 0;
    int sum = 0;
    while (current < 10000) {
        int i = 1;
        tempsum_1 = 0;
        tempsum_2 = 0;
        skip = 0;
        while (i < current) {
            if (current % i == 0) {
                tempsum_1 = tempsum_1 + i;
            }
            i ++;
        }
        if (tempsum_1 != current) {
            int j = 1;
            while (j < tempsum_1) {
                if (tempsum_1 % j == 0) {
                    tempsum_2 = tempsum_2 + j;
                }
                j ++;
            }

			if (tempsum_2 == current) {
				int k = 0;
				while (k < array_num) {
					if (current == array[k] || tempsum_1 == array[k]) {
						skip = 1;
					}
					k ++;
				}
				if (skip == 0) {
					sum = sum + current + tempsum_1;
					array[array_num] = tempsum_1;
					array_num ++;
				}
			}
        }
        current ++;
    }
    printf("%d\n", sum);
}

