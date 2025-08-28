#include<stdio.h>
#include<string.h>

//INITIALIZATION
int array[10][10000];
char command[10];

int main(void){
    //INITIALIZING POINTERS (ARRAY)
    int *pArray[10];
    for(int i = 0; i <= 9; i++){
        pArray[i] = array[i];
    }

    while(1){
        //INPUT STRING
        scanf("%s", command);

        //PRINT
        if(strcmp(command, "print") == 0){
            for(int i = 0; i <= 9; i++){
                printf("%d:", i);
                if(pArray[i][0] == 0){printf(" No card\n");}
                else{
                    for(int j = 0; pArray[i][j] != 0; j++){
                        printf(" %d", pArray[i][j]);
                    }
                    printf("\n");
                }
            }
        }

        //ALL
        else if(strcmp(command, "all") == 0){
            int num, len;
            scanf("%d%d", &num, &len);

            for(int i = 0; i <= 9; i++){
                for(int j = 0; j < len; j++){
                    pArray[i][j] = num;
                }
                pArray[i][len] = 0; //When printing, it will stop printing when it sees 0.
            }
        }

        //PLACE
        else if(strcmp(command, "place") == 0){
            int table, len;
            scanf("%d%d", &table, &len);

            for(int j = 0; j < len; j++){
                int input; scanf("%d", &input);
                pArray[table][j] = input;
            }
            pArray[table][len] = 0; //When printing, it will stop printing when it sees 0.
        }

        //SWAP (Swapping the addresses)
        else if(strcmp(command, "swap") == 0){
            int tableA, tableB;
            scanf("%d%d", &tableA, &tableB);

            int *temp = pArray[tableA];
            pArray[tableA] = pArray[tableB];
            pArray[tableB] = temp;
        }

        //CLEAR
        else if(strcmp(command, "clear") == 0){
            for(int i = 0; i <= 9; i++){
                for(int j = 0; pArray[i][j] != 0; j++){
                    pArray[i][j] = 0;
                }
            }
        }

        //EXIT
        else if(strcmp(command, "exit") == 0) {break;}
    }
    return 0;
}