#include "MyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//��� �����Լ�
Node* Create_Node(int newdata)
{
	Node* newnode;
	newnode = malloc(sizeof(Node));
	newnode->data = newdata;
	newnode->link = NULL;
	return newnode;
}

//��������Լ�
void Destroy_Node(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
	node = NULL;
}

//��� �߰��Լ�
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

//�ش��ϴ� ��ġ�� ����ּҸ� ��ȯ�ϴ� �Լ�
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
			printf("������尡 �����ϴ�.");
			break;
		}
	}
	return node_add;
}

//����Լ�
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

//Ÿ���ϴ� ����� �ּҸ� �޾� ��忡������ ã�Ƴ��� ����� �Լ�
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

//��带 Ư����ġ�� �߰���Ű�� �Լ�
void Insert_Node_After(Node* currentNode, Node* newNode)
{
	Node* temp = currentNode->link;
	currentNode->link = newNode;
	newNode->link = temp;
}

//data�� �Է¹޾� �� �����͸� ���� ��ġ�� ����ϴ� �Լ�
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
		printf("%d�� %d�� �����մϴ�", data, pos);
		return current_node;
	}
	else if (current_node->link == NULL)
	{
		printf("���������ʽ��ϴ�.");
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