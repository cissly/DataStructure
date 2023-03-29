#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* link;
}Node;

//하나의 노드를 만들고 그 노드의 주소를 리턴하는 함수
Node* Create_Node(int newdata)
{
	Node* newnode;
	newnode=malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->link = NULL;
	return newnode;
}

//노드의 주소를 받아서 동적할당을 풀어주는 함수
void Destroy_Node(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
	node = NULL;
}

/*더블포인터인 헤드를 받아 헤드가 가리키는 노드가 없다면 헤드가 노드를 가리키게 하거나
연결리스트의 맨마지막에 노드를 추가시키는 함수*/
void Append_Node(Node** head, Node* newnode)
{
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		Node* tail = *head;
		while (tail->link != NULL)
		{
			tail = tail->link;
		}
		tail->link = newnode;
	}
}

//연결리스트 출력함수
void Print_list(Node* head)
{
	Node* iter = head;
	int i = 0;
	while(iter != NULL)
	{
		printf("node[%d]:%d \n", i, iter->data);
		iter = iter->link;
	}
}

int main(void)
{
	Node* head = NULL;
	Node* newnode = NULL;

	newnode = Create_Node(20);
	Append_Node(&head, newnode);

	newnode = Create_Node(30);
	Append_Node(&head, newnode);

	newnode = Create_Node(40);
	Append_Node(&head, newnode);

	Print_list(head);

	Get_Node(head, 2);
	return 0;
}