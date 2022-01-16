// Program that finds the maximum number of solutions for a perimeter
// of a right angle triangle.
// Yang Xin

#include <stdio.h>

int main(void) {
    int result = 0;
    int perimeter = 2;
    int final_number_of_solutions = 0;
    while (perimeter < 1000) {
        int number_of_solutions = 0;
        int side = 2;
        while (side < (perimeter / 3) ) {
            if (perimeter*(perimeter-2*side) % (2*(perimeter-side)) == 0) {
                number_of_solutions ++;
            }
            if (number_of_solutions >= final_number_of_solutions) {
                final_number_of_solutions = number_of_solutions;
                result = perimeter;
            }
            side ++;
        }
        perimeter ++;
    }
    printf("%d\n", result);
}
