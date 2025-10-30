#include <stdio.h>

int N;
long long input[100000];

void BubbleSort(int startingIdx, int optimize) {
    for (int i = startingIdx; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (input[j] < input[i]) {
                long long temp = input[j];
                input[j] = input[i];
                input[i] = temp;
            } else if (optimize == 1) break;
        }
    }
}


int main(){
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++){
        scanf("%lld", &input[i]);
    }
    
    //swap first
    BubbleSort(0, 0);

    //after swap, we do the calculation
    long long result = 0;
    for (int i = 0; i < N - 1; i++){        
        long long sum = input[i] + input[i + 1];
        input[i + 1] = sum;
        result += sum;
        BubbleSort(i + 1, 1);
    }

    printf("%lld", result);
}