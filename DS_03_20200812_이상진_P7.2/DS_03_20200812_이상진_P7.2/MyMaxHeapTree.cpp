#include "MyMaxHeapTree.h"

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
//최대 힙 트리 삽입/삭제 함수
void Max_Heap_Insert(int* heap, int* h_size, int key)
{
	*h_size += 1;
	int index = *h_size;
	heap[index] = key;
	while (index >1)
	{
		if (heap[index] > heap[int(index / 2)])
		{
			int temp = heap[int(index / 2)];
			heap[int(index / 2)] = heap[index];
			heap[index] = temp;
			index = int(index / 2);
			//TreePrinter(heap, *h_size); //삽입 결과 확인
		}
		else
		{
			break;
		}
	}
}
int Max_Heap_Remove(int* heap, int* h_size)
{
	int del_value = heap[1];
	heap[1] = heap[*h_size];
	*h_size -= 1;
	int parent = 1;
	int index = 2;
	while (index <= *h_size)
	{
		if (index < *h_size)
		{
			index = (heap[index] > heap[index + 1] ? index : index + 1);
		}

		if (heap[parent] >= heap[index])
		{
			break;
		}
		int temp = heap[index];
		heap[index] = heap[parent];
		heap[parent] = temp;
		parent = index;
		index = parent * 2;
	}
	return del_value;
}