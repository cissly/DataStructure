
1. 과제설명 
기존의 연결리스트를 활용하여서 이중연결리스트의 함수들을 구현해보자
Node* DLL_Create_Node(int newData);
void DLL_Destroy_Node(Node* node);
void DLL_Append_Node(Node** head, Node* newNode);
Node* DLL_Get_Node(Node* head, int pos);
void DLL_Remove_Node(Node** head, Node* targetNode);
void DLL_Insert_Node_After(Node* currentNode, Node* newNode);
단 헤더파일로 분리할것

2. PDF 1페이지 부터

3. 고찰
 이번 이중연결리스트를 배우면서 이중연결리스트의 장점인 앞 뒤 노드를 알 수 있다는 것 그리고 이것을 통해서 앞서 있었던 연결리스트들 원형, 단방향 과 다른 기능들을 구현 할 수 있다 는 것을 느꼈지만 이중연결리스트를 통해 구현 할 수 있는것은 원형 연결리스트로도 조금은 더 복잡해지긴 하겠지만 구현이 가능하지않을까? 그렇다면 원형연결리스트의 끝과 시작이 붙어있다는점이 조금더 부각되어 원형 연결리스트가 조금 더 유용한 연결리스트이지 않을까 라는 생각을 하게 되었다. 이러한 생각을 가지고 언젠가 이런 생각을 부수는 프로그램을 만드는 기회가 생긴다면 조금 더 많은 생각을 할 수 있을것이고 이를 기대하게 되었다.
