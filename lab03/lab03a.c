/*
* lab03a.c
* Author: Zach Lindler
* CPSC 1010-001, CPSC 1011-006
* Lab #: 3A
* Submitted on: 09/13/2018
*
* Purpose: The purpose of this code is to calculate gross pay based off of hours worked in a week,
* and calculate the Federal, State, FICA, and Medicare taxes taken off. This program will also report
* the net pay for that week.
*
* Academic Honesty Declaration:
* The following code represents my own work and I have neither received nor
* given assistance that violates the collaboration policy posted with this assignment.
* I have not copied or modified code from any other source other than the lab
* assignment, course textbook, or course lecture slides. Any unauthorized
* collaboration or use of materials not permitted will be subjected to academic
* integrity policies of Clemson University and CPSC 1010/1011.
* I acknowledge that this lab assignment is based upon an assignment
created by
* Clemson University and that any publishing or posting of this code is
* prohibited unless I receive written permission from Clemson University.
*/

#include <stdio.h>

int main()
{
	//Define all necessary variables
	int userHours;
	double userWage = 7.25;
	double payGross;
	double payNet;
	double taxFederal = 0.1;
	double taxState = 0.01402;
	double taxFica = 0.06201;
	double taxMedicare = 0.0145;
	double taxTotal;

	//Ask the user how many hours they worked during the week, and store that number
	//into the variable userHours.
	printf("Hours per week: ");
	scanf("%d", &userHours);

	//Calculate gross pay.
	payGross = userHours * userWage;

	//Calulate taxes.
	taxFederal = payGross * taxFederal;
	taxState = payGross * taxState;
	taxFica = payGross * taxFica;
	taxMedicare = payGross * taxMedicare;

	//Calculate the net pay.
	taxTotal = taxFederal + taxState + taxFica + taxMedicare;
	payNet = payGross - taxTotal;

	//Display the necessary information to the user.
	printf("\n\n\n");
	printf("Hours per week:	%d\n", userHours);
	printf("Hourly Rate:   	$%.2lf\n", userWage);
	printf("Gross Pay:     	$%.2lf\n", payGross);
	printf("Net pay:       	$%.2lf\n\n", payNet);
	printf("Deductions\n");
	printf("Federal:       	$%.2lf\n", taxFederal);
	printf("State:	       	$%.2lf\n", taxState);
	printf("FICA:	       	$%.2lf\n", taxFica);
	printf("Medicare:      	$%.2lf\n", taxMedicare);

	return 0;
}
