#include <stdio.h>

int main(){
    /* Scanning Input Array */
    int inputH, inputW;
    scanf("%d%d", &inputH, &inputW);
    int input[inputH][inputW]; // Input Array
    for(int i=0; i<inputH; i++){
        for(int j=0; j<inputW; j++){
            scanf("%d", &input[i][j]);
        }
    }

    /* Scanning Kernel */
    int kernelH, kernelW;
    scanf("%d%d", &kernelH, &kernelW);
    int kernel[kernelH][kernelW]; // Kernel Array
    for(int i=0; i<kernelH; i++){
        for(int j=0; j<kernelW; j++){
            scanf("%d", &kernel[i][j]);
        }
    }

    /* Scanning Stride and Padding */
    int stride, padding;
    scanf("%d%d", &stride, &padding);

    /* Create the final array with padding */
    int height = inputH + padding * 2;
    int width = inputW + padding * 2;
    int arr[height][width];
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            arr[i][j] = 0;
        }
    }
    /* Replace the center with input */
    for(int i=0; i<inputH; i++){
        for(int j=0; j<inputW; j++){
            arr[i+padding][j+padding] = input[i][j];
        }
    }

    /* Calculate the Output  and print */
    int outputH = (height - kernelH);
    int outputW = (width - kernelW);
    for(int i=0; i<=outputH; i+=stride){
        for(int j=0; j<=outputW; j+=stride){
            int sum=0;
            for(int x=0; x<kernelH; x++){
                for(int y=0; y<kernelW; y++){
                    sum += arr[i+x][j+y] * kernel[x][y];
                }
            }
            printf("%d", sum);
            if(j + stride > outputW) printf("\n");
            else printf(" ");
        }
    }

}
