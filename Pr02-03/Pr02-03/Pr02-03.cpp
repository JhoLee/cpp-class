// Reference.cpp : 레퍼런스의 사용 예
// 변수 'ref'가 단순 변수인 경우
// (1626035, 이주호)
#include <iostream>
using namespace std;

int main() {
	int num = 10;
	int ref = num;

	cout << "num = " << num << endl;
	cout << "ref = " << ref << endl;

	ref = 100;

	cout << "num = " << num << endl;
	cout << "ref = " << ref << endl;

	cout << "&num = " << &num << endl;
	cout << "&ref = " << &ref << endl;

	return 0;
}
