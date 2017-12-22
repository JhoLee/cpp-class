#include <iostream>
using namespace std;
class Point
{
protected:
	int m_x, m_y;
public:
	void Print();
	bool IsEqual(const Point& p);
	void SetXY(int x, int y);
	Point();
	Point(int x, int y);
	~Point() { }
};


void Point::Print() { 

	cout << "(" << m_x << ", " << m_y << ")";
}

bool Point::IsEqual(const Point& p) { 

	return (m_x == p.m_x && m_y == p.m_y);
}

void Point::SetXY(int x, int y) { 
	
	m_x = x;
	m_y = y;
}

Point::Point(int x, int y) { 

	m_x = x;
	m_y = y;
}

int main()
{
	Point p1(10, 20);
	p1.Print();

	return 0;
}