#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "function.h"

const int MAX_ARRAY = 1000;
const int MAX_ELEMENT = 10000;

int main(){
    char cmd[20];

    /* init array */
    int ** arr = (int **)malloc(MAX_ARRAY * sizeof(int*));
    for(int i=0; i<MAX_ARRAY; i++)
        arr[i] = (int*)malloc(MAX_ELEMENT * sizeof(int));

    /* init array size */
    int * arrSize = (int*)malloc(MAX_ARRAY * sizeof(int));
    memset(arrSize, 0, MAX_ARRAY * sizeof(int));

    /* Register Function */
    myFunction func[10];
    func[1] = assignFunction("place");
    func[2] = assignFunction("delete");
    func[3] = assignFunction("swap");
    func[4] = assignFunction("reverse");
    func[5] = assignFunction("pop");
    func[6] = assignFunction("shift");
    func[7] = assignFunction("sort");
    func[8] = assignFunction("print");

    /* Testcase Loop */
    int T, idx;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &idx);
        assert(1 <= idx && idx <= 8);
        func[idx](arr, arrSize);
    }

    for(int i=0; i<MAX_ARRAY; i++) free(arr[i]);
    free(arr);
    free(arrSize);
}
