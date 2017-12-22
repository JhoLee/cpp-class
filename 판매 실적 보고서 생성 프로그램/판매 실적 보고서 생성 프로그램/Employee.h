#ifndef EMPLOYEE_H
#define EMPLOYEE_H



class Employee {

private:
	int number; // 개인 번호
	int performance[5]; // 0번째 값은 개인의 총합


public:
	Employee();
	Employee(int);
	void setNumber(int);
	int getNumber();
	void setPerformance(int, int);
	int getPerformance(int);
	const int &performanceSum = performance[0];

	


};

#endif
