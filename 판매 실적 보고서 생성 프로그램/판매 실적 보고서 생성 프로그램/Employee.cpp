#include "Employee.h"

Employee::Employee() {
	number = -1;
	for (int perform : performance) {
		perform = 0;
	}
}

Employee::Employee(int num) {
	number = num;
	for (int perform : performance) {
		perform = 0;
	}
}

void Employee::setNumber(int num) {
	number = num;
}


int Employee::getNumber() {
	return number;
}

void Employee::setPerformance(int order, int perform) {
	performance[order] = perform;
}

int Employee::getPerformance(int order) {
	return performance[order];
}

