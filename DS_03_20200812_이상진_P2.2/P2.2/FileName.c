#include <stdio.h>
#define MAX_ELEMENTS 8

typedef struct Element
{
	int row;
	int col;
	int value;
}Element;

Element* Transpose_Triple2(Element S_a[])
{
	static Element S_b[MAX_ELEMENTS];
	int v_num1 = S_a[0].value;
	S_b[0].col = S_a[0].row;
	S_b[0].row = S_a[0].col;
	S_b[0].value = v_num1;
	int row[MAX_ELEMENTS];
	int pos[MAX_ELEMENTS];
	if (v_num1 > 0)
	{
		for (int i = 0; i < S_a[0].col; i++)
		{
			row[i] = 0;
		}
		for (int i = 1; i <= v_num1; i++)
		{
			row[S_a[i].col] += 1;
		}
		pos[0] = 1;

		for (int i = 1; i < (S_a[0].col - 1); i++)
		{
			pos[i] = pos[i - 1] + row[i - 1];
		}
		for (int i = 1; i <= (v_num1); i++)
		{
			int abs_pos = pos[S_a[i].col];
			S_b[abs_pos].row = S_a[i].col;
			S_b[abs_pos].col = S_a[i].row;
			S_b[abs_pos].value = S_a[i].value;
			pos[S_a[i].col] = pos[S_a[i].col] + 1;
		}
		printf("\n");
		for (int i = 0; i < MAX_ELEMENTS; i++)
		{
			printf("%d, %d, %d \n", S_b[i].row, S_b[i].col, S_b[i].value);
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
	Element* Sparse_B2;
	printf("\n");
	Sparse_B2 = Transpose_Triple2(Sparse_A);

	Print_Sparse_MAt(Sparse_A);


	Print_Sparse_MAt(Sparse_B2);




	return 0;
}