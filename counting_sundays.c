// Program that finds how many Sundays fell on the first
// of the month during the twentieth century.

#include <stdio.h>

int main(void) {
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int num_sundays = 0;
    int year = 1900;
    int day = 1;
    int month = 1;
    while (month <= 12) {
        day = day + days[month - 1] % 7;
        while (day > 7) {
            day = day % 7;
        }
        month ++;
    }
    year = 1901;
    while (year <= 2000) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0)) {
            days[1] = 29;
        } else {
            days[1] = 28;
        }
        month = 1;
        while (month <= 12) {
            day = day + days[month - 1] % 7;
            while (day > 7) {
                day = day % 7;
            }
            if (day == 7) {
                num_sundays ++;
            }
            month ++;
        }
        year ++;
    }
    printf("%d\n", num_sundays);
}

