#include <stdio.h>
#define NO_OF_TERMS 20

//한가지의 차수와 계수를 저장하는 구조체poly
typedef struct poly 
{
	int coef;
	int expon;
}Term;

int Cs;
int Ce;

// 구조체 배열의 avail 번재의 구조체에 값을 넣는 함수
void insert(Term poly[], int avail,int coef, int expon) 
{
	poly[avail].coef = coef;
	poly[avail].expon = expon;
}

//두 다항식을 하나의 구조체 배열에 넣어 더한 다항식을 배열내에 입력하는 함수
void Poly_Add(Term poly[], int As, int Ae, int Bs, int Be, int* avail)
{
	Cs = *avail;
	while ((As <= Ae) && (Bs <= Be))
	{
		if (poly[As].expon > poly[Bs].expon)
		{
			insert(poly, *avail, poly[As].coef, poly[As].expon);
			As += 1;

		}
		else if (poly[As].expon < poly[Bs].expon)
		{
			insert(poly, *avail, poly[Bs].coef, poly[Bs].expon);
			Bs += 1;
	
		}
		else if (poly[As].expon == poly[Bs].expon)
		{
			if ((poly[As].coef + poly[Bs].coef) == 0)
			{
				Bs += 1;
				As += 1;
				*avail -= 1;
			}
			else
			{
				insert(poly, *avail, poly[Bs].coef + poly[As].coef, poly[Bs].expon);
				Bs += 1;
				As += 1;
			}

		}
		*avail += 1;
	}
	for (int i = As; i <= Ae; i++)
	{
		insert(poly, *avail, poly[i].coef, poly[i].expon);
		*avail += 1;
	}
	for (int i = Bs; i <= Be; i++)
	{
		insert(poly, *avail,poly[i].coef, poly[i].expon);
		*avail += 1;
	}
	Ce = *avail - 1;
}

//다항식 출력하는 함수
void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail)
{
	for (int i = 0; i < avail; i++)
	{
		if (i == As)
		{
			printf("A다항식은:");
		}
		else if (i == Bs)
		{
			printf("B다항식은:");
		}
		else if (i == Cs)
		{
			printf("C다항식은:");
		}
		printf(" %dx^%d ", poly[i].coef, poly[i].expon);
		if ((i == Ae) || (i == Be) || (i == Ce))
		{
			printf("\n\n");
		}
		else
		{
			printf("+");
		}
	}
}

int main(void)
{
	Term poly[NO_OF_TERMS] = { {3,5},{2,3} ,{2,0},{4,4},{5,3},{2,1} };
	int As = 0;
	int Ae = 2;
	int Bs = 3;
	int Be = 5;
	int avail = 6;
	Poly_Add(poly, As, Ae, Bs, Be, &avail);
	Print_Poly(poly, As, Ae, Bs, Be, avail);
	return 0;
}