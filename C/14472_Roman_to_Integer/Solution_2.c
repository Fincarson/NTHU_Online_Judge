#include <stdio.h>
#include <string.h>

void solve() {
    char str[20];
    scanf("%s", str);

    int n = strlen(str);
    int value = 0;
    int i = 0;

    while (i < n) {
        if (str[i] == 'I') {
            if (i + 1 < n && str[i + 1] == 'V') {
                value += 4;
                i++;
            } else if (i + 1 < n && str[i + 1] == 'X') {
                value += 9;
                i++;
            } else {
                value += 1;
            }
        } else if (str[i] == 'V') {
            value += 5;
        } else if (str[i] == 'X') {
            if (i + 1 < n && str[i + 1] == 'L') {
                value += 40;
                i++;
            } else if (i + 1 < n && str[i + 1] == 'C') {
                value += 90;
                i++;
            } else {
                value += 10;
            }
        } else if (str[i] == 'L') {
            value += 50;
        } else if (str[i] == 'C') {
            if (i + 1 < n && str[i + 1] == 'D') {
                value += 400;
                i++;
            } else if (i + 1 < n && str[i + 1] == 'M') {
                value += 900;
                i++;
            } else {
                value += 100;
            }
        } else if (str[i] == 'D') {
            value += 500;
        } else if (str[i] == 'M') {
            value += 1000;
        }

        i++;
    }

    printf("%d\n", value);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}