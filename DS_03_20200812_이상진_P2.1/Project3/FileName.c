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
	if (v_num1 > 0)
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



void Print_Sparse_MAt(Element* arr) {//희소행렬을 출력하는 함수
	Element narr[MAX_ELEMENTS];
	int row[MAX_ELEMENTS];// 빈도수배열
	int pos[MAX_ELEMENTS];// 위치배열
	narr[0].row = arr[0].row;
	narr[0].col = arr[0].col;
	narr[0].value = arr[0].value;
	for (int i = 0; i < arr[0].row; i++)
	{
		row[i] = 0;
	}
	for (int i = 1; i <= arr[0].value; i++)
	{
		row[arr[i].row] += 1; 
	}
	pos[0] = 1;
	for (int i = 1; i <= (arr[0].col - 1); i++)
	{
		pos[i] = pos[i - 1] + row[i - 1];
	}
	for (int i = 1; i < (MAX_ELEMENTS); i++)
	{
		int abs_pos = pos[arr[i].row];
		narr[abs_pos].row = arr[i].row;
		narr[abs_pos].col = arr[i].col;
		narr[abs_pos].value = arr[i].value;
		pos[arr[i].row] += 1;
	}
	printf("\n");
	for (int i = 1; i < MAX_ELEMENTS; i++)
	{
		printf("%d, %d, %d \n", narr[i].row, narr[i].col, narr[i].value);
	}
	printf("\n");
	for (int i = 1; i < narr[0].col; i++)
	{
		for (int j = i+1; j <= MAX_ELEMENTS; j++)
		{
			if ((narr[i].row==narr[j].row)&&(narr[i].col > narr[j].col))
			{
				int temp;
				temp = narr[j].value;
				narr[j].value = narr[i].value;
				narr[i].value = temp;
				temp = narr[j].col;
				narr[j].col = narr[i].col;
				narr[i].col = temp;
				
			}
		}
	}
	int current = 1;
	for (int i = 0; i < narr[0].row; i++)
	{
		for (int j = 0; j < narr[0].col; j++)
		{
				if ((narr[current].row == i) && (narr[current].col == j))
				{
					printf("%d", narr[current].value);
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
	{1,4,7},
	{1,0,8},
	{2,3,3},
	{4,1,9},
	{4,0,5},
	{5,3,2} };
	Element* Sparse_B;
	Sparse_B= Transpose_Triple1(Sparse_A);

	Print_Sparse_MAt(Sparse_A);

	Print_Sparse_MAt(Sparse_B);





	return 0;
}
