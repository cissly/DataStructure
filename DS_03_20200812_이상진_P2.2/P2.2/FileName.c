#include <stdio.h>
#define MAX_ELEMENTS 8

typedef struct Element
{
	int row;
	int col;
	int value;
}Element;

<<<<<<< HEAD
Element* Transpose_Triple2(Element S_a[])//입력함수의 전치행렬 함수의 주소를 반환하는 함수
{
	static Element S_b[MAX_ELEMENTS];//행렬이 함수가 끝나도 남아있게 하는 static
=======
Element* Transpose_Triple2(Element S_a[])//*�븣怨좊━利�3 �쓣 援ы쁽�븳 �쟾移섑뻾�젹�븿�닔
{
	static Element S_b[MAX_ELEMENTS];//�뻾�젹�씠 �븿�닔媛� �걹�굹�룄 �궓�븘�엳寃� �븯�뒗 static
>>>>>>> 7721fd497154b05853a309c55a89832a03d77414
	int v_num1 = S_a[0].value;
	S_b[0].col = S_a[0].row;
	S_b[0].row = S_a[0].col;
	S_b[0].value = v_num1;
	int row[MAX_ELEMENTS];
	int pos[MAX_ELEMENTS];
	if (v_num1 > 0)
	{
		for (int i = 0; i < S_a[0].col; i++)//鍮덈룄�닔 珥덇린���
		{
			row[i] = 0;
		}
		for (int i = 1; i <= v_num1; i++)
		{
			row[S_a[i].col] += 1; // 같은 열 값을 가지는 빈도수 확인
		}
<<<<<<< HEAD
		pos[0] = 1; //S_b[0]에는 무조건 행렬에대한 정보가 들어가기때문에 row값 0은 무조건 S_b[1]부터 시작한다. 
=======
		pos[0] = 1;//諛곗뿴�쓽 0�쐞移섏뿉�뒗 �뻾�젹�쓽 �젙蹂닿�� �떞寃⑥엳�쑝誘�濡� �떆�옉�젏��� 1�쐞移섍�� �릺�뼱�빞�븿
>>>>>>> 7721fd497154b05853a309c55a89832a03d77414

		for (int i = 1; i < (S_a[0].col - 1); i++)//(�닽�옄)�쓽 �뻾 �떆�옉�젏��� (�닽�옄-1)�뻾�쓽 �떆�옉�젏 + (�닽�옄-1)�쓽 鍮덈룄�닔 ��� 媛숇떎 
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

void Print_Sparse_MAt(Element* arr) {//�씗�냼�뻾�젹�닔異쒕젰�븿�닔
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
