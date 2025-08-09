#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(){
    char arr[50];
    scanf("%s", arr);

    int n = strlen(arr);

    int priority=0;

    int value = 0;

    // Maximum triple
    char prev = 'A';
    int consecutive = 0;

    for(int i=0; i<n; i++){
        char cur = arr[i];
        char next = arr[i+1];
        // Check consecutive
        switch(cur){
            case 'V':
            case 'L':
            case 'D':
                if(prev == cur){
                    return -1;
                }
                break;
            default:
                if(prev == cur){
                    if(consecutive == 3)
                        return -1;
                    else{
                        consecutive++;
                    }
                }
                else{
                    consecutive = 1;
                }
                break;
        }

        // Check Priority Order
        switch (cur) {
            case 'M':
                if (priority > 0) return -1;
                priority = 0;
                break;
            case 'D':
                if (priority > 1) return -1;
                priority = 1;
                break;
            case 'C':
                if (priority > 2) return -1;
                priority = 2;
                break;
            case 'L':
                if (priority > 3) return -1;
                priority = 3;
                break;
            case 'X':
                if (priority > 4) return -1;
                priority = 4;
                break;
            case 'V':
                if (priority > 5) return -1;
                priority = 5;
                break;
            case 'I':
                if (priority > 6) return -1;
                priority = 6;
                break;
            default:
                return -1;
        }

        // Adding Value
        switch (cur) {
            case 'I':
                if(next == 'V') {
                    if(consecutive > 1) return -1;
                    priority++;
                    value += 4;
                    i++;
                }
                else if(next == 'X'){
                    if(consecutive > 1) return -1;
                    priority++;
                    value += 9;
                    i++;
                }
                else{
                   value += 1;
                }
                break;
            case 'V':
                value += 5;
                break;
            case 'X':
                if(next == 'L') {
                    if(consecutive > 1) return -1;
                    priority++;
                    value += 40;
                    i++;
                }
                else if(next == 'C'){
                    if(consecutive > 1) return -1;
                    priority++;
                    value += 90;
                    i++;
                }
                else{
                   value += 10;
                }
                break;
            case 'L':
                value += 50;
                break;
            case 'C':
                if(next == 'D') {
                    if(consecutive > 1) return -1;
                    priority++;
                    value += 400;
                    i++;
                }
                else if(next == 'M'){
                    if(consecutive > 1) return -1;
                    priority++;
                    value += 900;
                    i++;
                }
                else{
                   value += 100;
                }
                break;
            case 'D':
                value += 500;
                break;
            case 'M':
                value += 1000;
                break;
            default:
                return -1;
        }

        prev = cur;

    }

    return value;

}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int ans = solve();
        if(ans == -1){
            printf("QQ\n");
        }
        else{
            printf("%d\n", ans);
        }
    }
}