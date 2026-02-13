#include <stdio.h>
#include <ctype.h>   // for toupper()
#include <string.h>  // for strlen()

// Function to count words in a string
int countWords(char str[]) {
    int count = 0;
    int i = 0;
    int inWord = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && !inWord) {
            count++;
            inWord = 1; // inside a word
        } else if (str[i] == ' ') {
            inWord = 0; // left a word
        }
        i++;
    }
    return count;
}

// Function to convert lowercase letters to uppercase
void convertToUppercase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        // Skip non-alphanumeric characters
        while (i < j && !isalnum(str[i])) i++;
        while (i < j && !isalnum(str[j])) j--;

        if (toupper(str[i]) != toupper(str[j])) {
            return 0; // not palindrome
        }
        i++;
        j--;
    }
    return 1; // palindrome
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read a line with spaces
    str[strcspn(str, "\n")] = '\0'; // remove trailing newline

    // a) Count words
    int words = countWords(str);
    printf("Number of words: %d\n", words);

    // b) Convert to uppercase
    convertToUppercase(str);
    printf("Uppercase string: %s\n", str);

    // c) Check palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
