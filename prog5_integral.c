//  prog5_integral.c
//Name: Ko Ko Maung
/*
ECE Application Programming
Professor M.Geiger
21/3/2018
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "prog5_functions.h"

#define prog5_functions_h


int main(void)
{
	double a = 2;																									//Variables min and max
	double b = 2;
	double change_x = 1;																							//x change at 1
	double answer = 0;																								//Integrals answer
	char ifValue = 'Y';
	char WValue;																									//Wrong user input value
	int abValue;																									//Correct a_b user input value
	int n = 1;																										//Trapezoids
	int nValue;																										//Number of trapazoid value


	while (ifValue != 'N' || ifValue == 'Y')
	{

		switch (ifValue)
		{
		case 'Y': case 'y':

			do {
				printf("Enter the low endpoint and high end point of the integral: \n");							//Input for min and max of the integral
				abValue = scanf("%lg %lg", &a, &b);

				if (abValue != 2 || b < a)																		   //Error number of input values
				{
					if (abValue != 2)
					{
						do
						{
							scanf("%c", &WValue);
						} while (WValue != '\n');
						printf("ERROR: Incorrect input format. \n");
					}

					if (b < a)																					   //If a < b, an error message will appear
						printf("ERROR: The value of must be greater than a, and, a must be less than b. \n");
				}

			}

			while (abValue < 2 || b < a);

			do {
				printf("Enter the number of trapezoids to be used: \n");										   //Input number of trapezoids

				nValue = scanf("%d", &n);

				if (nValue != 1 || n < 1)																			//If value of input is improper
				{
					if (nValue != 1)
					{
						do
						{
							scanf("%c", &WValue);
						} while (WValue != '\n');
						printf("ERROR: Improperly formatted input. \n");											//An error message will appear
					}
				}

				if (n < 1)																							//Error check incase user input value less than 1
					printf("ERROR: The number of trapezoids cannot be less than 1. \n");

				else																								//If no error found, integral will be calculate
					answer = integrate(a, b, n);																//These values will be used to calculate integral
				printf("With %d trapezoids, the integral between %f and %f = %f \n", n, a, b, answer);
			}

			while (nValue < 1 || n < 1);																			//If there is an error


			printf("Evaluate another interval? Enter Y for yes and N for no: \n");
			scanf(" %c", &ifValue);
			break;


		case 'N':																									//End the program if user inputs N
			printf("");
			break;

		case 'n':																									//End the program if user inputs n
			ifValue = 'N';
			printf("");
			break;

		default:																									//If user inputs every other possible format error, an error message will apear along with a question.
			printf("Invalid Response %c. Would you like to calculate another interval? Y/N: \n", ifValue);

		}
	}

	return 0;
}
