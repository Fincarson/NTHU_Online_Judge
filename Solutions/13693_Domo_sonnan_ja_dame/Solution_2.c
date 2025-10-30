#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double prefix() {
    char c;
    double op1, op2;
    scanf(" %c", &c);
    if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%lf", &op1);
        return op1;
    }
    else {
        op1 = prefix();
        op2 = prefix();
        switch (c) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        }
    }
}

int main()
{
    printf("%.4lf\n", prefix());
}