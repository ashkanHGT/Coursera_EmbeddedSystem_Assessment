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
void print_statistics(void);

//Given an array of data and a length, prints the array to the screen
void print_array(void);

//Given an array of data and a length, returns the median value
unsigned char find_median(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, returns the mean
unsigned char find_mean(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, returns the maximum
unsigned char find_maximum(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, returns the minimum
unsigned char find_minimum(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

//Given an array of data and a length, sorts the array from largest to smallest
unsigned char sort_array(unsigned char *DataToCompare, unsigned int ArraySizeToCompare);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */
