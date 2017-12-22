#include <iostream>
using namespace std;

int main() {
	int arr[10];
	int sum = 0;

	cout << "10개의 정수를 입력하세요 : ";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	double average = double(sum) / 10;
	cout << "배열의 내용 : ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";

	}
	cout << "\n합계 : " << sum << " \n평균 : " << average << "\n";

	return 0;
}