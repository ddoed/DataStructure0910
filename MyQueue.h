#pragma once
#include <iostream>
#include <queue>

/*
* �ڷᱸ�� : �����̳ʸ� �����ؼ� ������ ���صΰ� ����ϴ� ����� �ڷᱸ��
* 
* ť �ڷᱸ�� ����
* - �����Ͱ� ��µǴ� �ε����� front�̸����� ǥ��
* - �����Ͱ� ����Ǵ� �ε����� rear �̸����� ǥ��
* - ���� ť front rear �ʱⰪ���� �ǵ��ư� �� ����.
*/

// �����ؾ��� �Լ�
// �Է� �� ���� : push, pop
// �ʵ� �� ǥ�� : empty(), size(), front(), back()

template <typename T>
class ArrayBasedQueue
{
private:
	T* queue; // �����͸� �����ϱ����� �迭 �̸�
	int front; // ��� ��ġ�� ����Ű�� �ε���
	int rear; // ������ �Է� ��ġ�� ����Ű�� �ε���
	int iCount; // ���� �ڷᱸ���� ������ ����
public:
	// ������
	ArrayBasedQueue(int size = 10)
	{
		queue = new T[size];
		front = 0;
		rear = 0;
		iCount = 0;
	}
	~ArrayBasedQueue()
	{
		delete[] queue;
	}

	// �ʵ忡 ������ ���� �Լ�
	
	int size()
	{
		return iCount;
	}
	T getfront()
	{
		return queue[front];
	}
	
	T getback()
	{
		return queue[rear-1];
	}

	bool empty()
	{
		return (iCount == 0) ? true : false;
	}

	void push(T data)
	{
		queue[iCount] = data;
		rear++;
		iCount++;
	}

	void pop()
	{
		if (iCount != 0)
		{
			front++;
			iCount--;
		}
		else
		{
			std::cout << "������ϴ�" << std::endl;
		}
			
	}

	void print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}

	// Main Method ����� ���� �Լ� : ����, ����
};

template <typename T>
class LinkedQueue
{
private:
	struct QueueNode
	{
		T		   data;
		QueueNode* pNext;

		QueueNode(T data, QueueNode* pNode)
		{
			this->data = data;
			pNext = pNode;
		}
	};

	QueueNode*	front;
	QueueNode*	rear;
	int			iCount;
public:
	// ������ & �Ҹ���
	LinkedQueue()
	{
		front	= nullptr;
		rear	= nullptr;
		iCount	= 0;
	}
	~LinkedQueue() {}
	// Accessor
	T Front()
	{
		return front->data;
	}

	T Back()
	{
		return rear->data;
	}

	int Size()
	{
		return iCount;
	}

	bool Empty()
	{
		return iCount == 0 ? true : false;
	}

	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data, nullptr);

		if (Empty())
		{
			front	= newNode;
			rear	= newNode;
		}
		else
		{
			rear->pNext = newNode;
			rear = newNode;
		}
		iCount++;
	}

	void Pop()
	{
		if (Empty()) return;
		QueueNode* OldNode = front;
		front = front->pNext;
		delete[] OldNode;
		iCount--;
	}
};

/// <summary>
/// ���� ť�� ���� ť�� ������ �����ϱ� ���� ������ �ڷᱸ���Դϴ�.
/// ���� ť�� Frontm Rear�� ��Ȱ���ϱ� �����
/// Pop(Dequeue) : Front = (Front + 1) % �ִ밪
/// Push(Enqueu) : Rear = (Rear + 1) % �ִ밪
/// </summary>

void IQueueExample()
{

	ArrayBasedQueue<int> myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5);

	myQueue.print();
	std::cout << myQueue.getback() << std::endl;

	LinkedQueue<int> LQueue;
	LQueue.Push(1);
	LQueue.Push(2);
	LQueue.Push(3);
	LQueue.Push(4);
	LQueue.Push(5);

	LQueue.Pop();

	std::cout << LQueue.Front() << std::endl <<  LQueue.Back() << std::endl;
}