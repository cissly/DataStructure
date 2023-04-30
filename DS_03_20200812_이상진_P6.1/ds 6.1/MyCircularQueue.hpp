#ifndef __MY_CIRCULAR_QUEUE_HPP__
#define __MY_CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; //데이터 시작 위치(-1)
	int rear; //데이터 마지막 위치
	T* arr; //큐의 실질적 데이터 저장 공간
	int qSize; //큐의 길이를 저장
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
	//큐가 비어 있는지 확인
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
	//큐가 가득 차 있는지 확인
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
	//큐에 데이터를 삽입
	bool Enqueue(T item) 
	{
		if (IsFull())
		{
			return false;
		}
		rear = (rear + 1) % QUEUE_SIZE;
		arr[rear] = item;
	}
	//큐에서 데이터를 꺼냄
	T Dequeue() 
	{
		if (IsEmpty())
		{
			return NULL;
		}
		front = (front + 1) % QUEUE_SIZE;
		return arr[front];
	} 
	//최상단 데이터를 확인
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