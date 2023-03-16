#include <stdio.h>
#define MAX_ELEMENTS 8

typedef struct Element
{
	int row;
	int col;
	int value;
}Element;

Element* Transpose_Triple1(Element S_a[])//입력함수의 전치행렬 함수의 주소를 반환하는 함수
{
	static Element S_b[MAX_ELEMENTS];//행렬이 함수가 끝나도 남아있게 하는 static
	int v_num1 = S_a[0].value;
	S_b[0].col = S_a[0].row;
	S_b[0].row = S_a[0].col;
	S_b[0].value = v_num1;
	printf("%d, %d, %d \n", S_b[0].row, S_b[0].col, S_b[0].value);
	if (v_num1 > 0) //
	{
		int current = 1;
		for (int i = 0; i <= S_a[0].col; i++)
		{
			for (int j = 1; j <= v_num1; j++)
			{
				if (S_a[j].col == i)
				{
					S_b[current].col = S_a[j].row;
					S_b[current].row = S_a[j].col;
					S_b[current].value = S_a[j].value;
					printf("%d, %d, %d \n", S_b[current].row, S_b[current].col, S_b[current].value);
					current += 1;
				}
			}
		
		}
	}
	return S_b;
	
}



void Print_Sparse_MAt(Element* arr) {
	int current = 1;
	for (int i = 0; i < arr[0].row; i++)
	{
		for (int j = 0; j < arr[0].col; j++)
		{
				if ((arr[current].row == i) && (arr[current].col == j))
				{
					printf("%d", arr[current].value);
					current += 1;
				}
				else
				{
					printf("0");
				}
		}
		printf("\n");
	}

	printf("\n");
}

int main(void) {
	Element Sparse_A[MAX_ELEMENTS] = { {6,6,7},
	{0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2} };
	Element* Sparse_B;
	Sparse_B= Transpose_Triple1(Sparse_A);

	Print_Sparse_MAt(Sparse_A);

	Print_Sparse_MAt(Sparse_B);





	return 0;
}
