#include <stdio.h>
#include "MyLinkedList.h"

int main(void) {
	Node* head = NULL
		;
	//�⺻ ���Ḯ��Ʈ ����
	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(25));
	Append_Node(&head, Create_Node(31));
	Append_Node(&head, Create_Node(24));
	//�⺻ ���Ḯ��Ʈ ���
	Print_Linked_list(head);
	//�� ���Ḯ��Ʈ �Լ� ȣ��
	Node* reverse = Reverse_List(head);
	//�� ���Ḯ��Ʈ ���
	Print_Linked_list(reverse);
	printf("\n");
	return 0;
}