#include <iostream>
using namespace std;

int main() {
	int arr[10];
	int sum = 0;

	cout << "10���� ������ �Է��ϼ��� : ";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	double average = double(sum) / 10;
	cout << "�迭�� ���� : ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";

	}
	cout << "\n�հ� : " << sum << " \n��� : " << average << "\n";

	return 0;
}