#include "MyGraphSP.h"

//파일에 저장된 데이터로 가중치 그래프 구성
void ADJ_Create(const char* g_file, int weight_mat[][MAX_VERTICES])
{
	FILE* file;
	fopen_s(&file, g_file, "r");
	if (file == NULL)
	{
		printf("파일이 없습니다.");
		return;
	}
	while (1)
	{
		int i, j, w;
		int result = fscanf_s(file, "%d,%d,%d", &i, &j, &w);
		if (result == EOF)
		{
			break;
		}
		weight_mat[i][j] = w;
		weight_mat[j][i] = w;
	}
}
//출력함수
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
//최단거리 관련 함수
void Shortest_Path(int weight_mat[][MAX_VERTICES], int n, int v, int* path)
{
	int* distance = malloc(sizeof(int) * n);
	int* visited = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		distance[i] = weight_mat[v][i];
		path[i] = v;
		visited[i] = 0;
	}
	visited[v] = 1;
	int step = 1;
	while (step < n)
	{
		int k;
		int min = _CRT_INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if ((visited[i] == 0) && (distance[i] < min))
			{
				min = distance[i];
				k = i;
			}
		}
		visited[k] = 1;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == 0)
			{
				if ((weight_mat[k][j] != INT_MAX) && (distance[k] + weight_mat[k][j] < distance[j]))
				{
					distance[j] = distance[k] + weight_mat[k][j];
					path[j] = k;
				}
			}
		}
		step += 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("정점 %d -> 정점 %d: %d \n",v,i,distance[i]);

	}
}
void PrintPath(int* path, int v, int u)
{
	if (u == v) {
		printf("%d ", u);
		return;
	}
	PrintPath(path, v, path[u]);
	printf("-> %d ", u);
}