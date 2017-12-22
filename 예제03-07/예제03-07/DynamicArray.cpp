// DynamicArray.cpp
#include <iostream>
using namespace std;

int main() {
	
	int num;
	cout << "정수의 개수를 입력하세요 : ";
	cin >> num;

	int *data = new int[num];		// 동적 메모리 배열의 할당
	if (data == NULL) {

		cout << "동적 메모리 배열 할당 실패 \n";
		return 1;
	}

	cout << num << "개의 정수를 입력하세요 : ";
	for (int i = 0; i < num; i++) {
		cin >> data[i];
	}

	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += data[i];
	}

	double average = (double)sum / (double)num;
	cout << "배열의 합계 : " << sum << ", 배열의 평균 : "
		<< average << "\n";

	delete[] data;				// 동적 메모리 배열의 해제
	data = NULL;

	return 0;
}