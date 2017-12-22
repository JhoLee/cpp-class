/*
* Author: 1626035
* File: Taxpayer.cpp
* Date: 17.11.16
*
*/

#include <iostream>
#include "Taxpayer.h"

using namespace std;

Taxpayer::Taxpayer() {
	monthlyIncome = 0;
	grade = 0;
	maxValue = 0;
	tax_sum = 0;
}

Taxpayer::Taxpayer(int income, int grade) {
	monthlyIncome = income;
	this->grade = grade;
}

void Taxpayer::set_data() {
	int income, grade;
	do {
		cout << "월 수입액 입력 >> ";
		cin >> income;
		if (income > 0)
			break;
		else
			cout << "옳지 않은 금액입니다.. " << endl;
	} while (true);
	cout << endl;

	do {
		cout << "다음에 따라 등급 입력.." << endl;
		cout << "생활보호대상자(1) 국가유공자(2) 일반(3) >> ";

		cin >> grade;
		if (grade >= 1 && grade <= 3)
			break;
		else
			cout << "옳지 않은 등급입니다.. " << endl;
	} while (true);
	cout << endl;

	set_monthlyIncome(income);
	set_grade(grade);

	set_rate();
	set_maxValue();
	tax_sum = compute_tax();
}

void Taxpayer::set_rate() {
	switch (grade) {

	case 1:
		// 생활보호대상자
		rate[_0TO50] = 3;
		rate[_50TO100] = 3;
		rate[_100TO200] = 6;
		rate[_200TO] = 6;
		break;

	case 2:
		// 국가유공자
		rate[_0TO50] = 3;
		rate[_50TO100] = 3;
		rate[_100TO200] = 6;
		rate[_200TO] = 8;
		break;

	case 3:
		// 일반
		rate[_0TO50] = 3;
		rate[_50TO100] = 6;
		rate[_100TO200] = 8;
		rate[_200TO] = 11;
		break;
	}

}

int Taxpayer::compute_tax()
{
	int tax_sum = 0;
	int temp = monthlyIncome;

	switch (maxValue) {

	case _200TO:
		// 100 <= x < 200
		ammount[_200TO] = temp - 200.0 * pow(10, 4);
		temp -= ammount[_200TO];


	case _100TO200:
		ammount[_100TO200] = temp - 100.0 * pow(10, 4);
		temp -= ammount[_100TO200];

		if (rate[_100TO200] == rate[_100TO200 + 1]) {
			ammount[_100TO200] += ammount[_100TO200 + 1];
			ammount[_100TO200 + 1] = 0;
		}

	case _50TO100:
		ammount[_50TO100] = temp - 50 * pow(10, 4);
		temp -= ammount[_50TO100];

		if (rate[_50TO100] == rate[_50TO100 + 1]) {
			ammount[_50TO100] += ammount[_50TO100 + 1];
			ammount[_50TO100 + 1] = 0;
		}

	case _0TO50:
		ammount[_0TO50] = temp;
		temp -= ammount[_0TO50];

		if (rate[_0TO50] == rate[_0TO50 + 1]) {
			ammount[_0TO50] += ammount[_0TO50 + 1];
			ammount[_0TO50 + 1] = 0;
		}

	default:
		for (int i = _0TO50; i <= _200TO; i++) {
			tax[i] = ammount[i] * (rate[i] * pow(10, -2));
			tax_sum += tax[i];
		}

		break;
	}

	return tax_sum;
}

void Taxpayer::set_monthlyIncome(int income) {
	monthlyIncome = income;


}

void Taxpayer::set_grade(int grade) {
	this->grade = grade;
}

void Taxpayer::set_maxValue() {
	if (monthlyIncome < 50 * pow(10, 4))
		maxValue = _0TO50;
	else if (monthlyIncome < 100 * pow(10, 4))
		maxValue = _50TO100;
	else if (monthlyIncome < 200 * pow(10, 4))
		maxValue = _100TO200;
	else
		maxValue = _200TO;
}

void Taxpayer::print_result(Taxpayer person) {
	/* 출력양식은 다음과 같음 */
	//	********************************************			//
	//	월 수입액 : 2200000         등 급 : 3					//
	//	********************************************			//
	//	금액            	세율           	 세금				//
	//	--------------------------------------------			//
	//	500000       	2 %					10000				//
	//	500000       	5 %					25000				//
	//	1000000     	7 %					70000				//
	//	200000       	10 %				20000				//
	//	--------------------------------------------			//
	//	총 세금 : 125000원										//
	//	실수령액 : 2075000원									//
	//	============================================			//
	/********/

	cout << endl;
	cout << "********************************************" << endl;
	cout << "월 수입액: " << person.monthlyIncome << "\t\t";
	cout << "등급 : " << person.grade << endl;
	cout << "********************************************" << endl;
	cout << "금액" << "\t\t" << "세율" << "\t\t" << "세금" << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = _0TO50; i <= _200TO; i++) {
		if (person.ammount[i] != 0) {
			cout << person.ammount[i] << "\t\t";
			cout << person.rate[i] << "%\t\t";
			cout << person.tax[i] << endl;
		}
	}
	cout << "--------------------------------------------" << endl;
	cout << "총 세금: " << "\t\t\t" << person.tax_sum << "원" << endl;
	cout << "실수령액: " << "\t\t\t" << person.monthlyIncome - person.tax_sum << "원" << endl;
	cout << "============================================" << endl;

}