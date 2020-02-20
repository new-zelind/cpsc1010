/*
* binaryconverter.c
* Author: Zach Lindler
* Lecture, Lab Section: 002,006
* Lab #: 06
* Submitted on: 10/06/2018
*
* Purpose: This program converts base-10 numbers to base-2 binary numbers.
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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
	
	int isLoop;
	char userNum[64];
	int userNum2;
	int compNum;
	int binArray[64];
	int i = 0;
	int j;
	int k;
	
	printf("\nStarting the CPSC 1011 Decimal to Binary Converter!\n\n");
	while (1==1)
	{
		isLoop = 0;
		while (isLoop == 0)
		{
			//Enter the number, saved as a character string for validation.
			printf("Please enter a positive whole number (or EOF to quit): ");
			scanf("%s", userNum);
			if (feof(stdin)) 							//Checks for the EOF command
			{
				isLoop = 2;
			}
			else
			{
				if (strstr(userNum, ".")) 	//Checks to see if there is a "." in the string.
				{
					printf("\n\tSorry, this is not a positive whole number.\n\n");
					isLoop = 0;
				}
				else
				{
					userNum2=atoi(userNum);		//Converts the string to a number.
					if (userNum2<0)
					{
						printf("\n\tSorry, this is not a positive whole number.\n\n");
						isLoop = 0;
					}
					else
					{
						if (userNum2==0)					//Checks for letter characters.
						{
							printf("\n\tSorry, this is not a positive whole number.\n\n");
							isLoop = 0;
						}
						else
						{
							isLoop = 1;
						}
					}
				}
			}			
		}
		
		//Binary conversion
		if (isLoop == 1)
		{
			compNum = userNum2;
			i = 0;
			for (k=0;k<64;++k) 	//Clears the array, setting each value to 0.
			{
				binArray[k]=0;
			}
			while (compNum > 0)	//Converts to binary, recording each value in the binary array.
			{
				binArray[i]=compNum % 2;
				compNum = compNum / 2;
				++i;
			}
			//Print the results
			printf("\n\t %d (base-10) is equivalent to ", userNum2);
			for (j=i-1;j>=0;j--)
			{
				printf("%d", binArray[j]);
			}
			printf(" (base-2)!\n\n");
		}
	}
	printf("Thank you for using the CPSC 1011 Decimal to Binary Generator. Goodbye!");
		

	return 0;
}
