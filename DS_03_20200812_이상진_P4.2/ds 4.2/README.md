
1. 과제설명
오름차순으로 입력된 두개의 연결리스트를 하나의 연결리스트로 합병하는 함수를 구현하여라
Node* Merge_List(Node* head_a, Node* head_b)
메인함수는 주어진것을 이용할것

2. PDF 1페이지 부터

3. 고찰
지금까지 있었던 과제들중 비교적 쉽고 빠르게 끝나는 과제여서 추가로 주어지는 학습
본과제인 데이터를 추가하는것이 아닌 노드의 링크를 연결하여 원본을 훼손하돼 메모리의 추가적 사용이 없는 함수를 만들어 보았다.

		Node* Merge_List_P(Node* a, Node* b)
		{
			Node* result = NULL;
			Node* pos = NULL;
			Node* temp_a = a;
			Node* temp_b = b;
			int num = 0;
			while ((temp_a != NULL) && (temp_b != NULL))
			{
				if (temp_a->data > temp_b->data)
				{
					Append_Node(&result, temp_b);
					pos = temp_b;
					temp_b = temp_b->link;
					pos->link = NULL;
					printf("노드 d %d회", ++num);
					Print_Linked_List(result);
				}
				else
				{
					Append_Node(&result, temp_a);
					pos = temp_a;
					temp_a = temp_a->link;
					pos->link = NULL;
					printf("노드 d %d회", ++num);
					Print_Linked_List(result);

				}
			}
			while (temp_a != NULL)
			{
				Append_Node(&result, temp_a);
				pos = temp_a;
				temp_a = temp_a->link;
				pos->link = NULL;
				printf("노드 d %d회", ++num);
				Print_Linked_List(result);
			}
			while (temp_b != NULL)
			{
				Append_Node(&result, temp_b);
				pos = temp_b;
				temp_b = temp_b->link;
				pos->link = NULL;
				printf("노드 d %d회", ++num);
				Print_Linked_List(result);
			}
			return result;
		}
