#include<stdio.h>
#include<ctype.h>

/* INITIALIZATION */
char *str;
size_t buf = 34;
int idx;


/* FUNCTION(S) */
void audrey();


/*=======================================================*/


/* MAIN CODE */
int main(void){
    while(getline(&str, &buf, stdin) != EOF){
        idx = 0;
        audrey();
        printf("\n");
    }
    return 0;
}


void audrey() {
    if (str[idx] == ' ') idx++;
    //When there's spaces, skip it

    //If digit(s) are detected
    if (isdigit(str[idx])) {
        int num = 0;
        while (isdigit(str[idx])) {
            num = num * 10 + str[idx] - '0';
            idx++;
        }
        printf("%d", num);
    }

    //If '+' is detected
    if (str[idx] == '+') {
        idx++; audrey(); //Left node
        printf("+");
        idx++; audrey(); //Right node
    }

    //If '-' is detected
    if (str[idx] == '-') {
        //Left Node
        idx++; audrey();
        printf("-");
        idx++;

        //Right Node
        if (str[idx] == '+' || str[idx] == '-') {
            printf("(");
            audrey();
            printf(")");
        }
        else audrey();
    }

    //If '*' is detected
    if (str[idx] == '*') {
        idx += 2;
        //Left Node
        if (str[idx] == '+' || str[idx] == '-') {
            printf("(");
            audrey();
            printf(")");
        }
        else audrey();

        printf("*");

        //Right Node
        idx++;
        if (str[idx] == '+' || str[idx] == '-') {
            printf("(");
            audrey();
            printf(")");
        }
        else audrey();
    }

    //If '/' is detected
    if (str[idx] == '/') {
        //Left Node
        idx += 2;
        if (str[idx] == '+' || str[idx] == '-') {
            printf("(");
            audrey();
            printf(")");
        }
        else audrey();

        printf("/");

        //Right Node
        idx++;
        if (str[idx] == '+' || str[idx] == '-' || str[idx] == '*' || str[idx] == '/') {
            printf("(");
            audrey();
            printf(")");
        }
        else audrey();
    }
}
