#include "MyArrayStack.h"

void Stack_Init(ArrStack* pStack)
{
	pStack->top = -1;
}
void Stack_Push(ArrStack* pStack, int item)
{
	if (Stack_IsFull(pStack) == F)
	{
		pStack->top += 1;
		pStack->arr[pStack->top] = item;
	}
	else
	{
		printf("������ �����ϴ�.");
		return;
	}
}
Data Stack_Pop(ArrStack* pStack)
{
	if (Stack_IsEmpty(pStack) == F)
	{
		Data da = pStack->arr[pStack->top];
		pStack->top -= 1;
		return da;
	}
	else
	{
		printf("����ֽ��ϴ�.");
		return;
	}
}
Data Stack_Peek(ArrStack* pStack)
{
	if (Stack_IsEmpty(pStack) == T)
	{
		printf("����ֽ��ϴ�.");
		return;
	}
	else
	{
		return pStack->arr[pStack->top];
	}
}

Bool Stack_IsEmpty(ArrStack* pStack)
{
	if (pStack->top == -1)
	{
		return T;
	}
	else
	{
		return F;
	}
}
Bool Stack_IsFull(ArrStack* pStack)
{
	if (pStack->top == STACK_LEN-1)
	{
		return T;
	}
	else
	{
		return F;
	}
}