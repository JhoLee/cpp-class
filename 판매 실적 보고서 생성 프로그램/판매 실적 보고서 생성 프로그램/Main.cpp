#include <iostream>
#include "Employee.h"
#include <fstream>

using namespace std;

void printResult();

int main() {
	int employee_number = 5;


	/* Make Employee variables */
	Employee *employees = new Employee[employee_number];
	for (int i = 1; i <= employee_number; i++) {
		employees[i].setNumber(i);

	}
	/* End of Making Employee Variables */

	/* Reading perfomances data */
	ifstream fin;
	fin.open("Data.txt");
	for (int i = 1; i<= employee_number; i++) {
		int performs[4];
		while (fin >> performs[1] >> performs[2] >> performs[3] >> performs[4]) {
			for (int j = 1; j <= 4; j++) {
				employees[i].setPerformance(j, performs[j]);
			}
			i++;
		}
	}	
	fin.close();
	/* End of Reading Performances Data */

	/* Computing Personal Sum*/
	for (int i = 1; i <= employee_number; i++) {
		int sum = 0;
		for (int j = 1; j <= 4; j++) {
			sum += employees[i].getPerformance(j);
		}
		employees[i].setPerformance(0, sum);
	}
	/* End of Computing Personal Sum */

	/* Computing Sum */
	Employee employee_sum = Employee(0);
	for (int i = 1; i <= 4; i++) {
		int sum = 0;
		for (int j = 1; j <= employee_number; j++) {
			sum += employees[j].getPerformance(i);
		}
		employee_sum.setPerformance(0, sum);
	}
	int allSum = 0;
	for (int i = 1; i <= 4; i++) {
		allSum += employee_sum.getPerformance(i);
	}
	employee_sum.setPerformance(0, allSum);
	/* End of Computing Sum */

	/* Computing Average */
	double *average = new double[5];
	for (int i = 0; i < 5; i++) {
		average[i] = employee_sum.getPerformance(i);
		average[i] /= (double)employee_number;
	}
	/* End of Computing Average */

	/* Computing Percentage */
	double *percentage = new double[5];
	for (int i = 1; i < 5; i++) {
		percentage[i] = employee_sum.getPerformance(i);
		percentage[i] /= employee_sum.performanceSum;
		percentage[i] *= 100;
	}
	/* End of Computing Percentage */

	/* Printing Result */
	printResult();

	/* End of Printing Result */

	
	delete[] percentage;
	percentage = NULL;
	delete[] average;
	average = NULL;
	delete[] employees;
	employees = NULL;

	
	
	/* End of main */
	return EXIT_SUCCESS;
}


void printResult() {
	cout << "============================================================" << endl;
	cout << "   " << " 판매번호 " << "   " << " 1/4분기 " << "   " << " 2/4분기 " << "   " << " 3/4분기 " << "   " << " 4/4분기 " << "  총합  " << endl;
	cout << "============================================================" << endl;
}