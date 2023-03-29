
1. 과제설명
3.1실습과제에 이어서 
Node* Get_Node(Node* head, int pos); //노드 탐색
void Remove_Node(Node** head, Node* targetNode);//노드 삭제
void Insert_Node_After(Node* currentNode, Node* newNode); //노드 삽입
이러한 함수들을 만들고 이러한 함수들을 헤더파일에 따로 추가해보자

2. PDF 1페이지

3. 과제에 대한 고찰
실습과제 3.1을 빨리끝내고 3.2를 만들 수 있었으나 헤더파일을 만드는 과정에서 코드를 조금 지워버리는 실수를 해버려서 노드삭제함수(remove) 함수를 다시 만들게 되었다. 그과정에 이전에 만들었던 함수는 헤더를 지우는 경우를 구현하지 않았던것을 기억하게 되었고 조금더 발전된 함수를 만들 수 있게 되었다. 만약 함수를 하나 더 추가할 수 있다면 특정 DATA를 입력받아 그 데이터를 찾는 함수를 만들면 좋겠다고 생각하게 되었고 구현해보았다.
Node* Search_Node(Node* head, int data)
{
	int pos = 0;
	Node* current_node = head;
	while (current_node->data != data)
	{
		pos += 1;
		if (current_node->link == NULL)
		{
			break;
		}
		current_node = current_node->link;
	}
	if (current_node->data == data)
	{
		printf("%d는 %d에 존재합니다", data ,pos);
		return current_node;
	}
	else if (current_node->link == NULL)
	{
		printf("존재하지않습니다.");
	}
}