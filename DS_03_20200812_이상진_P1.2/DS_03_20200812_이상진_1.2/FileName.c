#include <stdio.h>
#define MAT_SIZE 5

void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]) {
    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            B[j][i] =A[i][j];

        }
    }
    return;
}

void Print_MAT(int arr[][MAT_SIZE]) {
        for (int i = 0; i < MAT_SIZE; i++) {
            for (int j = 0; j < MAT_SIZE; j++) {
                printf("%d ", arr[i][j]);
                
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

int main(void){
	int A[5][5]= { {3,2,6,4,5},
              {8,3,5,9,1},
              {0,3,2,7,9},
              {2,1,5,2,4},
              {5,0,8,2,3} };

    int B[MAT_SIZE][MAT_SIZE];
    
    Print_MAT(A);
    Transpose_Mat(A,B);
    Print_MAT(B);
    return 0;
}