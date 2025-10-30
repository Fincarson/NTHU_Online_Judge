#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char str[21];
int ans, max;

void solve(char*str, int bin){
    char ch = '\0';
    int count = 0;
    ans = 0;

    for(int i = 0; i < strlen(str); i++){
        if((bin>>i) & 1){
            if (ch == str[i]) count++;
            else{
                ans += (count)*(count+1)/2;
                count = 1;
                ch = str[i];
            }
        }
    }
    ans += (count)*(count+1)/2;
    if(ans > max) max = ans;
}

int main(void){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        for(int i = 0; i < (1<<strlen(str)); i++){
            solve(str, i);
        }
        printf("%d\n", max);
        max = 0;
    }
    return 0;
}
