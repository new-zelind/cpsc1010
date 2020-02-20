/*
* flags.c
* Author: Zach Lindler
* Lecture, Lab Section: 001,006
* Lab #: 07
* Submitted on: 10/12/2018
*
* Purpose: This program creates the flags of Poland, the Netherlands, and Italy as .ppm files.
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

// Creates a header with the desired width and height.
// To call, input make_ppm_header(width, height);
void make_ppm_header (int width, int height) {
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d %d\n", width, height, 255);
}

// Creates a pixel with the colors you tell it to use when you call it
// To call, input make_pixel(Red value, Green value, Blue value);
void make_pixel (int r, int g, int b) {
	fprintf(stdout, "%c%c%c", r, g, b);
}

// Creates a complete .ppm image when you call it
// To call, input make_ppm_image(width, height);
void make_ppm_image (int country_code, int width) {
	int height = 0;
	if (country_code == 1) {
		height = 5 * (width/8);
	}
	else {
		height = 2 * (width/3);
	}
	make_ppm_header(width, height);
	switch(country_code) {
		case 1:
			for(int i=0; i<height; i++) {
				for(int j=0; j<width; j++) {
					if (i>=(height/2)) {
						make_pixel(220,20,0);
					}
					else {
						make_pixel(225,225,225);
					}
				}
			}
			break;
		case 2:
			for (int i=0; i<height; i++) {
				for(int j=0; j<width; j++) {
					if(i<=height/3) {
						make_pixel(174,28,40);
					}
					else if(i>height/3 && i<=2*(height/3)) {
						make_pixel(255,255,255);
					}
					else {
						make_pixel(33,70,139);
					}
				}
			}
			break;
		case 3:
			for (int i=0; i<height; i++) {
				for (int j=0; j<width; j++) {
					if (j<=width/3) {
						make_pixel(0, 140, 69);
					}
					else if (j>width/3 && j<=2*(width/3)) {
						make_pixel(244,245,240);
					}
					else {
						make_pixel(205,33,42);
					}
				}
			}
	}

}


int main()
{
	int width, country_code;
	//Input and read country code and image
	fprintf(stderr, "What country's flag do you want to create? ");
	fscanf(stdin, "%i", &country_code);
	fprintf(stderr, "%i", country_code);
	fprintf(stderr, "What width (in pixels) do you want it to be? ");
	fscanf(stdin, "%i", &width);
	fprintf(stderr, "%i", width);
	fprintf(stderr, "\nMaking country %d's flag with width %d pixels...\n", country_code, width);
	make_ppm_image(country_code, width);
	fprintf(stderr, "Done!\n\n");
	return 0;
}
