// program that finds the amount of routes through a 20x20 grid to go from
// top left to bottom right corner of the grid.
// Yang Xin

#include <stdio.h>

int main(void) {
    long long grid[21][21];
    int row = 0;
    int col;
    while (row < 21) {
        col = 0;
        while (col < 21) {
            grid[row][col] = 1;
            col ++;
        }
        row ++;
    }
    row = 1;
    col = 1;
    while (row < 21) {
        col = 1;
        while (col < 21) {
            grid[row][col] = grid[row-1][col] + grid[row][col-1];
            col ++;
        }
        row ++;
    }
    printf("%lld\n", grid[20][20]);
}
