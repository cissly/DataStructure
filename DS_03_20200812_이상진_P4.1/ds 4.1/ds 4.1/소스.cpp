#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

Node* Newnode(int val)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	return newnode;
}

void Append_Node(Node** head, Node* newnode)
{
	if (*head == NULL)
	{
		*head = newnode;
		newnode->link = newnode;
	}
	else
	{
		Node* tail = *head;
		do
		{
			tail = tail->link;
		} while (tail->link != *head);
		tail->link = newnode;
		newnode->link = *head;
	}
}

void Append_Node_T(Node** tail, Node* newnode)
{
	if (*tail == NULL)
	{
		*tail = newnode;
		newnode->link = newnode;
	}

	else
	{
		newnode->link = (*tail)->link;
		(*tail)->link = newnode;
		*tail = newnode;
	}
}

void Print_Circular_Linked_List(Node* head)
{
	if (head == NULL) return; //헤드가 비어있으면, 함수 종료
	Node* iter = head;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 헤드로 연결되었는지 확인
	printf("\n");
}

void Print_Circular_Linked_List_T(Node* tail)
{
	if (tail == NULL) return; //꼬리가 비어있으면, 함수 종료
	Node* iter = tail->link;
	int i = 0;
	do
	{
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != tail->link); //헤드로 돌아올 때까지 반복
	printf("head:%d", iter->data); //마지막 노드가 처음로 연결되었는지 확인
	printf("\n");
}

void Append_Node_F(Node** tail, Node* newnode);
void Append_Node_T_F(Node** tail, Node* newnode);

int main(void)
{
	Node* head = NULL;

	//원형 연결리스트 구성
	Append_Node(&head, Newnode(15));

	Append_Node(&head, Newnode(25));

	Append_Node(&head, Newnode(31));

	Append_Node(&head, Newnode(24));
	
	//원형 연결리스트 출력
	Print_Circular_Linked_List(head);

	Node* tail = NULL;

	//원형 연결리스트 구성
	Append_Node_T(&tail, Newnode(15));

	Append_Node_T(&tail, Newnode(25));

	Append_Node_T(&tail, Newnode(31));

	Append_Node_T(&tail, Newnode(24));

	//원형 연결리스트 출력
	Print_Circular_Linked_List_T(tail);

}

//추가 응용학습
void Append_Node_T_F(Node** tail, Node* newnode)
{
	if (*tail == NULL)
	{
		*tail = newnode;
		newnode->link = newnode;
	}

	else
	{
		newnode->link = (*tail)->link;
		(*tail)->link = newnode;
	}
}

void Append_Node_F(Node** head, Node* newnode)
{
	if (*head== NULL)
	{
		*head = newnode;
		newnode->link = newnode;
	}

	else
	{
		newnode->link = *head;
		Node* tail = *head;
		do
		{
			tail = tail->link;
		} while (tail->link != *head);
		tail->link = newnode;
		*head = newnode;
	}
}