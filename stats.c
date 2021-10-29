/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
void print_statistics(unsigned char* array, int size)
{
	int temp;
	float median, mean;
	int i,j;
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if((int)array[j]<(int)array[i])
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
		mean+=(int)array[i];
	
	}
	mean=mean/SIZE;
	median=((int)array[19]+(int)array[20])/2;
	printf("Mean: %f\nMaximum: %d\nMinimum: %d\nMedian: %f",mean,(int)array[SIZE-1],(int)array[0],median);
}
void print_array(unsigned char* array, int size)
{
	int i;
	for(int i=0;i<size;i++)
	{
		printf("%d ", (int)array[i]);
	}
	printf("\n");
}	
int find_maximum(unsigned char* array, int size)
{
	int max=(int)array[0];
	int i;
	for(int i=1;i<size;i++)
	{
		if((int)array[i]>max)max=(int)array[i];
	}
	return max;
}
int find_minimum(unsigned char* array, int size)
{
	int min=(int)array[0];
	int i;
	for(int i=1;i<size;i++)
	{
		if((int)array[i]<min)min=(int)array[i];
	}
	return min;
}
float find_median(unsigned char* array, int size)
{
	int i,j;
	float median;
	int temp;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(array[j]<array[i])
			{
				temp=array[j];
				array[j]=array[i];
				array[i]=temp;
			}
		}
	}
	median=((int)array[size/2 -1 ] + (int)array[size/2])/2;
	return median;
}
float find_mean(unsigned char* array, int size)
{
	float mean=0;
	int i;
	for(int i=0;i<size;i++)
	{
		mean+=(int)array[i];
	}
	mean=mean/size;
	return mean;
}
void sort_array(unsigned char* array, int size)
{
	int i,j, temp;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(array[j]>array[i])
			{
				temp=array[j];
				array[j]=array[i];
				array[i]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
	printf("%d ", (int)array[i]);
	printf("\n");
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

print_array(test, SIZE);
sort_array(test,SIZE);
printf("Mean: %f\n", find_mean(test, SIZE));
printf("Median: %f\n", find_median(test, SIZE));
printf("Maximum: %d\n", find_maximum(test, SIZE));
printf("Minimum: %d\n", find_minimum(test, SIZE));
print_statistics(test,SIZE);
printf("\n");

}

/* Add other Implementation File Code Here */
