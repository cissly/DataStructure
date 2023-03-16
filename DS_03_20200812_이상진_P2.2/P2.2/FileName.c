#include <stdio.h>
#define MAX_ELEMENTS 8

typedef struct Element
{
	int row;
	int col;
	int value;
}Element;

<<<<<<< HEAD
Element* Transpose_Triple2(Element S_a[])//ÀÔ·ÂÇÔ¼öÀÇ ÀüÄ¡Çà·Ä ÇÔ¼öÀÇ ÁÖ¼Ò¸¦ ¹ÝÈ¯ÇÏ´Â ÇÔ¼ö
{
	static Element S_b[MAX_ELEMENTS];//Çà·ÄÀÌ ÇÔ¼ö°¡ ³¡³ªµµ ³²¾ÆÀÖ°Ô ÇÏ´Â static
=======
Element* Transpose_Triple2(Element S_a[])//*ì•Œê³ ë¦¬ì¦˜3 ì„ êµ¬í˜„í•œ ì „ì¹˜í–‰ë ¬í•¨ìˆ˜
{
	static Element S_b[MAX_ELEMENTS];//í–‰ë ¬ì´ í•¨ìˆ˜ê°€ ëë‚˜ë„ ë‚¨ì•„ìžˆê²Œ í•˜ëŠ” static
>>>>>>> 7721fd497154b05853a309c55a89832a03d77414
	int v_num1 = S_a[0].value;
	S_b[0].col = S_a[0].row;
	S_b[0].row = S_a[0].col;
	S_b[0].value = v_num1;
	int row[MAX_ELEMENTS];
	int pos[MAX_ELEMENTS];
	if (v_num1 > 0)
	{
		for (int i = 0; i < S_a[0].col; i++)//ë¹ˆë„ìˆ˜ ì´ˆê¸°ì™€
		{
			row[i] = 0;
		}
		for (int i = 1; i <= v_num1; i++)
		{
			row[S_a[i].col] += 1; // °°Àº ¿­ °ªÀ» °¡Áö´Â ºóµµ¼ö È®ÀÎ
		}
<<<<<<< HEAD
		pos[0] = 1; //S_b[0]¿¡´Â ¹«Á¶°Ç Çà·Ä¿¡´ëÇÑ Á¤º¸°¡ µé¾î°¡±â¶§¹®¿¡ row°ª 0Àº ¹«Á¶°Ç S_b[1]ºÎÅÍ ½ÃÀÛÇÑ´Ù. 
=======
		pos[0] = 1;//ë°°ì—´ì˜ 0ìœ„ì¹˜ì—ëŠ” í–‰ë ¬ì˜ ì •ë³´ê°€ ë‹´ê²¨ìžˆìœ¼ë¯€ë¡œ ì‹œìž‘ì ì€ 1ìœ„ì¹˜ê°€ ë˜ì–´ì•¼í•¨
>>>>>>> 7721fd497154b05853a309c55a89832a03d77414

		for (int i = 1; i < (S_a[0].col - 1); i++)//(ìˆ«ìž)ì˜ í–‰ ì‹œìž‘ì ì€ (ìˆ«ìž-1)í–‰ì˜ ì‹œìž‘ì  + (ìˆ«ìž-1)ì˜ ë¹ˆë„ìˆ˜ ì™€ ê°™ë‹¤ 
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

void Print_Sparse_MAt(Element* arr) {//í¬ì†Œí–‰ë ¬ìˆ˜ì¶œë ¥í•¨ìˆ˜
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
