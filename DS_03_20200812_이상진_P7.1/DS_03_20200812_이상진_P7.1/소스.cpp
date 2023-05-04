#include <iostream>
#include <cmath>
using namespace std;


void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height);
void TreePrinter(int* bTree, int size);
//아래 함수를 구현
void PrintAncestor(int* bTree, int size, int idx);
void PrintLeftDescendant(int* bTree, int size, int idx);
void PrintRightDescendant(int* bTree, int size, int idx);
int FindNode(int* bTree, int size, int data);


int main() {
	int full_bTree[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 55, 35, 65, 75, 25, 91 };
	int size = sizeof(full_bTree) / sizeof(full_bTree[0]) - 1;
	TreePrinter(full_bTree, size);
	PrintAncestor(full_bTree, size, 14);
	PrintLeftDescendant(full_bTree, size, 1);
	PrintRightDescendant(full_bTree, size, 1);
	printf("%d 노드의 인덱스는 %d 입니다. \n", 30, FindNode(full_bTree, size, 30));
	return 0;
}

void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height) {
	if (idx > size) return;
	M[row][col] = bTree[idx];
	PrintTree2Matrix(M, bTree, size, idx * 2, col - pow(2, height - 2), row + 1, height - 1);
	PrintTree2Matrix(M, bTree, size, idx * 2 + 1, col + pow(2, height - 2), row + 1, height - 1);
}

void TreePrinter(int* bTree, int size) {
	int h = (int)ceil(log2(size + 1));
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	PrintTree2Matrix(M, bTree, size, 1, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
				printf(" ");
			else
				printf("%2d", M[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
}
//아래 함수를 구현

void PrintAncestor(int* bTree, int size, int idx)
{
	cout << bTree[idx] << "의 모든 조상 노드:";

	do
	{
		cout << bTree[idx] << " ";
		idx = idx / 2;
		idx = (int)idx;
	} while (idx > 1);
	cout << endl;
}

void PrintLeftDescendant(int* bTree, int size, int idx)
{
	cout << bTree[idx] << "의 모든 왼쪽 후손 노드: ";
	idx *= 2;
	while (idx < (size+1))
	{
		cout << bTree[idx] << " ";
		idx *= 2;
	}
	cout << endl;
}
void PrintRightDescendant(int* bTree, int size, int idx)
{
	cout << bTree[idx] << "의 모든 왼쪽 후손 노드: ";
	idx *= 2;
	idx += 1;
	while (idx < (size+1) )
	{
		cout << bTree[idx] << " ";
		idx *= 2;
		idx += 1;
	}
	cout << endl;
}
int FindNode(int* bTree, int size, int data)
{
	for (int i = 1; i <= size; i++)
	{
		if (data == bTree[i])
		{
			return i;
		}
	}
}