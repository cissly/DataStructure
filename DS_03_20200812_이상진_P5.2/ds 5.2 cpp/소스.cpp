#include <iostream>
#include <cstring>
#include "헤더.hpp"
using namespace std;

void Infix2Postfix(const char* infix_exp, char* postfix_exp); //중위식->후위식 변환

int IsDigit(char token); //숫자인지 확인

int IsOperator(char token); //연산자인지 확인

int Priority(char op); //우선순위 확인

int Eval_Postfix(char* postfix_exp); // 후위식 계산 및 결과

int main(void) 
{
	char exp[] = "(2*7-4)"; //계산할 수식
	char* postfix = new char[strlen(exp) + 1]; //후위식 변환 결과

	//1) 중위식에서 후위식으로 변환
	Infix2Postfix(exp, postfix); //중위식에서 후위식으로 변환
	printf("Infix: %s\n", exp);
	printf("Postfix: %s\n", postfix); //변환 결과 출력
	////2) 변환된 후위식을 계산
	int result = Eval_Postfix(postfix);
	printf("%s = %d \n", postfix, result);
	return 0;
}

int IsDigit(char token)	//숫자인지 확인
{
	if (token >= 48 && token <= 57)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int IsOperator(char token) //연산자인지 확인
{
	if (token == '+' || token == '-' || token == '*' || token == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Priority(char op)
{
	int pri;
	switch(op)
	{
	case '*': case'/':
		pri = 3;
		break;
	case '+': case'-':
		pri = 2;
		break;
	case '(':
		pri = 1;
		break;
	default:
		pri = -1;
		break;
	}
	return pri;
}

void Infix2Postfix(const char* infix_exp, char* postfix_exp)
{
	int len = strlen(infix_exp);
	ArrStack<char> in(len+1);
	ArrStack<char> post;
	ArrStack<char> stack;
	for (int i = 0; len-i >= 0; i++)
	{
		in.Stack_Push(infix_exp[len - i]);
	}

	for (int i = 0; i < len; i++)
	{
		char token = in.Stack_Pop();

		if (IsDigit(token))
		{
			post.Stack_Push(token);
		}
		else if (IsOperator(token))
		{
			while (!stack.Stack_IsEmpty() && Priority(token) <= Priority(stack.Stack_Peek()))
			{
				post.Stack_Push(stack.Stack_Pop());
			}
			stack.Stack_Push(token);
		}
		else if (token == '(')
		{
			stack.Stack_Push(token);
		}
		else if (token == ')')
		{
			while (stack.Stack_Peek() != '(')
			{
				post.Stack_Push(stack.Stack_Pop());
			}
			stack.Stack_Pop();
		}

	}
	while (!stack.Stack_IsEmpty())
	{
		post.Stack_Push(stack.Stack_Pop());
	}

	char* temp = new char[len + 1];
	int i = 0;
	while (!post.Stack_IsEmpty())
	{
		temp[i++] = post.Stack_Pop();
	}
	temp[i] = NULL;
	i = 0;
	int postlen = strlen(temp);
	while( i < postlen)
	{
		char a =  temp[postlen -1 - i];
		postfix_exp[i] = a;
		i++;
	}
	postfix_exp[i] = NULL;
	
}


int Eval_Postfix(char* postfix_exp)
{
	ArrStack<int> stack;
	stack.Stack_Init();
	int len = strlen(postfix_exp);
	for (int i = 0; len - i >= 0; i++)
	{
		if (IsDigit(postfix_exp[i]))
		{
			stack.Stack_Push(postfix_exp[i]-48);
		}
		else
		{
			if (postfix_exp[i] == '+')
			{
				int a = stack.Stack_Pop();
				int b = stack.Stack_Pop();
				stack.Stack_Push(b + a);
			}
			else if (postfix_exp[i] == '-')
			{
				int a = stack.Stack_Pop();
				int b = stack.Stack_Pop();
				stack.Stack_Push(b - a);
			}
			else if (postfix_exp[i] == '/')
			{
				int a = stack.Stack_Pop();
				int b = stack.Stack_Pop();
				stack.Stack_Push(b / a);
			}
			else if (postfix_exp[i] == '*')
			{
				int a = stack.Stack_Pop();
				int b = stack.Stack_Pop();
				stack.Stack_Push(b * a);
			}
		}
	}

	return stack.Stack_Pop() ;
}