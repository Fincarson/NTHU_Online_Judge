#include <stdio.h>

int main() {
    int width, height;
    float kernel[3][3];

    //Scan in the size
    scanf("%d%d", &width, &height);

    //Initialize the image
    int input_image[width][height];
    int output_image[width - 2][height - 2];

    //Scan in the kernel
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            scanf("%f", &kernel[x][y]);
        }
    }

    //Scan in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            scanf("%d", &input_image[x][y]);
        }
    }

    //Process the data
    for (int offset_y = 0; offset_y < height - 2; offset_y++) {
        for (int offset_x = 0; offset_x < width - 2; offset_x++) {
            float sum = 0;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    sum += kernel[x][y] * input_image[x + offset_x][y + offset_y];
                }
            }
            output_image[offset_x][offset_y] = sum;
        }
    }

    //Output the data
    for (int y = 0; y < height - 2; y++) {
        for (int x = 0; x < width - 2; x++) {
            printf("%4d ", output_image[x][y]);
        }
        printf("\n");
    }
}