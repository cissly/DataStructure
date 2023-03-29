#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"


int main(void)
{
	Node* head = NULL;
	//기본노드 생성
	Append_Node(&head, Create_Node(20));
	Append_Node(&head, Create_Node(31));
	Print_list(head);
	
	//get함수 기능테스트
	Node* temp = Get_Node(head, 0);
	printf("Get_Node() test: %d\n", temp->data);
	
	//insert함수 기능테스트
	Insert_Node_After(Get_Node(head, 0), Create_Node(25));
	Print_list(head);

	//remove함수 기능테스트
	Remove_Node(&head, Get_Node(head, 1));
	Print_list(head);

	Search_Node(head, 25);

	return 0;
}