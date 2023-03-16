1. 과제설명
Element Sparse_A[MAX_ELEMENTS] =
  {0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2}
  
  입력으로 주어진 Sparse_A의 전치행렬 Sparse_B를 만들고
  Sparse_B 저장한 정보를 0을 포함한 희소행렬로 출력하여라

Element* Transpose_Triple1(Element S_a[]) 함수 구현
• void Print_Sparse_Mat (Element arr[]) 함수 구현


2. PDF 1페이지

3. 과제에 대한 고찰
	{8,8,7},
	{0,2,6},
	{1,0,5},
	{1,4,7},
	{2,3,3},
	{4,0,8},
	{4,1,9},
	{5,3,2}

실습과제의 의문점 하나는 주어진 값이 특정 규칙을 벗어나서 주어진다면 출력을 제대로 할 수 없게 만들어졌다는것이다.
예를들어 주어진배열의 값이 A[2] 와 A[5]의 값이 서로 바뀐다면 출력코드는 단순하게 위에서 부터 아래로 순서대로 오는것을 출력할 수 있게 만들어졌기 때문에 위 규칙을 벗어나도 정상적인 출력이 가능하게 만들려면 출력함수
• void Print_Sparse_Mat (Element arr[])
함수에 정리하는 기능까지 추가하여 구현하여야한다.
이를 과제 2.2에서 배운 알고리즘을 일부 차용하여 구현 하여 보았다.


	void Print_Sparse_MAt(Element* arr) {//희소행렬을 출력하는 함수
		Element narr[MAX_ELEMENTS];
		int row[MAX_ELEMENTS];// 빈도수배열
		int pos[MAX_ELEMENTS];// 위치배열
		narr[0].row = arr[0].row;
		narr[0].col = arr[0].col;
		narr[0].value = arr[0].value;
		for (int i = 0; i < arr[0].row; i++)
		{
			row[i] = 0;
		}
		for (int i = 1; i <= arr[0].value; i++)
		{
			row[arr[i].row] += 1; 
		}
		pos[0] = 1;
		for (int i = 1; i <= (arr[0].col - 1); i++)
		{
			pos[i] = pos[i - 1] + row[i - 1];
		}
		for (int i = 1; i < (MAX_ELEMENTS); i++)
		{
			int abs_pos = pos[arr[i].row];
			narr[abs_pos].row = arr[i].row;
			narr[abs_pos].col = arr[i].col;
			narr[abs_pos].value = arr[i].value;
			pos[arr[i].row] += 1;
		}
		printf("\n");
		for (int i = 1; i < MAX_ELEMENTS; i++)
		{
			printf("%d, %d, %d \n", narr[i].row, narr[i].col, narr[i].value);
		}
		printf("\n");
		for (int i = 1; i < narr[0].col; i++)
		{
			for (int j = i+1; j <= MAX_ELEMENTS; j++)
			{
				if ((narr[i].row==narr[j].row)&&(narr[i].col > narr[j].col))
				{
					int temp;
					temp = narr[j].value;
					narr[j].value = narr[i].value;
					narr[i].value = temp;
					temp = narr[j].col;
					narr[j].col = narr[i].col;
					narr[i].col = temp;

				}
			}
		}
		int current = 1;
		for (int i = 0; i < narr[0].row; i++)
		{
			for (int j = 0; j < narr[0].col; j++)
			{
					if ((narr[current].row == i) && (narr[current].col == j))
					{
						printf("%d", narr[current].value);
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

수업과 실습이 동시에 이루어지기 때문에 전치행렬을 구하는 함수는 쉽게 구현 할 수 있었고
배열을 프린트하는 함수를 만들때 반복문 사이에 끼여있는 변수들 i,j를 잘못 사용하여 많은 시간을 소모하여
다시한번 오탈자에 대한 경각심을 가지게 되었다
