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
	void Stack_Init() //�迭 ���� �ʱ�ȭ
	{ 
		this->top = -1;
	}
		
	void Stack_Push(T item) //������ ����
	{
		if (!Stack_IsFull())
		{
			this->top += 1;
			this->arr[this->top] = item;
		}
		else
		{
			cout << "������ �����ϴ�." << endl;
		}
	}
	
	T Stack_Pop() //������ ����
	{
		if (Stack_IsEmpty())
		{
			cout << "1. ��� �ֽ��ϴ�." << endl;
		}
		else
		{
			T da = this->arr[this->top];
			this->top -= 1;
			return da;
		}
	}
		
	T Stack_Peek() //�ֻ�� ������ Ȯ��
	{ 
		if (Stack_IsEmpty())
		{
			cout << "��� �ֽ��ϴ�." << endl;
		}
		else
		{
			return this->arr[this->top];
		}
	}
	
	bool Stack_IsEmpty() //������ ����ִ��� Ȯ��
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

	bool Stack_IsFull() //������ ���� �� �ִ��� Ȯ��
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
}; //Array Stack Ŭ���� ����
#endif