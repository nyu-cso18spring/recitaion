#include <stdio.h>
#include <stdlib.h>

#define ROWS 512
#define COLS ROWS


int main() {
    int arr1[ROWS][COLS];
    int arr2[COLS][COLS];

    int ans[ROWS][COLS];

    int sum;
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            sum = 0;
            /*ans[i][j] = 0; // sum;*/
            for (int k = 0; k < COLS; k++) {
                sum += arr1[i][k] * arr2[k][j];
                /*ans[i][j] += arr1[i][k] * arr2[k][j];*/
            }
            ans[i][j] = sum;
        }
    }
    printf("Done...\n");
}
