/*
 * �й� / ����(3��)���� / �հ� /  ��� /  ��� /  ����
 */


#include <iostream>
#include <iomanip>
#define NUM_STUDENT 4
#define NUM_SUBJECT 3

using namespace std;

int main() {

	/* Start of Deallocating Memory */
	// Student's ID
	int *id = new int[NUM_STUDENT];
	if (id == NULL) {
		cout << "�޸� �Ҵ� ����! ����.. ";
		return 1;
	}

	// Array for arrays of scores
	int **score = new int *[NUM_STUDENT];
	if (score == NULL) {
		cout << "�޸� �Ҵ� ����! ����.. ";
		return 1;
	}


	for (int i = 0; i < NUM_STUDENT; i++) {
		// �� �л� ���� ������, ������ ����ŭ �Ҵ�
		score[i] = new int[NUM_SUBJECT];
		if (score[i] == NULL) {
			cout << "�޸� �Ҵ� ����! ����.. ";
			return 1;
		}
	}

	// Score Sum
	int *sum = new int[NUM_STUDENT];
	if (sum == NULL) {
		cout << "�޸� �Ҵ� ����! ����.. ";
		return 1;
	}

	// Score Average
	double *average = new double[NUM_STUDENT];
	if (average == NULL) {
		cout << "�޸� �Ҵ� ����! ����.. ";
		return 1;
	}

	// Grade
	char *grade = new char[NUM_STUDENT];
	if (grade == NULL) {
		cout << "�޸� �Ҵ� ����! ����.. ";
		return 1;
	}

	// Rank
	int *rank = new int[NUM_STUDENT];
	if (rank == NULL) {
		cout << "�޸� �Ҵ� ����! ����...";
		return 1;
	}

	/* End of Deallocating Memory */

	/* Start of Receiving Data */
	for (int i = 0; i < NUM_STUDENT; i++) {
		cout << "<" << (i + 1) << "��° �л��� ����>" << endl;
		cout << "�й� : ";
		cin >> id[i];
		cout << "(1) Java (2) C++ (3) MySQL" << endl;
		for (int j = 0; j < NUM_SUBJECT; j++) {
			cout << (j + 1) << "��° ������ ���� : ";
			cin >> score[i][j];
		}
		cout << endl;
	}
	cout << endl;

	/* End of Receiving Data */


	/* Start of Calculating 'Sum', 'Avaerage' */
	for (int i = 0; i < NUM_STUDENT; i++) {
		sum[i] = 0;
		for (int j = 0; j < NUM_SUBJECT; j++) {
			sum[i] += score[i][j];
		}
		average[i] = sum[i] / NUM_SUBJECT;
	}
	/* End of Calculating 'Sum', 'Average' */

	/* Start of Grading */
	for (int i = 0; i < NUM_STUDENT; i++) {
		if (average[i] > 90)
			grade[i] = 'A';
		else if (average[i] > 80)
			grade[i] = 'B';
		else if (average[i] > 70)
			grade[i] = 'C';
		else if (average[i] > 60)
			grade[i] = 'D';
		else
			grade[i] = 'F';
	}
	/* End of Grading */

	/* Start of Ranking */
	for (int i = 0; i < NUM_STUDENT; i++) {
		rank[i] = 0;
		for (int j = 0; j < NUM_STUDENT; j++) {
			if (sum[i] < +sum[j])
				rank[i]++;

		}
	}
	/* End of Ranking */

	/* Start of Printing Result */
	
	// Printing 'ID'
	cout << setw(13) <<"�й�";
	for (int i = 0; i < NUM_STUDENT; i++) {
		cout << setw(13) << id[i];
	}
	cout << endl;

	// Printing 'Scores'
	for (int j = 0; j < NUM_SUBJECT; j++) {
		cout << (j + 1)  << "�� ���� ����";
		for (int i = 0; i < NUM_STUDENT; i++) {
			cout << setw(13) << score[i][j];
		}
		cout << endl;
	}

	// Printing 'Sum'
	cout << setw(13) << "������ ����";
	for (int i = 0; i < NUM_STUDENT; i++) {
		cout << setw(13) << sum[i];
	}
	cout << endl;

	// Printing 'Average'
	cout << setw(13) << "������ ���";
	for (int i = 0; i < NUM_STUDENT; i++) {
		cout << setw(13) << average[i];
	}
	cout << endl;

	// Printing 'Grade'
	cout << setw(13) << "���";
	for (int i = 0; i < NUM_STUDENT; i++) {
		cout << setw(13) << grade[i];
	}
	cout << endl;

	// Printing 'Rank'
	cout << setw(13) << "����";
	for (int i = 0; i < NUM_STUDENT; i++) {
		cout << setw(13) << rank[i] + 1;
	}
	cout << endl;

	/* End of Printing Result */



	/* Start of Deallocating Memory */
	delete rank;
	delete grade;
	grade = NULL;
	delete average;
	average = NULL;
	delete sum;
	sum = NULL;
	for (int i = 0; i < NUM_SUBJECT; i++) {
		delete[] score[i];
		score[i] = NULL;
	}
	delete score;
	score = NULL;
	delete id;
	id = NULL;

	/* End of Deallocating Memory */

}
