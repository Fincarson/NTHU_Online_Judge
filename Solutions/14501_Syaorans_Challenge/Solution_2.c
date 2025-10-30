#include<stdio.h>
#include<string.h>

//INITIALIZATION
int array[10][10001];
char command[10];

int main(void) {
    //INITIALIZING POINTERS (ARRAY)
    int* pArray[10];
    for (int i = 0; i <= 9; i++) {
        pArray[i] = array[i];
    }

    while (1) {
        //INPUT STRING
        scanf("%s", command);

        //PRINT
        if (strcmp(command, "print") == 0) {
            for (int i = 0; i <= 9; i++) {
                printf("%d:", i);
                if (pArray[i][0] == 0) { printf(" No card\n"); }
                else {
                    for (int j = 0; pArray[i][j] != 0; j++) {
                        printf(" %d", pArray[i][j]);
                    }
                    printf("\n");
                }
            }
        }

        //ALL
        else if (strcmp(command, "all") == 0) {
            int num, len;
            scanf("%d%d", &num, &len);

            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j < len; j++) {
                    pArray[i][j] = num;
                }
                pArray[i][len] = 0; //When printing, it will stop printing when it sees 0.
            }
        }

        //PLACE
        else if (strcmp(command, "place") == 0) {
            int table, len;
            scanf("%d%d", &table, &len);

            for (int j = 0; j < len; j++) {
                int input; scanf("%d", &input);
                pArray[table][j] = input;
            }
            pArray[table][len] = 0; //When printing, it will stop printing when it sees 0.
        }

        //SWAP (Swapping the addresses)
        else if (strcmp(command, "swap") == 0) {
            int tableA, tableB;
            scanf("%d%d", &tableA, &tableB);

            int* temp = pArray[tableA];
            pArray[tableA] = pArray[tableB];
            pArray[tableB] = temp;
        }

        //CLEAR
        else if (strcmp(command, "clear") == 0) {
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; pArray[i][j] != 0; j++) {
                    pArray[i][j] = 0;
                }
            }
        }

        //REVERSE
        else if (strcmp(command, "reverse") == 0) {
            int start = 0, stop = 0, middle = 0;
            scanf("%d %d", &start, &stop);

            if (stop < start) {
                middle = (10 - (start - stop) + 1) / 2;
            }
            else {
                middle = (stop - start + 1) / 2;
            }
            while (middle--) {
                int* temp = pArray[start];
                pArray[start] = pArray[stop];
                pArray[stop] = temp;

                start++; stop--;
                if (start > 9) { start = 0; }
                if (stop < 0) { stop = 9; }
            }
        }

        //EXIT
        else if (strcmp(command, "exit") == 0) { break; }
    }
    return 0;
}

