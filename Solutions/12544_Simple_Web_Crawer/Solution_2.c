#include<stdio.h>
#include<stdlib.h>

/*INITIALIZATION*/
char input[10001];
//To store the input

char title[1001];
//To store the title

int countLink;
//To count how many link(s)

int x = 0;
//As index for title[]



//Main Code
int main(void){
    while(fgets(input, sizeof(input), stdin) != NULL){
        int i = 0;
        while(input[i] != '\0'){
            while(input[i] != '<' && input[i] != '\0')i++;
            if(input[i] == '\0')break;

            if(input[i] == '<'){
                i++;

                //Detects <title>
                if(input[i] == 't'){
                    i += 6;
                    while(input[i] != '<') title[x++] = input[i++];
                    title[x] = '\0';
                }

                //Detects <a>
                else if(input[i] == 'a'){
                    i += 2;
                    while(input[i] != '<')i++;
                    if(input[i] == '<' && input[i+1] == '/' && input[i+2] == 'a') countLink++;
                }
            }
            i++;
        }
    }

    //After finishing the input:
    printf("%s\n", title);
    printf("%d\n", countLink);
    return 0;
}