#include <stdio.h>

int main() {
    int counter_1 = 0, counter_2 = 0, false_1 = 0, false_2 = 0, length = 0;
    char c, temp;
    char banana[6] = { 'B', 'A', 'N', 'A', 'N', 'A' };
    while (scanf("%c", &c)) {
        if (counter_1 == 6 || counter_2 == 5) break;
        if (c == '/') {
            if (length != 0) {
                length--;
                if (counter_1 != 0 && false_1 == 0) counter_1--;
                else if (false_1 != 0) false_1--;
            }
        }
        else if (c == '0') break;
        else {
            length++;
            if (banana[counter_1] != c || false_1 != 0) false_1++;
            if (banana[counter_1] == c && false_1 == 0) counter_1++;
        }
        temp = c;
    }
    if (counter_1 == 6) printf("Potassium!\n");
    else printf("No potassium.\n");
    return 0;
}