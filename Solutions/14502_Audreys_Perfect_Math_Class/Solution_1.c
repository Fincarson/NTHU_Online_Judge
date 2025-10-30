#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *str = NULL;
size_t buf = 0;
int idx;

void audrey(){
    if(str[idx] == ' ')idx++;
    
    if(isdigit(str[idx])){
        int num = 0;
        while(isdigit(str[idx])){
            num = num*10 + str[idx] - '0';
            idx++;
        }
        printf("%d", num);
        return;
    }
    
    if(str[idx] == '+'){
        idx++;
        audrey();
        printf("+");
        idx++;
        audrey();
    }
    
    if(str[idx] == '-'){
        idx++;
        audrey();
        printf("-");
        idx++;
        if(str[idx] == '-' || str[idx] == '+'){
            printf("(");
            audrey();
            printf(")");
        }else{
            audrey();
        }
    }
    
    if(str[idx] == '*'){
        idx+=2;
        if(str[idx] == '-' || str[idx] == '+'){
            printf("(");
            audrey();
            printf(")");
        }else{
            audrey();
        }
        printf("*");
        idx++;
        if(str[idx] == '-' || str[idx] == '+'){
            printf("(");
            audrey();
            printf(")");
        }else{
            audrey();
        }
    }
}

int main(void){
    while(getline(&str, &buf, stdin) !=  EOF){
        idx = 0;
        audrey();
        printf("\n");
    }
}