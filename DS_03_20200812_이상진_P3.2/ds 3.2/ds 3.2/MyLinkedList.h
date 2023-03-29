#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__

typedef struct node
{
	int data;
	struct node* link;
}Node;

Node* Create_Node(int newdata);

void Destroy_Node(Node* node);

void Append_Node(Node** head, Node* newnode);

Node* Get_Node(Node* head, int pos);

void Print_list(Node* head);

void Remove_Node(Node** head, Node* targetNode);

void Insert_Node_After(Node* currentNode, Node* newNode);

#endif
