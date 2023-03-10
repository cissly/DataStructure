#include <stdio.h>
#define MAT_SIZE 5 /*수업중 임의로 설정해주신 배열 크기*/

void Transpose_Mat(int A[][MAT_SIZE], int B[][MAT_SIZE]) {
    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            B[j][i] =A[i][j];

        }
    }
    return;
}/*전치행렬을 만드는 함수*/

void Print_MAT(int arr[][MAT_SIZE]) {
        for (int i = 0; i < MAT_SIZE; i++) {
            for (int j = 0; j < MAT_SIZE; j++) {
                printf("%d ", arr[i][j]);
                
            }
            printf("\n");
        }
        printf("\n");
        return;
}/*행렬을 출력하는 함수*/

int main(void){
	int A[5][5]= { {3,2,6,4,5},
              {8,3,5,9,1},
              {0,3,2,7,9},
              {2,1,5,2,4},
              {5,0,8,2,3} }; /*행렬 A를 설정*/

    int B[MAT_SIZE][MAT_SIZE];
    
    Print_MAT(A);/*원본행렬 A를 출력*/
    Transpose_Mat(A,B);/*행렬 A의 전치행렬 B를 생성*/
    Print_MAT(B);/*원본행렬 A의 전치행렬 B를 출력*/
    return 0;
}