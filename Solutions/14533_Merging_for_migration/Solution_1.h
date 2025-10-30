#include <stdio.h>
#include <stdlib.h>

struct data {
    int index;
    int age;
    int height;
};

//FUNCTIONS
void sort_by_age(int l, int r, struct data *arr);
//To sort the elephants by age

void sort_by_height(int l, int r, struct data *arr);
//To sort the elephants by height

void print_elephants(int l, int r, struct data *arr);
//To print out the order of elephants after sorting



// TODO: Implement the following functions in your function.c
void merge_by_age(int l, int m, int r, struct data *arr){
    //l = left
    //m = middle
    //r = right

    struct data*temp = (struct data*)malloc((r-l+1)*sizeof(struct data));
    //Make temporary structure

    int i = l, j = m+1, k = 0;
    //i represents the left index
    //j represent the middle index
    //k represent the input index (read the code below for more explanation)

    //Start sorting merging
    while(i <= m && j <= r){
        if(arr[i].age < arr[j].age || arr[i].age == arr[j].age && arr[i].index < arr[j].index) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    //Merge the remaining
    while(i <= m) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];

    //Start putting the merged and sorted temporary array to the original array
    for(i = l, k = 0; i<=r; i++, k++) arr[i] = temp[k];

    //Free the temp memory
    free(temp);
}


void merge_by_height(int l, int m, int r, struct data *arr){ //LITERALLY THE SAME with merge_by_age, but its height
    //l = left
    //m = middle
    //r = right

    struct data *temp = (struct data*)malloc((r-l+1) * sizeof(struct data));
    //Make temporary structure

    int i = l, j = m+1, k = 0;
    //i represents the left index
    //j represent the middle index
    //k represent the input index (read the code below for more explanation)

    //Start sorting merging
    while(i <= m && j <= r){
        if(arr[i].height < arr[j].height || arr[i].height == arr[j].height && arr[i].index < arr[j].index) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    //Merge the remaining
    while(i <= m) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];


    //Start putting the merged and sorted temporary array to the original array
    for(i = l, k = 0; i<=r; i++, k++) arr[i] = temp[k];

    //Free the temp memory
    free(temp);
}

