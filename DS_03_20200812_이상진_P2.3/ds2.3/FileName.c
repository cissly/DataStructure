#include <stdio.h>
#define NO_OF_TERMS 20

//�Ѱ����� ������ ����� �����ϴ� ����üpoly
typedef struct poly 
{
	int coef;
	int expon;
}Term;

int Cs;
int Ce;

// ����ü �迭�� avail ������ ����ü�� ���� �ִ� �Լ�
void insert(Term poly[], int avail,int coef, int expon) 
{
	poly[avail].coef = coef;
	poly[avail].expon = expon;
}

//�� ���׽��� �ϳ��� ����ü �迭�� �־� ���� ���׽��� �迭���� �Է��ϴ� �Լ�
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

//���׽� ����ϴ� �Լ�
void Print_Poly(Term poly[], int As, int Ae, int Bs, int Be, int avail)
{
	for (int i = 0; i < avail; i++)
	{
		if (i == As)
		{
			printf("A���׽���:");
		}
		else if (i == Bs)
		{
			printf("B���׽���:");
		}
		else if (i == Cs)
		{
			printf("C���׽���:");
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