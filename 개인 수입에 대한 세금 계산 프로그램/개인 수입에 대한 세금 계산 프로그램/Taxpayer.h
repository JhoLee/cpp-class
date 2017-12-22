/*
* Author: 1626035
* File: Taxpayer.h
* Date: 17.11.16
*
*/




#ifndef TAXPAYER_H
#define TAXPAYER_H

class Taxpayer {
protected:
	int monthlyIncome;
	int grade;
	int maxValue;
	int tax_sum;

	int result_data[3][5]; 
	const static enum LABEL { AMMOUNT, RATE, TAX };
	const static enum TAXRATE_STANDARD { _0TO50 = 1, _50TO100, _100TO200, _200TO };

	void set_rate();
	int compute_tax();
	
	int ammount[5];
	int rate[5];
	int tax[5];

public:
	

	void set_monthlyIncome(int);
	void set_grade(int);

	void set_maxValue();

	Taxpayer();
	Taxpayer(int, int); // Grade, Income


	static void print_result(Taxpayer);

	void set_data();

};

#endif`