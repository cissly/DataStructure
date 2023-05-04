
1. 과제설명

배열스택의 함수들을 구현해보자

void Stack_Init(ArrStack* pStack); //배열 스택 초기화

void Stack_Push(ArrStack* pStack, Data item); //데이터 삽입

Data Stack_Pop(ArrStack* pStack); //데이터 인출

Data Stack_Peek(ArrStack* pStack); //최상단 데이터 확인

Bool Stack_IsEmpty(ArrStack* pStack); //스택이 비어있는지 확인

Bool Stack_IsFull(ArrStack* pStack); //스택이 가득 차 있는지 확인

헤더파일로 분리할것

2. 소스코드

코드첨부

3. 고찰

 이번 실습을 하기 이전에도 스택이라는 자료구조에 대해 어느정도는 이해를 하고 있었지만 평범한 연결리스트를 이용한다면 훨씬 다양하게 이용할 수 있을텐데 굳이 이러한 활용을 제한해서 사용하는 스택이란 것은 도대체 어디에서 쓰일까 라는 생각을 하고 있었다. 이번 수업을 들으면서도 이런생각을 하고 있었지만 다르게 생각한다면 연결리스트의 다른 기능들을 제한하기 때문에 그런 기능들을 구현할 필요가 없다는 점과 구현되어 있지 않기에 의도한대로 사용될 가능성이 높아진다는 생각을 하게 되어 스택이란 것이 내가 예전에 생각한 이상한 자료구조가 아니구나 라고 느끼게 되었다.
