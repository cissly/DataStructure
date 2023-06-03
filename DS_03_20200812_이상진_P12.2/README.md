
1 과제설명

해시 탐색 알고리즘을 응용한 프로그램을 구현해보자 
int Hash_Function(int key, int Hash_Size);

void SInfo_Create(Std_Info* students, const char* file_name, int Hash_Size);

int Hash_Search(Std_Info* students, int key, int Hash_Size);

2 소스코드

첨부

3 고찰

주어진 정보를 활용하여서 해쉬값을 만든다는 발상이 정말 유용한다고 생각된다. 해쉬를 나누는 방법에 따라 조금더 공간의 낭비를 없이 해시 테이블을 만들 수 있다고 생각이 되고 해시 탐색은 해쉬 테이블을 어떤 방식에 따라 만드느냐에 상관없이 속도는 일정할것이다 라고 생각이 된다(충돌이 거의 없다면). 해수 테이블을 만드는 방식은 앞으로도 계속 쓰일것같으므로 조금 더 효율적으로 해쉬 테이블을 만드는 방법을 공부하는게 좋을것 같다 라고 생각이 된다.
