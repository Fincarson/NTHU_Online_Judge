#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char* equation;
size_t buf = 0;

int idx;
int cidx;

int getVal(char ch) {
    if (ch == '+') return 1;
    else if (ch == '-') return 2;
    else if (ch == '*') return 3;
    return 0;
}

int checkPriority() {
    char ch = equation[cidx++];

    if (ch == ' ') return checkPriority();

    if (isdigit(ch)) {
        while (isdigit(ch)) {
            ch = equation[cidx++];
        }
        cidx--;
        return 10;
    }

    int v1 = checkPriority();
    int v2 = checkPriority();

    return getVal(ch);

    return 0;
}

void printEquation() {
    char ch = equation[idx++];

    if (ch == ' ') return printEquation();

    if (isdigit(ch)) {
        int num = 0;
        while (isdigit(ch)) {
            num = num * 10 + ch - '0';
            ch = equation[idx++];
        }
        idx--;
        printf("%d", num);
        return;
    }

    /* Print equation with parentheses */
    cidx = idx;
    int op = getVal(ch);
    int v1 = checkPriority();
    int v2 = checkPriority();

    if (op > v1 && ch != '-') printf("(");
    printEquation();
    if (op > v1 && ch != '-') printf(")");

    switch (ch) {
    case '+': printf("+"); break;
    case '-': printf("-"); break;
    case '*': printf("*"); break;
    case '/': printf("/"); break;
    }

    if (op > v2 || (op == v2 && ch == '-')) printf("(");
    printEquation();
    if (op > v2 || (op == v2 && ch == '-')) printf(")");
}

int main() {
    while (getline(&equation, &buf, stdin) != -1) {
        idx = 0;
        printEquation();
        printf("\n");
    }
}
