// Program that reads names from a file sorts into alphabetical order
// then finds the alphabetical value for each name, and multiplies this
// value by its alphabetical position in the list to obtain a name score.

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("p022_names.txt", "r");
    char current;
    char temp[12];
    char names[5200][12];
    int current_name = 0;
    int character = 0;
    int sum = 0;
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
        while (current_char < 12) {
            if (names[current_pos][current_char] != '\0') {
                temp_sum = temp_sum + names[current_pos][current_char] - 64;
            } else {
                break;
            }
            current_char ++;
        }
        sum = sum + temp_sum * (current_pos + 1);
        current_pos ++;
    }
    printf("%d\n", sum);
}
