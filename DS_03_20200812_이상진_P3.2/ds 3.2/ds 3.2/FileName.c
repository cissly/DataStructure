#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"


int main(void)
{
	Node* head = NULL;
	//�⺻��� ����
	Append_Node(&head, Create_Node(20));
	Append_Node(&head, Create_Node(31));
	Print_list(head);
	
	//get�Լ� ����׽�Ʈ
	Node* temp = Get_Node(head, 0);
	printf("Get_Node() test: %d\n", temp->data);
	
	//insert�Լ� ����׽�Ʈ
	Insert_Node_After(Get_Node(head, 0), Create_Node(25));
	Print_list(head);

	//remove�Լ� ����׽�Ʈ
	Remove_Node(&head, Get_Node(head, 1));
	Print_list(head);

	Search_Node(head, 25);

	return 0;
}