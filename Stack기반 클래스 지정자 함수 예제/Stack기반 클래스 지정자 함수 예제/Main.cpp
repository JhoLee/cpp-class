#include <iostream>

using namespace std;


class Stack
{
protected:
	int m_size;
	int m_top;
	int *m_buffer;


public:
	// ������ �Լ�
	int GetSize();
	int GetTop();
	bool SetSize(int size);
	bool GetData(int index, int& data);

public:
	void Initialize(int size = 10);
	void RemoveAll();
	bool Push(int value);
	bool Pop(int& value);
};



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

int Stack::GetSize()
{
	return m_size;
}

int Stack::GetTop()
{
	return m_top;
}

bool Stack::SetSize(int size) //������ ũ�⸦ �����ϴ� ������ �Լ�
{
	if (size < m_size)         return false;
	int* tmp = m_buffer;
	m_size = size;
	m_buffer = new int[m_size];
	memcpy(m_buffer, tmp, sizeof(int) * (m_top + 1));
	delete[] tmp;
	return true;
}

bool Stack::GetData(int index, int& data)
//���ÿ� ����� �������� index��° �������� ���� �о���� �Լ�
{
	if (index < 0 || index > m_top)    return false;
	data = m_buffer[index];
	return true;
}

int main()
{
	Stack s1;
	s1.Initialize(5);
	while (s1.Push(rand() % 100));   // �� ����

	int data;
	cout << "������ ����� ������ : ";

	for (int i = 0; i <= s1.GetTop(); i++)
	{
		s1.GetData(i, data);
		cout << data << " ";
	}
	cout << "\n";

	s1.SetSize(10);
	cout << "������ ũ�� : " << s1.GetSize() << "\n";
	cout << "������ �� : " << s1.GetTop() << "\n";

	s1.RemoveAll();
	return 0;
}
