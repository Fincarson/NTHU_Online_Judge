#include <stdio.h>
#include <string.h>

int main(){
    char arr[100000];
    int i = 0;
    int link = 0;
    char title[100];
    while(scanf("%c", &arr[i])!=EOF){
        i++;
    }
    char * ptr;
    ptr = strstr(arr, "<title>");
    for(int j=7;ptr[j]!='<';j++)
        title[j-7] = ptr[j];
    ptr = strstr(arr, "</a>");
    while(ptr!=NULL){
        link++;
        ptr = strstr(ptr+1, "</a>");
    }
    printf("%s\n%d\n", title, link);
}