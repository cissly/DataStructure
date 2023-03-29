#include "MyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node* Create_Node(int newdata)
{
	Node* newnode;
	newnode = malloc(sizeof(Node));
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

Node* Get_Node(Node* head, int pos)
{
	int present_pos = 0;
	Node* node_add = head;
	while (present_pos <= pos - 1)
	{
		if (node_add != NULL)
		{
			node_add = node_add->link;
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

void Print_list(Node* head)
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

void Remove_Node(Node** head, Node* targetNode)
{
	Node* cur_node = *head;
	if (cur_node == targetNode)
	{
		*head = cur_node->link;
	}
	else
	{
		while ((cur_node->link != targetNode))
		{
			printf("%d", cur_node == targetNode);
			if (cur_node->link == NULL)
			{
				break;
			}
			cur_node = cur_node->link;
		}
		if (cur_node->link == targetNode)
		{
			cur_node->link = cur_node->link->link;
		}
	}
	free(targetNode);
}

void Insert_Node_After(Node* currentNode, Node* newNode)
{
	Node* temp = currentNode->link;
	currentNode->link = newNode;
	newNode->link = temp;
}

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