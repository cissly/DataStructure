
1 과제설명

그래프 관련 기초함수를 구현하여라

void ADJ_Degree(int adj_mat[][MAX_VERTICES], int n);
void ADJ_Insert(G_Node** List, int i, int j);
void ADJ_Mat2List(int adj_mat[][MAX_VERTICES], int n, G_Node** List);
void Graph_DFS(G_Node** List, int v);
void Graph_DFS_Recursive(G_Node** List, int v)

2 소스코드

첨부

3 고찰

그래프를 처음 배울때 든 생각은 굳이 트리를 쓰지 않고 그래프를 써야하는 이유가 무엇인가 이다.
그래프는 트리와 달리 레벨이 없고 그냥 단순히 바닥에 흩뿌려진 자료를 보는 느낌이기에 이러한 생각이 들었다. 그래프를 사용해야하는 경우를 생각해본다면 자료들의 상하 관계가 뚜렸하지 않을 때 사용하는 경우 밖에 생각이 나지 않기에 여러모로 이해를 하기 어려웠고 어떻게 써야할지 감이 잘 잡히지 않는 자료구조의 부분이다.
