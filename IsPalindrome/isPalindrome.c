#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrom(char *text, int left, int right);

bool isPalindrom(char *text, int left, int right) {
    if (left == right) {
        return true;
    }
    if (text[left] != text[right]) {
        return false;
    }
    if (left < right + 1) {
        return isPalindrom(text, left + 1, right - 1);
    }
}

int main()
{
    char text[100];
    printf("Enter your text: ");
    scanf("%s", text, sizeof(text));
    int n = strlen(text);
    if (isPalindrom(text, 0, n - 1)) {
        printf("It is a palindrom.");
    }
    else {
        printf("Not a palindrom!");
    }
}