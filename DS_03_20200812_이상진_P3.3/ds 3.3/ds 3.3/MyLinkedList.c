#include "MyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//노드 생성함수
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

//해당하는 위치의 노드주소를 반환하는 함수
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

//출력함수
void Print_Linked_list(Node* head)
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

//타켓하는 노드의 주소를 받아 헤드에서부터 찾아나가 지우는 함수
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

//노드를 특정위치에 추가시키는 함수
void Insert_Node_After(Node* currentNode, Node* newNode)
{
	Node* temp = currentNode->link;
	currentNode->link = newNode;
	newNode->link = temp;
}

//data를 입력받아 그 데이터를 갇는 위치를 출력하는 함수
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
		printf("%d는 %d에 존재합니다", data, pos);
		return current_node;
	}
	else if (current_node->link == NULL)
	{
		printf("존재하지않습니다.");
	}
}

Node* Reverse_List(Node* head)
{
	Node* reverse = NULL;
	Node* temp = NULL;
	while (head != NULL)
	{
		temp = reverse;
		reverse = head;
		head = head->link;
		reverse->link = temp;
	}
	return reverse;
}