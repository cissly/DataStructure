#include <cstdio>
void swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
int Partition(int* random_data, int left, int right)
{
	int pivot = random_data[left];
	int low = left + 1;
	int high = right;
	while (low <= high)
	{
		while (random_data[high] > pivot)
		{
			high -= 1;
		}
		while ((low <= high) && (random_data[low] <= pivot))
		{
			low += 1;
		}
		if (low <= high)
		{
			swap(&random_data[low], &random_data[high]);
			low += 1;
			high -= 1;
		}
	}
	swap(&random_data[left], &random_data[high]);
	return high;
}

void Quick_Sort(int* random_data, int left, int right)
{
	if (left < right)
	{
		int q = Partition(random_data, left, right);
		Quick_Sort(random_data, left, q - 1);
		Quick_Sort(random_data, q + 1, right);
	}
}

int main()
{
	int random_data[] = { 27, 4, 37, 2, 62, 12, 59, 16, 49, 18 };
	int size = sizeof(random_data) / sizeof(int);
	printf("정렬 전 데이터: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", random_data[i]);
	}
	Quick_Sort(random_data, 0, size - 1);
	printf("\n정렬 후 데이터: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", random_data[i]);
	}
	return 0;
}