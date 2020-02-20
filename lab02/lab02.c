/* Zach Lindler
   09/04/2018
   CPSC 1010 sec 2; 1011 sec 6
   This is a program used to convert miles to kilometers.
   The user will input a number of miles and the program will output the distance in kilometers. */

#include <stdio.h> 	   //Added the missing the period in "stdio.h"
			   //Each line in the code was not tabbed over correctly.
int main (void) {   	   //Added the missing {.
	double kilometers; //Whitespace inconsistency: this line was tabbed over too far.
	int miles;	   

	// Read input from the user
	printf("\nPlease enter the distance in miles: "); //The \n from the previous line was added.
	scanf("%d", &miles);				  //Added missing " before the &d; also replaced : with ; at end of statment.
	printf("\n");					  //Changed command from "print" to "printf".

	// Calculate distance in kilometers from miles
	kilometers = 1.610 * miles;			  //Changed to the correct conversion factor.

	// Print the distances
	printf("%d miles is equal to ", miles); //Removed unneccessary % in the middle of the printf statment.
	printf("%.2f kilometers", kilometers);  //Missing ; at end of statement; also removed the &.
	printf("\n\n");

	return 0;
}
