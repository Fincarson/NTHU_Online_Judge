#include <stdio.h>
#include <string.h>

char a[1000];
char b[1000];
char ans[1001]; // Increased size to handle carry
int i, j, diff, x, y;

int main(void)
{
    // Read input string
    scanf("%s", a);

    // Find the '+' symbol and split the strings into `a` and `b`
    for (i = 0; a[i] != '+'; i++);
    a[i] = '\0'; // Terminate first part
    strcpy(b, a + i + 1); // Copy second part to `b`

    // Calculate lengths of `a` and `b`
    int lenA = strlen(a);
    int lenB = strlen(b);

    // Pad the shorter string with zeros at the front
    if (lenA > lenB) {
        diff = lenA - lenB;
        for (x = lenB - 1; x >= 0; x--) {
            b[x + diff] = b[x];
        }
        for (x = 0; x < diff; x++) {
            b[x] = '0';
        }
        lenB = lenA;
    }
    else if (lenB > lenA) {
        diff = lenB - lenA;
        for (x = lenA - 1; x >= 0; x--) {
            a[x + diff] = a[x];
        }
        for (x = 0; x < diff; x++) {
            a[x] = '0';
        }
        lenA = lenB;
    }

    // Perform the addition
    int carry = 0;
    for (i = lenA - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        ans[i + 1] = (sum % 10) + '0'; // Store the current digit
        carry = sum / 10;             // Calculate carry
    }

    // Handle any remaining carry
    if (carry > 0) {
        ans[0] = carry + '0';
        ans[lenA + 1] = '\0'; // Null-terminate the result
        printf("%s\n", ans);
    }
    else {
        printf("%s\n", ans + 1); // Skip leading zero
    }

    return 0;
}