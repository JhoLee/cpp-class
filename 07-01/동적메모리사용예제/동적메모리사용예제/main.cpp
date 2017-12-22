#include <iostream>
using namespace std;

int main() {
	int *data = NULL;
	int num;
	cout << "데이터의 개수를 입력하세요: ";
	cin >> num;

	data = new int[num];
	for (int i = 0; i < num; i++) {
		data[i] = rand() % 100;
	}

	cout << "생성된 데이터: ";
	for (int i = 0; i < num; i++) {
		cout << data[i] << " ";
		
	}
	cout << "\n";

	delete data;
	data = NULL;

	return 0;
}