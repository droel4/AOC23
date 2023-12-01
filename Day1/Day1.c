#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>

#define LINE_LENGTH 100

int findNum(char line[LINE_LENGTH]);

int main(int argc, char** argv) {
    // Open a file in read mode
    FILE* in_fptr = fopen("input.txt", "r");
    int total = 0;
    char line[LINE_LENGTH];

    // Read the content and print it
    while(fgets(line, LINE_LENGTH, in_fptr)) {
        int firstDigit = 0;
        int lastDigit = 0;

        char findingChar[100] = "";

        for (int i = 0; i < strlen(line); i++) {
            char c = line[i];
            findingChar[i] = c;

            if (isdigit(c)) {
                firstDigit = c - '0';
                break;
            }
            firstDigit = findNum(findingChar);
            if (firstDigit != 0) {
                break;
            }
        }

        char findingCharBack[100] = "                                                                                                   ";

        for (int i = strlen(line) - 1; i > -1; i--) {
            char c = line[i];
            findingCharBack[i] = c;
            if (isdigit(c)) {
                lastDigit = c - '0';
                break;
            }
            lastDigit = findNum(findingCharBack);
            if (lastDigit != 0) {
                break;
            }
        }

        printf("%i\n", firstDigit * 10 + lastDigit);
        total += firstDigit * 10 + lastDigit;
    }
    printf("%i\n", total);

    // Close the file
    fclose(in_fptr);

    return 0;
}

int findNum(char line[LINE_LENGTH]) {
    if (strstr(line, "one") != NULL) {
        return 1;
    }
    if (strstr(line, "two") != NULL) {
        return 2;
    }
    if (strstr(line, "three") != NULL) {
        return 3;
    }
    if (strstr(line, "four") != NULL) {
        return 4;
    }
    if (strstr(line, "five") != NULL) {
        return 5;
    }
    if (strstr(line, "six") != NULL) {
        return 6;
    }
    if (strstr(line, "seven") != NULL) {
        return 7;
    }
    if (strstr(line, "eight") != NULL) {
        return 8;
    }
    if (strstr(line, "nine") != NULL) {
        return 9;
    }
    return 0;
}

