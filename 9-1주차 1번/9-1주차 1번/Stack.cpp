// Stack.cpp : Stack 클래스의 소스 파일
#include <string.h>
#include "Stack.h"

void Stack::Initialize(int size)
{
	m_size = size;
	m_top = -1;
	m_buffer = new int[m_size];
	memset(m_buffer, 0, sizeof(int) * m_size);
}

void Stack::RemoveAll()
{
	m_size = 0;
	m_top = -1;
	delete[] m_buffer;
	m_buffer = NULL;
}

bool Stack::Push(int value)
{
	if (m_top >= m_size - 1)       return false;
	m_buffer[++m_top] = value;
	return true;
}

bool Stack::Pop(int& value)
{
	if (m_top < 0)                 return false;
	value = m_buffer[m_top--];
	return true;
}
