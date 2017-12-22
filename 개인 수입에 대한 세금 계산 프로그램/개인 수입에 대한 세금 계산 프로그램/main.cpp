/*
 * Author: 1626035
 * File: Main.cpp
 * Date: 17.11.16
 *
 */


#include <iostream>
#include "Taxpayer.h"

using namespace std;



int main() {
	
	/* Generate Obj. Taxpayer */
	Taxpayer person;
	person.set_data();

	/* */

	Taxpayer::print_result(person);

	return 0;
	
}