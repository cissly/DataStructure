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
	newnode=malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->link = NULL;
	return newnode;
}

void Destroy_Node(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
	node = NULL;
}

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