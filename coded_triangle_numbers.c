// Program that converts words to the sum of the alphabetical position
// of each letter and finds the number of triangular numbers.
// Yang Xin

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    FILE *fp = fopen("p042_words.txt", "r");
    char current;
    char temp[15];
    char names[5200][15];
    int current_name = 0;
    int character = 0;
    int result = 0;
    while ((current = fgetc(fp)) != EOF) {
        if (current == ',') {
            names[current_name][character] = '\0';
            character = 0;
            current_name ++;
        } else if (current != '"') {
            names[current_name][character] = current;
            character ++;
        }
    }
    names[current_name][character] = '\0';
    fclose(fp);
    int sorted = 1;
    while (sorted == 1) {
        sorted = 0;
        int current_pos = 0;
        while (current_pos < current_name) {
            if (strcmp(names[current_pos], names[current_pos+1]) > 0) {
                strcpy(temp, names[current_pos]);
                strcpy(names[current_pos], names[current_pos+1]);
                strcpy(names[current_pos+1], temp);
                sorted = 1;
            }
            current_pos ++;
        } 
    }
    int current_pos = 0;
    while (current_pos < current_name) {
        int current_char = 0;
        int temp_sum = 0;
        while (current_char < 15) {
            if (names[current_pos][current_char] != '\0') {
                temp_sum = temp_sum + names[current_pos][current_char] - 64;
            } else {
                break;
            }
            current_char ++;
        }
        double wordsum = (sqrt(1+8*temp_sum)-1)/2;
        if (wordsum == ((int)wordsum)) {
            result ++;
        }
        current_pos ++;
    }
    printf("%d\n", result);
}
