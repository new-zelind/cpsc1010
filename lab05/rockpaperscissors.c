/** rockpaperscissors.c
Author: Zach Lindler 
Lecture, Lab Section: 002, 006
Lab #: Lab 05
Submitted on: 9/27/2018
Purpose: This program simulates a game, or multiple games, of rock, paper, scissors, and keeps track of wins, losses, and draws. 
Academic Honesty Declaration: The following code represents my own work and I have neither received norgiven assistance that violates the collaboration policy posted with this assignment. I have notcopied or modified codefrom any other source other than the labassignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011. I acknowledge that this lab assignment is basedupon an assignment created byClemson University and that any publishing or posting of this code is prohibited unless I receive written permissionfrom Clemson University.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int numMatches;
	int i;
	int inputValid;
	char playerChoice;
	int playerNum;
	int compNum;
	int compWins = 0;
	int playerWins = 0;
	int ties = 0;
	
	//Player enters the number of matches, and is saved into numMatches.
	printf("\nStarting the CPSC 1011 Rock, Paper, Scissor Game!\n\n");
	printf("Enter number of matches to play: ");
	scanf("%d",&numMatches);
	
	//Begin the matches
	//Determine the user's choice
	for (i=0;i<numMatches;++i) {
		inputValid = 0;
		while (inputValid == 0) {							//Input validation loop
			printf("\n\n\tMatch %d: Enter R for Rock, P for Paper, or S for Scissors: ", i+1);
			scanf(" %c",&playerChoice);
			if (playerChoice == 'R') {						//Assigns 0 in the place of Rock
				playerNum = 0;
				inputValid = 1;
			}
			
			else if (playerChoice == 'P') {					//Assigns 1 in the place of Paper
				playerNum = 1;
				inputValid = 1;
			}
			
			else if (playerChoice == 'S') {					//Assigns 2 in the place of Scissors
				playerNum = 2;
				inputValid = 1;
			}
		}
		
		//Random number generation for the computer's throw
		srand(time(0));
		compNum = rand() %3;
		
		//Determining the result
		if (playerNum == 0) {											//Player chose rock
			if (compNum == 0) {
				ties++;
				printf("\tThe computer chose rock. You tied.\n");		//Computer chose rock. Tie game.
			}
			
			else if (compNum == 1) {
				compWins++;
				printf("\tThe computer chose paper. You lose.\n");		//Computer chose paper. Computer wins.
			}
			
			else if (compNum == 2) {
				playerWins++;
				printf("\tThe computer chose scissors. You win!\n");	//Computer chose scissors. Player wins.
			}
		}
		else if (playerNum == 1) {										//Player chose paper.
			if (compNum == 0){
				playerWins++;
				printf("\tThe computer chose rock. You win!\n");		//Computer chose rock. Player wins.
			}
			
			else if (compNum == 1) {
				ties++;
				printf("\tThe computer chose paper. You tied.\n");		//Computer chose paper. Tie game.
			}
			
			else if (compNum == 2) {
				compWins++;
				printf("\tThe computer chose scissors. You lose.\n");	//Computer chose scissors. Computer wins.
			}
		}
		else if (playerNum == 2) {										//Player chose scissors.
			if (compNum == 0) {
				compWins++;
				printf("\tThe computer chose rock. You lose.\n");		//Computer chose rock. Computer wins.
			}
			
			else if (compNum == 1) {
				playerWins++;
				printf("\tThe computer chose paper. You win!\n");		//Computer chose paper. Player wins.
			}
			
			else if (compNum == 2) {
				ties++;
				printf("\tThe computer chose scissors. You tied.\n");	//Computer chose scissors. Tie game.
			}
		}
		
		//Print a summary of the games so far.
		printf("\tScores:\tYou-%d\tComputer-%d",playerWins, compWins);
		if (ties >=1) {
			printf("\tTies:%d\n\n",ties);
		}
	}
	
	//Print a summary of the games to the user.
	printf("\nThe game of 3 matches is complete. The final scores are:\n");
	printf("You:\t\t%d\n", playerWins);
	printf("Computer:\t%d\n", compWins);
	printf("Ties:\t\t%d\n\n", ties);
	
	return 0;
}
			
	
	
