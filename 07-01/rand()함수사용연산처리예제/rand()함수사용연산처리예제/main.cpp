#include <iostream>
#include <cstdlib>
#include <ctime>
#define ROW 5
#define COL 5
using namespace std;


int main() {
	srand((unsigned int)time(NULL));


	/* 동적메모리 할당 */
	int **data = new int *[ROW];
	if (data == NULL) {
		cout << "메모리 할당 실패" << endl;
		return 1;
	}
	for (int i = 0; i < ROW; i++) {
		data[i] = new int[COL];
		if (data[i] == NULL) {
			cout << "메모리 할당 실패" << endl;
			return 1;
		}
	}

	int *vSum, *hSum;
	double *vAvg, *hAvg;
	vSum = new int[ROW];
	if (vSum == NULL) {
		cout << "메모리 할당 실패" << endl;
		return 1;
	}
	
	hSum = new int[COL];
	if (hSum == NULL) {
		cout << "메모리 할당 실패" << endl;
		return 1;
	}
	
	vAvg = new double[ROW];
	if (vAvg == NULL) {
		cout << "메모리 할당 실패" << endl;
		return 1;
	}
	hAvg = new double[COL];
	if (hAvg == NULL) {
		cout << "메모리 할당 실패" << endl;
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
	cout << "<랜덤 데이터>" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << data[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "\t합\t평균" << endl;
	for (int i = 0; i < ROW; i++) {
		cout << i+1 << "행\t" << hSum[i] << "\t" << hAvg[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < COL; i++) {
		cout << i + 1 << "열\t" << vSum[i] << "\t" << vAvg[i] << endl;
	}

	cout << endl;



	/* 동적메모리 할당 해제 */
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