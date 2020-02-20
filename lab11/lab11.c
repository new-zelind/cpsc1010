/** rockpaperscissors.c
Author: Zach Lindler
Lecture, Lab Section: 002, 006
Lab #: Lab 05
Submitted on: 9/27/2018
Purpose: This program simulates a game, or multiple games, of rock, paper, scissors, and keeps track of wins, losses, and draws.
Academic Honesty Declaration: The following code represents my own work and I
have neither received nor given assistance that violates the collaboration
policy posted with this assignment. I have not copied or modified code from any
other source other than the lab assignment, course textbook, or course lecture
slides. Any unauthorized collaboration or use of materials not permitted will be
subjected to academic integrity policies of Clemson University and
CPSC 1010/1011. I acknowledge that this lab assignment is based upon an
assignment created by Clemson University and that any publishing or posting of
this code is prohibited unless I receive written permission from
Clemson University.*/

#include <stdio.h>
#include <string.h>
#include <time.h>

void selectionSort(int numberArray[], int in);
void insertionSort(int numberArray[], int in);
void bubbleSort(int numberArray[], int in);
void quickSort(int numberArray[], int in);
void writeData(int* numberArray, int in);

int main(){

  int userChoice;

  printf("Welcome to the CPSC 1011 sorting simulator.");
  printf("\nWhich data file would you like to sort?");
  printf("\n\t[1] Small file (10 items)");
  printf("\n\t[2] Medium file (100 items)");
  printf("\n\t[3] Medium file (1,000 items)");
  printf("\n\t[4] Medium file (10,000 items)");
  printf("\nEnter your choice: ");
  scanf(" %i", &userChoice);

  switch(userChoice){
    case 1:;
      break;
    case 2:;
      break;
    case 3:;
      break;
    case 4:;
      FILE *fp=fopen("a","r");
      int items[10000];
      int i=0;
      while(!feof(fp)){
        fscanf(fp,"%d, ",items+i);
        i++;
      }
      clock_t begin=clock();
      selectionSort(items,10000);
      insertionSort(items,10000);
      insertionSort(items,10000);
      bubbleSort(items,10000);
      clock_t end=clock();
      double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
      printf("%d\n", (int)(time_spent*10000));
      writeData(items,10000);
  }

  return 0;
}

void writeData(int* numberArray, int in){
  FILE *fpW=NULL;
  fpW=fopen("c","w");
  for(int i=0;i<in;i++){
    fprintf(fpW,"%d, ",numberArray[i]);
  }
  fclose(fpW);
}

void selectionSort(int numberArray[], int in){
  int i=0,j=0;
  int temp=0;
  int indexSmallest=0;
  for(i=0;i<in;i++){
    indexSmallest=i;
    for(j=i+1;j<in;j++){
      if(numberArray[j]<numberArray[indexSmallest]){
        indexSmallest=j;
      }
    }
    temp=numberArray[i];
    numberArray[i]=numberArray[indexSmallest];
    numberArray[indexSmallest]=temp;
  }
}

void insertionSort(int numberArray[], int in){
  int temp=0;
  int i=0;
  int j=0;
  for(i=1;i<in;i++){
    temp=numberArray[i];
    j=i-1;
    while(temp<numberArray[j]&&j>-0){
      numberArray[j+1]=numberArray[j];
      j--;
    }
    numberArray[j+1]=temp;
  }
}

void bubbleSort(int numberArray[], int in){
  int i=0,j=0;
  int temp=0;
  for(i=1;i<in;i++){
    for(int j=0;j<(in-i-1);j++){
      temp=numberArray[j];
      numberArray[j]=numberArray[j+1];
      numberArray[j+1]=temp;
    }
  }
}

void quickSort(int numberArray[], int in){
  int pivot=0;
  int i=0,j=0;
  int temp=0;
  if(low<high){
    pivot=low;
    i=low;
    j=high;
    while(i<j){
      while(numberArray[i]<=numberArray[pivot]&&i<=high){
        i++;
      }
      while(numberArray[j]>numberArray[pivot]&&j>=low){
        j--;
      }
      if(i<j){
        temp=numberArray[j];
        numberArray[j]=temp;
      }
    }
    temp=numberArray[j];
    numberArray[j]=numberArray[pivot];
    numberArray[pivot]=temp;
    quickSort(low,numberArray);
    quickSort(high,numberArray);
  }
}
