#include <iostream>
#include <cstdlib>
#include <ctime>
#define ROW 5
#define COL 5
using namespace std;


int main() {
	srand((unsigned int)time(NULL));


	/* �����޸� �Ҵ� */
	int **data = new int *[ROW];
	if (data == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return 1;
	}
	for (int i = 0; i < ROW; i++) {
		data[i] = new int[COL];
		if (data[i] == NULL) {
			cout << "�޸� �Ҵ� ����" << endl;
			return 1;
		}
	}

	int *vSum, *hSum;
	double *vAvg, *hAvg;
	vSum = new int[ROW];
	if (vSum == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return 1;
	}
	
	hSum = new int[COL];
	if (hSum == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return 1;
	}
	
	vAvg = new double[ROW];
	if (vAvg == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return 1;
	}
	hAvg = new double[COL];
	if (hAvg == NULL) {
		cout << "�޸� �Ҵ� ����" << endl;
		return 1;
	}

	/* data processing */
	for (int i = 0; i < ROW; i++) {
		vSum[i] = 0;
		hSum[i] = 0;
		for (int j = 0; j < COL; j++) {
			// input data
			data[i][j] = (rand() % 5) + 1;

		}

	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			/* vertical sum */
			vSum[j] += data[i][j];

			/* horizontal sum */
			hSum[i] += data[i][j];
		}
	}
	/* Calculate vertical average */
	for(int i=0; i<COL; i++) {
		vAvg[i] = (double)vSum[i] / ROW;
	}

	/* Calculate horizontal average */
	for (int i = 0; i < ROW; i++) {
		hAvg[i] = (double)hSum[i] / COL;
	}


	/* print */
	cout << "<���� ������>" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << data[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "\t��\t���" << endl;
	for (int i = 0; i < ROW; i++) {
		cout << i+1 << "��\t" << hSum[i] << "\t" << hAvg[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < COL; i++) {
		cout << i + 1 << "��\t" << vSum[i] << "\t" << vAvg[i] << endl;
	}

	cout << endl;



	/* �����޸� �Ҵ� ���� */
	for (int i = 0; i < ROW; i++) {
		delete data[i];
		data[i] = NULL;
	}
	delete data;
	data = NULL;
	delete vSum;
	vSum = NULL;
	delete hSum;
	hSum = NULL;
	delete vAvg;
	vAvg = NULL;
	delete hAvg;
	hAvg = NULL;

	/* EoP */
	return 0;
}