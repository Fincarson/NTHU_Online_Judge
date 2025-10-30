#include <stdio.h>
#include <string.h>

char s[201];
int num1[100];
int num2[100];
int res[101];

signed main() {
    /*
     BEG INPUT
    */
    scanf("%s", s);
    /*
     END INPUT
    */


    /*
     BEG PROCESS INPUT
    */
    int inputLength = strlen(s);
    int mode = 2, idx = 0, longestNumberLength = 0;

    // reverse loop to save digits backward
    for (int i = inputLength - 1; i >= 0; i--) {
        if (s[i] == '+') {
            if (idx > longestNumberLength) {
                longestNumberLength = idx;
            }
            mode = 1; // we met '+', start saving another number
            idx = 0;
            continue;
        }
        if (mode == 1) {
            num1[idx] = s[i] - '0'; // minus '0' so it become a int number
        }
        if (mode == 2) {
            num2[idx] = s[i] - '0'; // minus '0' so it become a int number
        }
        idx++;
    }
    if (idx > longestNumberLength) {
        longestNumberLength = idx;
    }
    /*
     END PROCESS INPUT
    */


    /*
     BEG CALCULATE
    */
    int carry = 0;
    for (int i = 0; i < longestNumberLength; i++) {
        res[i] = (num1[i] + num2[i] + carry) % 10;
        carry = (num1[i] + num2[i] + carry) / 10;
    }
    /*
     END CALCULATE
    */


    /*
     BEG OUTPUT
    */
    // check leading number is ot is not zero
    if (res[longestNumberLength] != 0) {
        printf("%d", res[longestNumberLength]);
    }
    // print each digit reversly
    for (int i = longestNumberLength - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    /*
     END OUTPUT
    */
}