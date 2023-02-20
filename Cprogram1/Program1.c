/*
 * Program1.c
 *
 *  Created on: Feb 14, 2023
 *      Author: Anjay Bhandari
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char months[12][12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
};



void SalesReport(char lines[11][11]) {
	printf("\n");
	printf("%s", "Monthly sales report for 2022:\n ");
	printf("Month		Sales\n");
	printf("%s		$%s", months[0], lines[0]);
	printf("%s	$%s", months[1], lines[1] );
	printf("%s		$%s", months[2], lines[2] );
	printf("%s		$%s",months[3], lines[3] );
	printf("%s		$%s",months[4], lines[4] );
	printf("%s		$%s",months[5], lines[5] );
	printf("%s		$%s",months[6], lines[6] );
	printf("%s		$%s",months[7], lines[7] );
	printf("%s	$%s", months[8],lines[8] );
	printf("%s		$%s", months[9], lines[9] );
	printf("%s        $%s",months[10], lines[10] );
	printf("%s        $%s", months[11], lines[11] );
	printf("\n");

	return;
}

void SalesSummary(char lines[11][11]) {
	float highest = 0.0;
	int highest_index = 0;
	float lowest = 0.0;
	int lowest_index = 0.0;
	float total = 0.0;
	int i;
	for (i = 0; i < 12; i++) {
		float value = atof(lines[i]);
		if (value >= highest || highest == 0.0) {
			highest = value;
			highest_index = i;
		}
		if (value <= lowest || lowest == 0.0) {
			lowest = value;
			lowest_index = i;
		}

		total += value;
	}

	printf("Sales Summary:\n");
	printf("Minimum Sales:    $%.2f (%s)\n", lowest, months[lowest_index] );
	printf("Maximum Sales:    $%.2f (%s)\n", highest, months[highest_index] );
	printf("Average Sales:    $%.2f\n", total / 12);

}

void SixMonthMovingAverage(char lines[11][11]) {

	float arr[11];
	int m;
	for (m = 0; m < 12; m++) {
		arr[m] = strtof(lines[m], NULL);
	}
	printf("\n");
	printf("Six-Month Moving Average Report: \n");

	int i, j;
	for (i = 0; i <= 6 ; i ++) {
		float total = 0;
		float average = 0;
		for (j = i; j <= i + 5; j++) {
			total += arr[j];
			//printf("%f : %f\n", total, arr[j]);
		}
		average = total / 6.0;
		printf("%10s - %10s     $%8f\n", months[i], months[i + 5], average);
	}

}

void swap(float *x, float *y) {
	float temp = *x;
	*x = *y;
	*y = temp;
}

int compare_float(float f1, float f2) {
	float precision = 1;
	if (((f1 - precision) < f2) && (f1 + precision) > f2) {
		return 1;
	}
	else {
		return 0;
	}
}


void SalesReportHighToLow(char lines[11][11]) {

	float arr[11];
	int m;
	for (m = 0; m < 12; m++) {
		arr[m] = strtof(lines[m], NULL);
	}


	int i,j, min_index;
	for (i= 0; i < 11; i++) {
		min_index = i;
		for (j = i + 1; j < 12; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		swap(&arr[min_index], &arr[i]);
	}




	printf("\n");
	printf("%s", "Monthly sales report for 2022:\n ");
	printf("Month		Sales\n");
	int k;
	for (k = 11; k >= 0; k--) {
		int a;
		for (a = 0; a < 12; a++) {
			if (compare_float(atof(lines[a]), arr[k]) == 1) {
				printf("%10s: $%8.2f\n", months[a], arr[k]);
			}

		}

	}



}

int main() {
	char inputFile[] = "input.txt";
	printf("Enter a filename: \n");
	// scanf("%s", inputFile);
	char contents[11];
	char lines[11][11];
	FILE *file_ptr;
	file_ptr = fopen(inputFile, "r");
	int index = 0;

	while(fgets(contents, 11, file_ptr) != NULL ) {
		 strcpy(lines[index], contents);
			index++;
		}

	fclose(file_ptr);
	SalesReport(lines);
	SalesSummary(lines);
	SixMonthMovingAverage(lines);
	SalesReportHighToLow(lines);


	return 0;
}


