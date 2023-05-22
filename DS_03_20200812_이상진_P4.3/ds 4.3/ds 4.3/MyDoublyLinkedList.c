#include "MyDoublyLinkedList.h"


Node* DLL_Create_Node(int newData)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = newData;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void DLL_Destroy_Node(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
}

void DLL_Append_Node(Node** head, Node* newNode)
{
	Node* tail = *head;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;
	}
}

Node* DLL_Get_Node(Node* head, int pos)
{
	int present_pos = 0;
	Node* node_add = head;
	while (present_pos <= pos - 1)
	{
		if (node_add != NULL)
		{
			node_add = node_add->next;
			present_pos += 1;
		}
		else
		{
			printf("다음노드가 없습니다.");
			break;
		}
	}
	return node_add;
}

void DLL_Remove_Node(Node* targetNode)
{
	if (targetNode->prev == NULL)
	{
		targetNode->next->prev = targetNode->prev;
	}
	if (targetNode->next == NULL)
	{
		targetNode->prev->next = targetNode->next;
	}
	else
	{
		targetNode->prev->next = targetNode->next;
		targetNode->next->prev = targetNode->prev;
		DLL_Destroy_Node(targetNode);
	}
}

void DLL_Insert_Node_After(Node* currentNode, Node* newNode)
{
	Node* temp = currentNode->next;
	currentNode->next = newNode;
	newNode->next = temp;
	newNode->prev = currentNode;
	newNode->next->prev = newNode;
}

void DLL_Print_Linked_List(Node* head)
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d ", i, iter->data);
		if (iter->next != NULL)
		{
			printf("<->");
		}
		iter = iter->next;
		i++;
	}
	printf("\n");
}

void DLL_Print_Linked_List_Reverse(Node* tail)
{
	Node* iter = tail;
	int i = 0;
	while (iter != NULL)
	{
		printf("node[%d]:%d ", i, iter->data);
		if (iter->prev != NULL)
		{
			printf("<->");
		}
		iter = iter->prev;
		i++;
	}
	printf("\n");
}