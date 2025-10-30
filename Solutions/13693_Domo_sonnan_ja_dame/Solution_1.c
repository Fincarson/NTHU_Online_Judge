#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 50001

char buff_stk[2 * MAX][30];
int buff_idx, idx;
double stk[MAX];

double prefix()
{
    double op1, op2;
    while (buff_idx--) {
        if (isdigit(buff_stk[buff_idx - 1][0])) {
            stk[idx++] = atof(buff_stk[buff_idx - 1]);
        }
        else {
            op1 = stk[--idx];
            op2 = stk[--idx];
            switch (buff_stk[buff_idx - 1][0]) {
            case '+': stk[idx++] = op1 + op2; break;
            case '-': stk[idx++] = op1 - op2; break;
            case '*': stk[idx++] = op1 * op2; break;
            case '/': stk[idx++] = op1 / op2; break;
            }
        }
    }
    return stk[0];
}

int main()
{
    while (scanf("%s", buff_stk[buff_idx++]) != EOF);
    printf("%.4lf\n", prefix());
}