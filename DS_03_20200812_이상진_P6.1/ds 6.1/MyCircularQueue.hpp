#ifndef __MY_CIRCULAR_QUEUE_HPP__
#define __MY_CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; //������ ���� ��ġ(-1)
	int rear; //������ ������ ��ġ
	T* arr; //ť�� ������ ������ ���� ����
	int qSize; //ť�� ���̸� ����
public:
	CircularQueue() {
		front = -1;
		rear = -1;
		arr = new T[QUEUE_SIZE];
		qSize = QUEUE_SIZE;
	}
	CircularQueue(int size) {
		front = -1;
		rear = -1;
		arr = new T[size];
		qSize = size;
	}
	//ť�� ��� �ִ��� Ȯ��
	bool IsEmpty() 
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	} 
	//ť�� ���� �� �ִ��� Ȯ��
	bool IsFull() 
	{
		if (front == ((rear + 1) % QUEUE_SIZE))
		{
			return true;
		}
		else
		{
			return false;
		}
	
	} 
	//ť�� �����͸� ����
	bool Enqueue(T item) 
	{
		if (IsFull())
		{
			return false;
		}
		rear = (rear + 1) % QUEUE_SIZE;
		arr[rear] = item;
	}
	//ť���� �����͸� ����
	T Dequeue() 
	{
		if (IsEmpty())
		{
			return NULL;
		}
		front = (front + 1) % QUEUE_SIZE;
		return arr[front];
	} 
	//�ֻ�� �����͸� Ȯ��
	T Peek() 
	{
		if (IsEmpty())
		{
			return;
		}
		int temp = (front + 1) % QUEUE_SIZE;
		return arr[temp];
	} 
	~CircularQueue() {
		delete[] arr;
	}
};
#endif