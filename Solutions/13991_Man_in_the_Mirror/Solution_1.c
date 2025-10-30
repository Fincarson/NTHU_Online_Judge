#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    char input[1000001];
    int q;

    scanf("%d", &q);

    while (q--)
    {
        scanf("%s", input);
        if (isPalindrome(input)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}