// Stack.h : Stack Ŭ������ ��� ����

#ifndef STACK_H
#define STACK_H

class Stack
{
public:
	int m_size;
	int m_top;
	int *m_buffer;

	void Initialize(int size = 10);
	void RemoveAll();
	bool Push(int value);
	bool Pop(int& value);
};

#endif
