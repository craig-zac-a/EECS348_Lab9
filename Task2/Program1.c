/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Zachary Craig
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

#define SUCCESS 0
#define EMPTY_INPUT 1
#define OVERFLOW 2

void minMaxAverage(float sales[MONTHS])
{
	float min = sales[0];
	float max = sales[0];
	float average = 0;
	int minIndex = 0;
	int maxIndex;

	for(int i = 0; i < MONTHS; i++)
	{
		if(sales[i] < min)
		{
			min = sales[i];
			minIndex = i;
		}

		if(sales[i] > max)
		{
			max = sales[i];
			maxIndex = i;
		}

		average += sales[i];
	}

	average /= MONTHS;

	printf("Sales Summary:\n--------------\n");
	printf("Minimum sales:\t$%0.2f  (%s)\n", sales[minIndex], months[minIndex]);
	printf("Maximum sales:\t$%0.2f  (%s)\n", sales[maxIndex], months[maxIndex]);
	printf("Average sales:\t$%0.2f\n", average);

	return;
}

void sixMonthMovingAverage(float sales[MONTHS])
{
	float average;
	printf("Six-Month Moving Average Report:\n--------------------------------\n");
	for(int i = 0; i < 7; i++)
	{
		average = 0;
		for(int j = i; j < i+6; j++)
		{
			average += sales[j];
		}
		average /= MONTHS/2;
		if(i == 1) printf("%s\t-\t%s\t\t$%0.2f\n", months[i], months[i+5], average);
		else if(i == 3 || i == 5 || i == 6) printf("%s\t\t-\t%s\t$%0.2f\n", months[i], months[i+5], average);
		else printf("%s\t\t-\t%s\t\t$%0.2f\n", months[i], months[i+5], average);
	}
}

void highestToLowest(float sales[MONTHS])
{
	int array[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

	printf("Sales Report (Highest to Lowest):\n---------------------------------\nMonth\t\tSales\n");

	for(int i = 0; i < MONTHS; i++)
	{
		for(int j = i + 1; j < MONTHS; j++)
		{
			if(sales[i] < sales[j])
			{
				float temp = sales[i];
				int tempInt = array[i];

				sales[i] = sales[j];
				sales[j] = temp;
				array[i] = array[j];
				array[j] = tempInt;
			}
		}
		if(i == 0 || i == 1 || i == 4 || i == 8) printf("%s\t$%0.2f\n", months[array[i]], sales[i]);
		else printf("%s\t\t$%0.2f\n", months[array[i]], sales[i]);
	}
	return;
}

int main()
{
	// initializing global variables
	FILE *fp;
	float sales[MONTHS];

	// opens file for reading
	fp = fopen("sales.txt", "r");

	// inputs data from file into variables
	for(int i = 0; i < MONTHS; i++)
	{
		fscanf(fp, "%f", &sales[i]);
	}

	// all operations go after this
	printf("Monthly sales report for 2022:\n------------------------------\nMonth\t\tSales\n\n");

	for(int i = 0; i < MONTHS; i++)
	{
		if(i == 1 || i == 8 || i == 10 || i == 11)
			printf("%s\t%0.2f\n", months[i], sales[i]);
		else
			printf("%s\t\t%0.2f\n", months[i], sales[i]);
	}

	printf("\n\n");
	minMaxAverage(sales);
	printf("\n\n");
	sixMonthMovingAverage(sales);
	printf("\n\n");
	highestToLowest(sales);

	return 0;
}
