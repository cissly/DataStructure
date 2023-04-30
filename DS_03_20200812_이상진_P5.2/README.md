
1. 과제설명
배열 스택을 활용한 계산기를 구현해보자

//1) 중위식 -> 후위식 변환

void Infix2Postfix(const char* infix_exp, char* postfix_exp);//중위식 -> 후위식 변환

int IsDigit(char token);//숫자인지 확인

int IsOperator(char token);//연산자인지 확인

int Priority(char op);//우선순위 확인

//2) 후위식 계산 및 결과

int Eval_Postfix(char* postfix_exp);

헤더파일로 분리할것

2. 소스코드
코드첨부

3. 고찰
