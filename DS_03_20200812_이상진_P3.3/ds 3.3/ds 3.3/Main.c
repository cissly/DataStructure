#include <stdio.h>
#include "MyLinkedList.h"

int main(void) {
	Node* head = NULL
		;
	//기본 연결리스트 구성
	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(25));
	Append_Node(&head, Create_Node(31));
	Append_Node(&head, Create_Node(24));
	//기본 연결리스트 출력
	Print_Linked_list(head);
	//역 연결리스트 함수 호출
	Node* reverse = Reverse_List(head);
	//역 연결리스트 출력
	Print_Linked_list(reverse);
	printf("\n");
	return 0;
}