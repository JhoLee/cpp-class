// DynamicArray.cpp
#include <iostream>
using namespace std;

int main() {
	
	int num;
	cout << "������ ������ �Է��ϼ��� : ";
	cin >> num;

	int *data = new int[num];		// ���� �޸� �迭�� �Ҵ�
	if (data == NULL) {

		cout << "���� �޸� �迭 �Ҵ� ���� \n";
		return 1;
	}

	cout << num << "���� ������ �Է��ϼ��� : ";
	for (int i = 0; i < num; i++) {
		cin >> data[i];
	}

	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += data[i];
	}

	double average = (double)sum / (double)num;
	cout << "�迭�� �հ� : " << sum << ", �迭�� ��� : "
		<< average << "\n";

	delete[] data;				// ���� �޸� �迭�� ����
	data = NULL;

	return 0;
}