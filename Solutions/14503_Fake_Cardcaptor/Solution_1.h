#include <stdio.h>
#include <stdlib.h>

extern const int MAX_ARRAY;
extern const int MAX_ELEMENT;

typedef void (*myFunction)(int **, int *);

void placeFunction(int ** arr, int * size){
    //Input which table and how many elements we wants
    int index, length; scanf("%d %d", &index, &length);

    //Create new memory
    int newSize = size[index] + length;
    int *newArr = (int*)malloc(newSize*sizeof(int));

    //Copy all the values inside the old memory to the new one
    for(int i = 0; i < size[index]; i++){
        newArr[i] = arr[index][i];
    }

    //Start placing
    for(int i = size[index]; i < newSize; i++){
        scanf("%d", &newArr[i]);
    }

    //Remove (free) the old memory and replace it with the new one
    free(arr[index]);
    arr[index] = newArr;
    size[index] = newSize;
}

void deleteFunction(int ** arr, int * size){
    //Input which table we want to delete
    int index; scanf("%d", &index);

    //Delete
    free(arr[index]);
    arr[index] = NULL;

    //Don't forget to make the size 0
    size[index] = 0;
}

void swapFunction(int ** arr, int * size){
    //Input the 2 tables we want to swap
    int index1, index2; scanf("%d%d", &index1, &index2);

    //Swapping Adresses
    int *temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;

    //Swapping the sizes
    int tempSize = size[index1];
    size[index1] = size[index2];
    size[index2] = tempSize;
}

void reverseFunction(int ** arr, int * size){
    //The idea is SELECT whichever arrays has value
    //From there, we reverse them

    //Creating new array for all non-empty arrays
    int nonEmpty[MAX_ARRAY];
    int count = 0; //Count how many original arrays have value

    //We select the arrays that have value.
    for(int i = 0; i < MAX_ARRAY; i++){
        if(arr[i] != NULL && size[i] != 0){
            nonEmpty[count++] = i; //Select the index
        }
    }

    //After determining whichever arrays has value, we start reversing.
    int left = 0; int right = count-1;
    while(left < right){

        //Swapping the addresses
        int *temp = arr[nonEmpty[left]];
        arr[nonEmpty[left]] = arr[nonEmpty[right]];
        arr[nonEmpty[right]] = temp;

        //Swapping the size amount
        int tempSize = size[nonEmpty[left]];
        size[nonEmpty[left]] = size[nonEmpty[right]];
        size[nonEmpty[right]] = tempSize;

        //Don't forget to move on
        left++; right--;
    }
}

void popFunction(int ** arr, int * size){
    //Input the index and the amount of pop
    int index, length; scanf("%d %d", &index, &length);

    //If the length is MORE than the size of the array
    if(size[index] < length){
        free(arr[index]);
        arr[index] = NULL;
        size[index] = 0;
    }

    //If the length is LESS than the size of the array
    else{
        size[index] -= length;
        //Why not also delete the numbers?
        //In the print function, we only print as long as the SIZE[index]
        //So, we don't have to worry about the numbers at the back.
    }
}

void shiftFunction(int ** arr, int * size){
    //The idea here is putting the addresses of the arrays into the new array
    //After shifted, then we put them back to the original array
    //So basically, putting them into new array, overlap the original array with the new one.

    //Input how much we want to shift
    int length; scanf("%d", &length);

    //Create new memory
    int*newArray[MAX_ARRAY];
    int newSize[MAX_ARRAY];

    //Initialize the newArray and newSize manually
    for(int i = 0; i < MAX_ARRAY; i++){
        newArray[i] = NULL;
        newSize[i] = 0;
    }

    //Start shifting (One-by-one)
    for(int i = 0; i < MAX_ARRAY; i++){
        int newIndex = (i+length) % MAX_ARRAY;
        if(newIndex < 0){
            newIndex += MAX_ARRAY;
        }
        newArray[newIndex] = arr[i];
        newSize[newIndex] = size[i];
    }

    //Now we return them back to the original Array
    for(int i = 0; i < MAX_ARRAY; i++){
        arr[i] = newArray[i];
        size[i] = newSize[i];
    }
}

void sortFunction(int ** arr, int * size){
    //Input which index we want to sort
    int index; scanf("%d", &index);

    //Quick Sort (I hate bubble sort)
    for(int i = 0; i < size[index] - 1; i++){
        int min = i;
        for(int j = i+1; j < size[index]; j++){
            //Determining which index has the lowest integer value
            if (arr[index][min] > arr[index][j]){min = j;}
        }
        //Swap the value
        int temp = arr[index][i];
        arr[index][i] = arr[index][min];
        arr[index][min] = temp;
    }
}

void printFunction(int ** arr, int * size){
    int empty = 1; //To check if there's any arrays are printed or not

    for(int i = 0; i < MAX_ARRAY; i++){ //Check every array
        if(size[i] != 0 && arr[i] != NULL){
            empty = 0;
            printf("%d:", i);
            for(int j = 0; j < size[i]; j++){
                printf(" %d", arr[i][j]);
            }
            printf("\n");
        }
    }
    //If we don't have any array that has value
    if(empty) printf("Empty QQ\n");
}

//Assigning Functions
myFunction assignFunction(char * str){
    if      (strcmp(str, "place")  == 0) return placeFunction; //Return the ADDRESS of the function
    else if (strcmp(str, "delete") == 0) return deleteFunction;
    else if (strcmp(str, "swap")   == 0) return swapFunction;
    else if (strcmp(str, "reverse") == 0) return reverseFunction;
    else if (strcmp(str, "pop")    == 0) return popFunction;
    else if (strcmp(str, "shift")  == 0) return shiftFunction;
    else if (strcmp(str, "sort")   == 0) return sortFunction;
    else if (strcmp(str, "print")  == 0) return printFunction;
    return NULL;
}
