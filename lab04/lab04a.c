/*
* lab04a.c
* Author: Zach Lindler
* Lecture, Lab Section: 002, 006
* Lab #: Lab 04
* Submitted on: 09/20/2018
*
* Purpose: This program prompts the user to input a magic square, then checks to
see if the solutoion is valid.
*
* Academic Honesty Declaration:
* The following code represents my own work and I have neither received
nor given assistance that violates the collaboration policy posted with
this assignment. I have not copied or modified code from any other source
other than the lab assignment, course textbook, or course lecture slides.
Any unauthorized collaboration or use of materials not permitted will be
subjected to academic integrity policies of Clemson University and CPSC
1010/1011.
*
* I acknowledge that this lab assignment is based upon an assignment
created by Clemson University and that any publishing or posting of this
code is prohibited unless I receive written permission from Clemson
University.
*/

#include <stdio.h>

int main() {
	int topLeft;
	int topCent;
	int topRight;
	int midLeft;
	int midCent;
	int midRight;
	int botLeft;
	int botCent;
	int botRight;
	int row1Sum;
	int row2Sum;
	int row3Sum;
	int col1Sum;
	int col2Sum;
	int col3Sum;
	int diag1Sum;
	int diag2Sum;
	int isError;

	//Prompt the user to enter the values, then store the values based on their location.
	printf("Enter in the values: ");
	scanf("%d %d %d %d %d %d %d %d %d", &topLeft, &topCent, &topRight, &midLeft, &midCent, &midRight, &botLeft, &botCent, &botRight);

	//Display the values to the user as a square.
	printf("\nYou entered:\n");
	printf("%d %d %d\n", topLeft, topCent, topRight);
	printf("%d %d %d\n", midLeft, midCent, midRight);
	printf("%d %d %d\n", botLeft, botCent, botRight);
	printf("\nAnalyzing...\n");

	//Calculate if the magic square works or not
	//Rows:
	row1Sum = topLeft + topCent + topRight;
	if (row1Sum != 15) {
		printf("[%d, %d, %d] does not work!\n", topLeft, topCent, topRight);
		isError = 1;
	}
	row2Sum = midLeft + midCent + midRight;
	if (row2Sum != 15) {
		printf("[%d, %d, %d] does not work!\n", midLeft, midCent, midRight);
		isError = 1;
	}
	row3Sum = botLeft + botCent + botRight;
	if (row3Sum != 15) {
		printf("[%d, %d, %d] does not work!\n", botLeft, botCent, botRight);
		isError = 1;
	}

	//Columns:
	col1Sum = topLeft + midLeft + botLeft;
	if (col1Sum != 15) {
		printf("Column 0 does not work!\n");
		isError = 1;
	}
	col2Sum = topCent + midCent + botCent;
	if (col2Sum != 15) {
		printf("Column 1 does not work!\n");
		isError = 1;
	}
	col3Sum = topRight + midRight + botRight;
	if (col3Sum != 15) {
		printf("Column 2 does not work!\n");
		isError = 1;
	}

	//Diagonals:
	diag1Sum = topLeft + midCent + botRight;
	if (diag1Sum != 15) {
		printf("Diagonal [%d, %d, %d] does not work!\n", topLeft, midCent, botRight);
		isError = 1;
	}
	diag2Sum = botLeft + midCent + topRight;
	if (diag2Sum != 15) {
		printf("Diagonal [%d, %d, %d] does not work!\n", botLeft, midCent, topRight);
		isError = 1;
	}

	//Final statement:
	if (isError == 1) {
		printf("\nThis is not a magic square!\n\n");
	}
	else {
		printf("\nThis is a magic square!\n\n");
	}

	return 0;
}
