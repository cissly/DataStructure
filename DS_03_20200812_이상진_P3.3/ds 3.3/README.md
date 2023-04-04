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

3.3과제를 4.1과 함께 제출하기때문에 가능한 고찰이 있다. 4.1의 과제를 체줄할때 원형 연결리스트의 끝을 가르키는 tail 노드포인터가 있는데 이것을 사용하면 할수록
다른 평범한 연결리스트에서도 그냥 head를 사용하는것이 아닌 tail을 사용한다면 특정한 상황에서 훨씬 간편하게 기능을 구현할 수 있다고 생각이 된다.
만약 다음에 연결리스트를 사용할 상황이 생긴다면 tail과 head를 둘다 변수로 만들어 사용해보아야겠다고 다짐하게 되었다.
