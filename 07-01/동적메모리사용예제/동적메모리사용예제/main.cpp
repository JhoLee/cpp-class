#include <iostream>
using namespace std;

int main() {
	int *data = NULL;
	int num;
	cout << "�������� ������ �Է��ϼ���: ";
	cin >> num;

	data = new int[num];
	for (int i = 0; i < num; i++) {
		data[i] = rand() % 100;
	}

	cout << "������ ������: ";
	for (int i = 0; i < num; i++) {
		cout << data[i] << " ";
		
	}
	cout << "\n";

	delete data;
	data = NULL;

	return 0;
}