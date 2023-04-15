#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

Node* Create_Node(int newdata)
{
	Node* newnode;
	newnode = malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->link = NULL;
	return newnode;
}

//노드제거함수
void Destroy_Node(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
	node = NULL;
}

//노드 추가함수
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


//출력함수
void Print_Linked_List(Node* head)
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d ", i, iter->data);
		if (iter->link != NULL)
		{
			printf("->");
		}
		iter = iter->link;
		i++;
	}
	printf("\n");
}

Node* Merge_List(Node* a, Node* b)
{
	Node* result = NULL;
	Node* temp_a = a;
	Node* temp_b = b;
	while ((temp_a != NULL) && (temp_b != NULL))
	{
		if (temp_a->data > temp_b->data)
		{
			Append_Node(&result, Create_Node(temp_b->data));
			temp_b = temp_b->link;
		}
		else
		{
			Append_Node(&result, Create_Node(temp_a->data));
			temp_a = temp_a->link;
		}
	}
	while (temp_a != NULL)
	{
		Append_Node(&result, Create_Node(temp_a->data));
		temp_a = temp_a->link;
	}
	while (temp_b != NULL)
	{
		Append_Node(&result, Create_Node(temp_b->data));
		temp_b = temp_b->link;
	}
	return result;
}

Node* Merge_List_P(Node* a, Node* b);
int main(void)
{
	Node* head_a = NULL
		;
	Node* head_b = NULL
		;
	Node* head_c = NULL
		;
	//a 연결리스트 구성
	Append_Node(&head_a, Create_Node(10));
	Append_Node(&head_a, Create_Node(20));
	Append_Node(&head_a, Create_Node(30));
	//b 연결리스트 구성
	Append_Node(&head_b, Create_Node(15));
	Append_Node(&head_b, Create_Node(25));
	Append_Node(&head_b, Create_Node(27));
	Append_Node(&head_b, Create_Node(28));
	//a,b 연결리스트 출력

	//연결리스트 합병 함수 호출
	head_c = Merge_List
	(head_a, head_b);
	//합병된 연결리스트 출력
	Print_Linked_List
	(head_a);
	Print_Linked_List
	(head_b);
	Print_Linked_List(head_c);

	Node* head_d = Merge_List_P(head_a,head_b);
	Print_Linked_List
	(head_a);
	Print_Linked_List
	(head_b);
	Print_Linked_List(head_d);
	return 0;
}

Node* Merge_List_P(Node* a, Node* b)
{
	Node* result = NULL;
	Node* pos = NULL;
	Node* temp_a = a;
	Node* temp_b = b;
	int num = 0;
	while ((temp_a != NULL) && (temp_b != NULL))
	{
		if (temp_a->data > temp_b->data)
		{
			Append_Node(&result, temp_b);
			pos = temp_b;
			temp_b = temp_b->link;
			pos->link = NULL;
			printf("노드 d %d회", ++num);
			Print_Linked_List(result);
		}
		else
		{
			Append_Node(&result, temp_a);
			pos = temp_a;
			temp_a = temp_a->link;
			pos->link = NULL;
			printf("노드 d %d회", ++num);
			Print_Linked_List(result);

		}
	}
	while (temp_a != NULL)
	{
		Append_Node(&result, temp_a);
		pos = temp_a;
		temp_a = temp_a->link;
		pos->link = NULL;
		printf("노드 d %d회", ++num);
		Print_Linked_List(result);
	}
	while (temp_b != NULL)
	{
		Append_Node(&result, temp_b);
		pos = temp_b;
		temp_b = temp_b->link;
		pos->link = NULL;
		printf("노드 d %d회", ++num);
		Print_Linked_List(result);
	}
	return result;
}