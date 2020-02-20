/** lab12.c
Author: Zach Lindler
Lecture, Lab Section: 002, 006
Lab #: Lab 05
Submitted on: 11/30/2018
Purpose: This program takes a range of numbers and returns whether the number is
perfect, deficient, or abundant.
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
#include <stdlib.h>
#include <string.h>

typedef struct {
  int lineNum;
  int sum;
  char result[];
}lineStruct;

int calculateDivisiors(int num);

int main(int argc, char *argv[]){

  if(argc!=4){
    fprintf(stderr, "\nYou need 4 arguments!\n");
    return 1;
  }

  int x=atoi(argv[1]);
  int y=atoi(argv[2]);
  if(x<2){
    fprintf(stderr,"You need X to be greater than or equal to 2!\n");
    return 1;
  }
  if(y<=x){
    fprintf(stderr,"Y should be greater than X!\n");
    return 1;
  }
  char chr;
  sscanf(argv[3],"%c",&chr);
  lineStruct *lineInfo=(lineStruct*) malloc((y-x+1)*sizeof(lineStruct));

  for(int i=x;i<=y;++i){
    lineInfo[i-x].lineNum=i;
    lineInfo[i-x].sum=calculateDivisiors(i);
    if(lineInfo[i-x].sum==i){
      snprintf(lineInfo[i-x].result,10,"%s","Perfect");
    }
    else if (lineInfo[i-x].sum>i){
      snprintf(lineInfo[i-x].result,10,"%s","Abundant");
    }
    else{
      snprintf(lineInfo[i-x].result,10,"%s","Deficient");
    }
  }

  for(int i=0;i<=(y-x);++i){
    printf("%4d is %-10s", lineInfo[i].lineNum,lineInfo[i].result);
    for(int j=0;j<lineInfo[i].sum;++j){
      printf("%c",chr);
    }
    printf("\n");
  }
  free(lineInfo);
  return 0;
}

int calculateDivisiors(int num){
  int sum=0;
  for(int i=1;i<num;i++){
    if(num%i==0){
      sum+=1;
    }
  }
  return sum;
}
