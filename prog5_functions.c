//prog5_functions.c
//Name: Ko Ko Maung
/*
ECE Application Programming
Professor M.Geiger
21/3/2018
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "prog5_functions.h"
# include <math.h>


double integrate(double a, double b, int n) {
	double aa = a;													//min value
	double bb = b;													//max value
	double nn = n;													//number of trapezoids
	double different_x;												//Change of x
	double mid_traps = 0;											//aa+Change_x
	double area;													//Area under the curve
	double currentxvalue = aa;										//determine the middle trapezoid values
	double i;														//add middle trapezoids to change the value of x

	different_x = (bb - aa) / nn;                                   //depending on number of trapezoids
	for (i = 1; i < nn; i++)										//include all trapezoids between min and max value
	{
		currentxvalue = different_x + currentxvalue;
		mid_traps = (2 * f(currentxvalue)) + mid_traps;
	}
	area = different_x * .5 * (mid_traps + f(aa) + f(bb));          //trapezoidal equation
	return area;
}

double f(double x) {
	printf("integrate() doesn't work!\n");                          //error message appear if integrate does not work
	return sin(x) + ((x * x) / 10);
}


void badInput() {
	char trash;
	do {
		scanf("%c", &trash);
	} while (trash != '\n');

}
