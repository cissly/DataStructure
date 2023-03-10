Algorithm Trandspose_Mat(int A[][Mat_size],int B[][Mat_size])

input : 배열 A 배열 B

output : 배열 A의 전치행렬 배열 B

define Mat_size 5

int B[Mat_size][Mat_size];      / s/e = 0 , Frequency = 0                          Total steps =0

for i = 0; i < Mat_size ; i++   / s/e = 1 , Frequency = Mat_size+1                 Total steps =i+1

 for j = 0; j < Mat_size ; j++  / s/e = 1 , Frequency = Mat_size(Mat_size+1)       Total steps =Mat_size(Mat_size+1)

  int B[j][i] = int A[i][j]     / s/e = 1 , Frequency = Mat_size^2                 Total steps =Mat_size^2
                                
  ㅁ                             / Total = 2Mat_size^2 +2Mat_size+1
                                
  ㅁ                             / O(n^2)


1. 과제설명

nXn 행렬이 주어졌을때 이 행렬의 전치행렬을 구하는 알고리즘을 의사코드로 기술하는 과제 1.1
(행렬이 5X5로 주어졌음)
원본배열 A를 받아 전치행렬 배열 B를 만들기 위해 배열 A,B둘다 받는 함수를 작성한후 for 반복문을 이용해 행과 열의 갯수를 곱한만큼 반복되는 반복문을 만들고
A의 전치행렬을 만들기위해 A의 행,열위치를 바꾸어 B에 대입하였음.
이후 알고리즘의 시간복잡도를 계산하기위해 위처럼 서술함.

2. 알고리즘 첨부

3. 과제에 대한 고찰

시간복잡도를 계산할때
for i = 0; i < Mat_size ; i++  의 문장이 왜 Mat_size + 1 번만큼 반복되는지 이해하기위해 구글링을 하여 해결하였음
관계연산자 < 가 마지막으로 반복문을 탈출할때 한번더 사용되기 때문에 빈도가 하나 올라가는것으로 이해하였음
