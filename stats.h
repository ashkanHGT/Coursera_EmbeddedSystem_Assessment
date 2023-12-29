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

#ifndef __STATS_H__
#define __STATS_H__

//The main function
void main();

//A function that prints the statistics of an array including minimum, maximum, mean, and median.
void Print_Statistics(unsigned char Min, unsigned char Max, unsigned char Avg, unsigned char Mead);

//Given an array of data and a length, prints the array to the screen
void Print_Array(unsigned char *Array, unsigned int SizeofArray);

//Given an array of data and a length, returns the median value
unsigned char Find_Median(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, returns the mean
unsigned char Find_Mean(unsigned char *DataToCompare, unsigned int ArraySize);

//Given an array of data and a length, returns the maximum
unsigned char Find_Maximum(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, returns the minimum
unsigned char Find_Minimum(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, sorts the array from largest to smallest
unsigned char Sort_Array(unsigned char *DataToSort, unsigned int ArraySize);


#endif /* __STATS_H__ */
