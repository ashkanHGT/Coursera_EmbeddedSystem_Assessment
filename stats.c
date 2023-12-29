/******************************************************************************
* Copyright (C) 2023 by Ashkan Haghparast - Ajand Electronics Co.
*
* Redistribution, modification or use of this software in sources is permitted as long as file
* maitain this copyright. the file is not allowed to change by user
*
******************************************************************************/

/**
 * @file <stats.c> 
 * @brief <Use this file to calculate statistical functions>
 *
 * <In this file we have Some function to calculating statistical operations>
 *
 * @author <Ashkan Haghparast>
 * @date <2023/12/28>
 *
 */



#include <stdio.h>
#include <math.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	unsigned char MinimumValue = 0;
	unsigned char MaximumValue = 0;
	unsigned char AverageValue = 0;
	unsigned char MedianValue = 0; 

	Print_Array(test, sizeof(test));

	MinimumValue = Find_Minimum(test, sizeof(test));
	MaximumValue = Find_Maximum(test, sizeof(test));
	AverageValue = Find_Mean(test, sizeof(test));
	MedianValue = Find_Median(test, sizeof(test));

	Print_Statistics(MinimumValue, MaximumValue, AverageValue, MedianValue);

}


/******************************************************************************
 * Function: Print_Statistics
 * Description:
 *     This function prints the Statistics values which are calculated
 * Parameters:
 *     unsigned char Min: Calculated minimum value
 *     unsigned char Max: Calculated maximum value
 *	   unsigned char Avg: Calculated Average value
 *	   unsigned char Mead: Calculated Median value
 * Return: 
 *     None
 *****************************************************************************/
void Print_Statistics(unsigned char Min, unsigned char Max, unsigned char Avg, unsigned char Mead){

	printf("Minimum Value is :%d \n", Min);
	printf("Maximum Value is :%d \n", Max);
	printf("The Down Rounded Average is: %d \n", Avg);
	printf("The Down Rounded Median value is: %d \n", Mead);
}


/******************************************************************************
 * Function: Print_Array
 * Description:
 *     This function prints the orginal array and then sort them from largest to
 *     lowest value and then print again the sorted array
 * Parameters:
 *     unsigned char *Array: Pointer to a data array
 *     unsigned int SizeofArray: size of array
 * Return: 
 *     unsigned char :Down Rounded median of array
 *****************************************************************************/
void Print_Array(unsigned char *Array, unsigned int SizeofArray){

	unsigned char i = 0;

	printf("The orginal Array is: \n");
	for(i=0 ; i<SIZE ; i++){
		printf("%d ", *(Array + i));
	}
	printf("\n\n");

	Sort_Array(Array, SizeofArray); // Sort array from largest to lowest

	printf("Then we sort the array from largest to lowest value: \n");
	for(i=0 ; i<SIZE ; i++){
		printf("%d ", *(Array + i));
	}
	printf("\n\n");
}


/******************************************************************************
 * Function: Find_Median
 * Description:
 *     This function takes a set of numbers, First sort them from largest to lowest
 *	   and them find the median in sorted array
 * Parameters:
 *     unsigned char *DataToCompare: Pointer to a data array
 *     unsigned int ArraySizeToCompare: size of array
 * Return: 
 *     unsigned char :Down Rounded median of array
 *****************************************************************************/
unsigned char Find_Median(unsigned char *DataToCompare, unsigned int ArraySizeToCompare){
	
	float MedianTemp = 0;
	float Buff;
	unsigned char RoundMedian = 0;
	
	Sort_Array(DataToCompare, ArraySizeToCompare);	//before fine median we should sort the array
	
	if(ArraySizeToCompare % 2){
		MedianTemp = *(DataToCompare + ((ArraySizeToCompare/2) +1));
	}
	else{
		Buff = *(DataToCompare + (ArraySizeToCompare/2)) + *(DataToCompare + ((ArraySizeToCompare/2) + 1));
		MedianTemp = Buff / 2;
		RoundMedian = floor(MedianTemp);
	}

	//printf("The Median value is: %.2f \n", MedianTemp);
	//printf("The Down Rounded Median value is: %d \n", RoundMedian);

	return RoundMedian;

}


/******************************************************************************
 * Function: Find_Mean
 * Description:
 *     This function takes a set of numbers and find the average of the and then 
 *	   Down Rounded the average
 * Parameters:
 *     unsigned char *DataToCompare: Pointer to a data array
 *     unsigned int ArraySize: size of array
 * Return: 
 *     unsigned char :Down Rounded average of array
 *****************************************************************************/
unsigned char Find_Mean(unsigned char *DataToCompare, unsigned int ArraySize){

	unsigned char i = 0;
	float SumTemp = 0;
	float Aveg = 0;
	unsigned char RoundedAveg = 0;
	
	for(i=0 ; i<ArraySize ; i++){
		SumTemp += *(DataToCompare + i);
	}

	Aveg = SumTemp / ArraySize;
	RoundedAveg = floor(Aveg);
	
	//printf("The Average is: %.2f \n", Aveg);
	//printf("The Down Rounded Average is: %d \n", RoundedAveg);
	return RoundedAveg;
} 


/******************************************************************************
 * Function: Find_Maximum
 * Description:
 *     This function takes a set of numbers and find the maximum number in that array
 * Parameters:
 *     unsigned char *DataToCompare: Pointer to a data array
 *     unsigned int ArraySizeToCompare: size of array
 * Return: 
 *     unsigned char :Maximum value in array
 *****************************************************************************/
unsigned char Find_Maximum(unsigned char *DataToCompare, unsigned int ArraySizeToCompare){

	unsigned char i = 0;
	unsigned char MaxTemp = 0x00;
	
	for(i=0 ; i<ArraySizeToCompare ; i++){

		if(*(DataToCompare + i) > MaxTemp){

			MaxTemp = *(DataToCompare + i);	
		}
	}

	//printf("Maximum Value is :%d \n", MaxTemp); 
	return MaxTemp;
}


/******************************************************************************
 * Function: Find_Minimum
 * Description:
 *     This function takes a set of numbers and find the minimum number in that array
 * Parameters:
 *     unsigned char *DataToCompare: Pointer to a data array
 *     unsigned int ArraySizeToCompare: size of array
 * Return: 
 *     unsigned char :Maximum value in array
 *****************************************************************************/
unsigned char Find_Minimum(unsigned char *DataToCompare, unsigned int ArraySizeToCompare){

	unsigned char i = 0;
	unsigned char MinTemp = 0xFF;
	
	for(i=0 ; i<ArraySizeToCompare ; i++){

		if(*(DataToCompare + i) < MinTemp){

			MinTemp = *(DataToCompare + i);	
		}
	}

	//printf("Minimum Value is :%d \n", MinTemp); 
	return MinTemp;
}


/******************************************************************************
 * Function: Sort_Array
 * Description:
 *     This function takes a set of numbers and sort them from maximum to minimum
 * Parameters:
 *     unsigned char *DataToSort: Pointer to a data array
 *     unsigned int ArraySize: size of array
 * Return: 
 *     None
 *****************************************************************************/
unsigned char Sort_Array(unsigned char *DataToSort, unsigned int ArraySize){
	
	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char Temp = 0;	


    for (i = 0; i < ArraySize; i++) {  
  
        for (j = i + 1; j < ArraySize; j++) {  
  
            if (*(DataToSort + j) > *(DataToSort + i)) {  
  
                Temp = *(DataToSort + i);  
                *(DataToSort + i) = *(DataToSort + j);  
                *(DataToSort + j) = Temp;  
            }  
        }  
    } 

//	for(i=0 ; i<ArraySize ; i++){
//		printf("%d ", *(DataToSort + i));
//	}
}


