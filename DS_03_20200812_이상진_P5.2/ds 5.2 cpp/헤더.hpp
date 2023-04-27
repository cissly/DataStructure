#ifndef __MY_ARRAY_STACK_HPP__
#define __MY_ARRAY_STACK_HPP__
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define STACK_LEN 100
template <typename T>
class ArrStack {
private:
	T* arr;
	int length;
	int top;
public:
	ArrStack() {
		top = -1;
		length = STACK_LEN;
		arr = new T[STACK_LEN];
	}
	ArrStack(int len) {
		top = -1;
		length = len;
		arr = new T[len];
	}
	void Stack_Init() //배열 스택 초기화
	{ 
		this->top = -1;
	}
		
	void Stack_Push(T item) //데이터 삽입
	{
		if (!Stack_IsFull())
		{
			this->top += 1;
			this->arr[this->top] = item;
		}
		else
		{
			cout << "공간이 없습니다." << endl;
		}
	}
	
	T Stack_Pop() //데이터 인출
	{
		if (Stack_IsEmpty())
		{
			cout << "1. 비어 있습니다." << endl;
		}
		else
		{
			T da = this->arr[this->top];
			this->top -= 1;
			return da;
		}
	}
		
	T Stack_Peek() //최상단 데이터 확인
	{ 
		if (Stack_IsEmpty())
		{
			cout << "비어 있습니다." << endl;
		}
		else
		{
			return this->arr[this->top];
		}
	}
	
	bool Stack_IsEmpty() //스택이 비어있는지 확인
	{
		if (this->top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Stack_IsFull() //스택이 가득 차 있는지 확인
	{
		if (this->top == length - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}; //Array Stack 클래스 선언
#endif