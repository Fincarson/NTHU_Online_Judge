#include<stdio.h>

//INITIALIZATION
long long length[51];


//Main Code
void OuQString(long long offset, int depth, long long left, long long right){
    if (depth == 0 || right < offset) return;
    //Skip if it's outside the range

    //Step 1: 'O'
    if(left <= offset && offset <= right) printf("O");
    offset++;

    //Step 2: s[k-1]
    if(left <= offset+length[depth-1]) OuQString(offset, depth-1, left, right);
    offset += length[depth-1];
    //'offset + length[k-1]' is indicating ONE position after the s[k-1]
    //Example: s[2] = OOuQuOuQQ, 'offset + length[k-1]' will indicate at index 4 ('u'),
    //because it's one position after the s[k-1] ('OuQ')
    //if 'l' is at the left of the condition, it will call the function

    //Step 3: 'u'
    if(left <= offset && offset <= right) printf("u");
    offset++;

    //Step 4: s[k-1]
    if(left <= offset+length[depth-1]) OuQString(offset, depth-1, left, right);
    offset += length[depth-1];
    //Same with the first s[k-1] explanation, 'offset + length[k - 1]' is indicating ONE position after the s[k-1]

    if(left <= offset && offset <= right) printf("Q");

}

int main(void){
    int k; long long l, r;

    //Precompute Length
    length[0] = 0; length[1] = 3;
    for(int i = 2; i < 50; i++){
        length[i] = 2*length[i-1] + 3;
    }

    //OuQ
    while(scanf("%d%lld%lld", &k, &l, &r) != EOF){
        OuQString(0, k, l, r);
        printf("\n");
    }
    return 0;
}