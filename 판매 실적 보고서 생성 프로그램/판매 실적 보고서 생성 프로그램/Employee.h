#ifndef EMPLOYEE_H
#define EMPLOYEE_H



class Employee {

private:
	int number; // ���� ��ȣ
	int performance[5]; // 0��° ���� ������ ����


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
