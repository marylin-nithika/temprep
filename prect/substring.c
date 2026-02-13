#include <stdio.h>
#include <string.h>

int main() {
    char str[200], sub[50];
    int count = 0;

    // Input string
    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline

    // Input substring
    printf("Enter the substring to search: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0'; // remove newline

    // Use strstr in a loop to count occurrences
    char *pos = str; // start searching from beginning

    while ((pos = strstr(pos, sub)) != NULL) {
        count++;
        pos++; // move pointer forward by 1 to allow overlapping occurrences
    }

    printf("The substring '%s' occurs %d time(s) in the string.\n", sub, count);

    return 0;
}
