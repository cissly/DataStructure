#ifndef __MY_DOUBLY_LINKED_LIST_H__
#define __MY_DOUBLY_LINKED_LIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* DLL_Create_Node(int newData);
void DLL_Destroy_Node(Node* node);
void DLL_Append_Node(Node** head, Node* newNode);
Node* DLL_Get_Node(Node* head, int pos);
void DLL_Remove_Node(Node** head, Node* targetNode);
void DLL_Insert_Node_After(Node* currentNode, Node* newNode);
void DLL_Print_Linked_List(Node* head);
void DLL_Print_Linked_List_Reverse(Node* head);

#endif