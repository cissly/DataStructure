1. 실습 3.1 ~3.2에 이어서 주어진 연결리스트의 역연결리스트를 만드는 함수
Node* Reverse_List(Node* head);
를 구현해보자 
메인함수는 주어진 코드를 사용한다.

2. PDF 1페이지 부터

3. 과제 3.2 에서 추가된 코드는 MyLinkedList.c에 정의와 헤더파일에 선언이고 메인은 주어진코드를 사용하였다.

//추가된 코드

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
  
//코드
