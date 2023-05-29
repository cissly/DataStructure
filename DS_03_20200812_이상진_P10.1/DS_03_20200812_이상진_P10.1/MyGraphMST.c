#include "MyGraphMST.h"

//���Ͽ� ����� �����ͷ� ����ġ �׷��� ����
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES])
{
	FILE* file;
	fopen_s(&file, g_file, "r");
	if (file == NULL)
	{
		printf("������ �����ϴ�.");
		return;
	}
	while (1)
	{
		int i, j, w;
		int result = fscanf_s(file,"%d,%d,%d", &i, &j, &w);
		if (result == EOF)
		{
			break;
		}
		weight_mat[i][j] = w;
		weight_mat[j][i] = w;
	}
}
//����Լ�
void ADJ_Print_Array(int weight_mat[][MAX_VERTICES], int n)
{

		printf("  ");
		for (int i = -1; i < n; i++) {
			for (int j = -1; j < n; j++) {
				if (i == -1) {
					if (j != -1) printf("%2d ", j);
					else printf(" ");
				}
				else {
					if (j == -1) printf("%2d ", i);
					else
					{
						if (weight_mat[i][j] == _CRT_INT_MAX)
						{
							printf("INF");
						}
						else
						{
							printf("%2d ", weight_mat[i][j]);
						}

					}
				}
			}
			printf("\n");
		}
	
}
//���� �˰��� ��� �ּҺ�� ����Ʈ��
void MST_Prim(int weight_mat[][MAX_VERTICES], int MST[][MAX_VERTICES], int n)
{
	int* selected = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		selected[i] = 0;
	}
	int edge_count = 0;
	selected[0] = 1;

	while (edge_count < n - 1)
	{
		int min = INT_MAX;
		int u = 0;
		int v = 0;
		for (int i = 0; i < n; i++)
		{
			if (selected[i] == 1)
			{
				for (int j = 0; j < n; j++)
				{
					if ((selected[j] == 0) && (min > weight_mat[i][j]))
					{
						min = weight_mat[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		selected[v] = 1;
		MST[u][v] = weight_mat[u][v];
		MST[v][u] = weight_mat[u][v];
		edge_count += 1;
	}
}