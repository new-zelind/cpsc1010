/*
* example2.c
* Author: Zach Lindler
* Lecture, Lab Section: 001,006
* Lab #: 10
* Submitted on: 11/01/2018
*
* Purpose: This program creats an array of values, then determines if the number
* 11 exists within that array. It also prints the first value of two different
* arrays using pointers.
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

void Find11 ();
void PointersAreFun();

int main( void ) {
    Find11();           //Prints the table, then returns the location of "11" in the table, if it exists
    PointersAreFun();   //Returns the first value of two different int arrays
    return 0;
}

void Find11 (void){
    int i = 0, count = 0, search = 1, found = 0;
    int number = 5;
    int table[10];

    //Print the first value of the table
    table[0] = number;
    printf( "table[%i]: %i\n", count, table[count] );

    //Calculates the table's values, then prints them to the user
    count = 1;
    while( count < 10 ) {
        table[count] = (number++) * 2;  //Added parenthesis around number++ calculation
        printf( "table[%i]: %i\n", count, table[count] );
        count++;
    }

    //Detects the presence of "11" in the table
    while( search == 1 ) {    //Corrected to logical statement "==" instead of "="
        if( table[i++] == 11 ) {
            search = 0;
            found = i + 1;    //Changed to i+1 for proper location calculation
        }
        if( count == i ) {
            search = 0;
        }
    }

    //If "11" is found, print the location to the user; otherwise, print to the user that 11 is not in the table.
    if(found==i+1){ //Added logic and braces
      printf( "The number 11 is in the table at location: %d\n", found );
    }
    else{           //Added braces
      printf( "The number 11 is not in the table.\n" );
    }
}

//Given two arrays, this function prints the values of the first variable for two separate arrays.
void PointersAreFun(){
    puts("\nDemo on Pointers!\n");

    int myArray [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int anotherArray [10] = {10, 11, 12};
    int * ptrArray = NULL;
    int * ptrAnotherArray = NULL;

    //Assigns the pointer to the first value of each array
    ptrArray = myArray;
    ptrAnotherArray=anotherArray; //Added the same assignment for prtAnotherArray

    //Dereferences the pointer, then prints the first value to the user.
    printf("The first value of the array is %d\n", *ptrArray);
    printf("The first value of the second array is %d\n", *ptrAnotherArray);


}
