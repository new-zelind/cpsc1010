/*	Zach Lindler C201658043
	CPSC 1010-001
	Fizz Buzz Assignment
	9/26/2018 */

#include <stdio.h>

int main() {
	int userNum;
	int i;
	int currentNum;
	int fizz;
	int buzz;
	int fizzbuzz;
	
	printf("Enter an integer from 1 to 100: ");
	scanf(" %d", &userNum);
	printf("\n\n");
	for (i=0; i<userNum; ++i) {
		currentNum = i + 1;
		fizz = currentNum % 3;
		buzz = currentNum % 5;
		if (fizz == 0) {
			if (buzz == 0) {
				fizzbuzz = 3;
			}
			else {
				fizzbuzz = 1;
			}				
		}
		else if (buzz == 0) {
			if (fizz == 0) {
				fizzbuzz = 3;
			}
			else {
				fizzbuzz = 2;
			}
		}
		else {
			fizzbuzz = 0;
		}
		switch (fizzbuzz) {
			case 1:
				printf("Fizz");
				break;
			case 2:
				printf("Buzz");
				break;
			case 3:
				printf("FizzBuzz");
				break;
			default:
				printf("%d", currentNum);
				break;
		}
		printf("\n");
	}
		
	return 0;	
}
