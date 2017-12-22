// StaticMemberFunction.cpp : 정적 멤버 함수
#include <iostream>
using namespace std;

class Point
{
protected:
	int m_x, m_y;

public:
	void Print();
	void SetXY(int x, int y);
	bool IsEqual(const Point& p);
	Point(int x = 0, int y = 0);

protected:  // 정적 멤버 변수
	static int s_xScreen, s_yScreen;
public:
	static void SetScreenSize(int xScreen, int yScreen);
};

int Point::s_xScreen = 0;
int Point::s_yScreen = 0;

void Point::SetScreenSize(int xScreen, int yScreen)
{
	s_xScreen = xScreen;
	s_yScreen = yScreen;
}
//   s_xScreen = 1024, s_yScreen = 768;

void Point::Print()
{
	cout << "(" << m_x << ", " << m_y << ")";
}

void Point::SetXY(int x, int y)
{
	m_x = (x < s_xScreen) ? x : s_xScreen;
	m_y = (y < s_yScreen) ? y : s_yScreen;
}

bool Point::IsEqual(const Point& p)
{
	return (m_x == p.m_x && m_y == p.m_y);
}

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

int main() {
	//    Point::s_xScreen = 1024;
	//    Point::s_yScreen = 768;
	Point::SetScreenSize(500, 1000);

	Point p1(1000, 2000);
	cout << "p1의 좌표는 ";
	p1.Print();
	cout << "입니다.\n";

	p1.SetXY(2000, 1000);
	cout << "변경된 p1의 좌표는 ";
	p1.Print();
	cout << "입니다.\n";

	return 0;
}
