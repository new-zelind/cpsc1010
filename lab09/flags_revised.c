/*
* flags_revised.c
* Author: Zach Lindler
* Lecture, Lab Section: 001,006
* Lab #: 09
* Submitted on: 10/26/2018
*
* Purpose: This program creates the flags of Poland, the Netherlands, Italy, and
Benin as .ppm files.
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

// Define structs
typedef struct pixel{
	int r;
	int g;
	int b;
} pixel;

typedef struct image{
	int width;
	int height;
	int country_code;
} image;
// Creates a header with the desired width and height.
void make_ppm_header (image img) {
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d %d\n", img.width, img.height, 255);
}

// Creates a pixel with the colors you tell it to use when you call it
void make_pixel (pixel pix) {
	fprintf(stdout, "%c%c%c", pix.r, pix.g, pix.b);
}

// Calculates height
int calculate_height(int width, int country_code){
	image img;
	int height;
	if (country_code == 1) {	//France's proportions
		height = 5 * (width/8);
	}
	else {
		height = 2 * (width/3);	//Other flags
	}
	img.height=height;
	return img.height;
}

// Creates a pixel struct of the correct color
pixel get_color(int column, int row, image img){
	pixel pix;
	switch(img.country_code){
		//France
		case 1:
			if(row>=img.height/2){
				pix.r=220;
				pix.g=20;
				pix.b=0;
			}
			else{
				pix.r=225;
				pix.g=225;
				pix.b=225;
			}
			break;
		//Netherlands
		case 2:
			if(row<=img.height/3) {
				pix.r=174;
				pix.g=28;
				pix.b=40;
			}
			else if(row>img.height/3 && row<=2*(img.height/3)) {
				pix.r=255;
				pix.g=255;
				pix.b=255;
			}
			else {
				pix.r=33;
				pix.g=70;
				pix.b=139;
			}
			break;
		//Italy
		case 3:
			if(column<=img.width/3) {
				pix.r=0;
				pix.g=140;
				pix.b=69;
			}
			else if(column>img.width/3 && column<=2*(img.width/3)) {
				pix.r=244;
				pix.g=245;
				pix.b=240;
			}
			else {
				pix.r=205;
				pix.g=33;
				pix.b=42;
			}
			break;
		//Benin
		case 4:
			if(column<(img.width/16)*5){
				pix.r=0;
				pix.g=170;
				pix.b=0;
			}
			else{
				if(row>=img.height/2){
					pix.r=255;
					pix.g=0;
					pix.b=0;
				}
				else{
					pix.r=255;
					pix.g=255;
					pix.b=0;
				}
			}
			break;
	}
	return pix;
}

// Creates a complete .ppm image when you call it
void make_ppm_image (image img) {
	pixel pix;
	img.height = calculate_height( img.width, img.country_code );
	make_ppm_header(img);
	for (int row=0;row<img.height;++row){
		for (int col=0;col<img.width;++col){
			pix = get_color(col,row,img);
			make_pixel(pix);
		}
	}
}

// Driver function
int main(void){
	int valInput=0;
	image img;
	while(valInput==0){
		fprintf(stderr, "What country's flag do you want to create? ");
		fscanf(stdin, "%i", &img.country_code);
		switch(img.country_code){	//Input validation
			case 1:
			case 2:
			case 3:
			case 4:
				valInput=1;
				break;
			default:
				valInput=0;
				fprintf(stderr,"Please input a valid number.\n");
				break;
		}
	}
	valInput=0;
	while(valInput==0){
		fprintf(stderr, "What width (in pixels) do you want it to be? ");
		fscanf(stdin, "%i", &img.width);
		if(img.width<=0){	//Input validation
			fprintf(stderr,"Please input a valid width.\n");
		}
		else{
			valInput=1;
		}
	}
	fprintf(stderr, "\nMaking country %d's flag with width %d pixels...\n", img.country_code, img.width);
	make_ppm_image(img);
	fprintf(stderr, "Done!\n\n");
	return 0;
}
