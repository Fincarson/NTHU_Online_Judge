#include <stdio.h>
#include <string.h>

void solve(){
    char str[20];
    scanf("%s", str);

    int n = strlen(str);

    int value = 0;
    int i = 0;
    while(i < n){
        if(str[i] == 'I'){
            value += 1;
        }
        if(str[i] == 'V'){
            value += 5;
        }
        if(str[i] == 'X'){
            value += 10;
        }
        if(str[i] == 'L'){
            value += 50;
        }
        if(str[i] == 'C'){
            value += 100;
        }
        if(str[i] == 'D'){
            value += 500;
        }
        if(str[i] == 'M'){
            value += 1000;
        }

        i++;
    }

    printf("%d\n", value);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}