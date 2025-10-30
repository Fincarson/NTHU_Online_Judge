#include<stdio.h>

int N, K;
int array[200000];
unsigned long long prefixSum[200001] = {0};

unsigned long long calculate(int left, int right){
	if(left > right) return 0;
    return prefixSum[right] - prefixSum[left-1];
}


//Time ~ O(1)

int findTreasure(int left, int right){
    unsigned long long sum, sumMax = 0, Q;
    if(left == right)
		return array[left];
    int middle = (left + right)/2;
	
	unsigned long long leftSum = calculate(left, middle-1);
	unsigned long long rightSum = calculate(middle+1, right);
	
	return (leftSum <= rightSum)? findTreasure(middle+1, right): findTreasure(left, middle-1);
}

int main(void){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", &array[i]);
        prefixSum[i] = prefixSum[i-1] + array[i];
    }
    for(int j = 0; j<K; j++){
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", findTreasure(left, right));
    }

    //O (K * log(N))
    return 0;
}
