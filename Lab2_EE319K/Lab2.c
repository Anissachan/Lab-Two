// ****************** Lab2.c ***************
// Program written by: Anissa Chan
// Date Created: 1/18/2017 
// Last Modified: 1/18/2019 
// Brief description of the Lab: 

// An embedded system is capturing temperature data from a
// sensor and performing analysis on the captured data.
// The controller part of the system is periodically capturing size
// readings of the temperature sensor. Your task is to write three
// analysis routines to help the controller perform its function
//   The three analysis subroutines are:
//    1. Calculate the mean of the temperature readings 
//       rounded down to the nearest integer
//    2. Convert from Farenheit to Centigrate using integer math 
//    3. Check if the captured readings are a non-decreasing monotonic series
//       This simply means that the readings are sorted in non-decreasing order.
//       We do not say "increasing" because it is possible for consecutive values
//       to be the same, hence the term "non-decreasing". The controller performs 
//       some remedial operation and the desired effect of the operation is to 
//       raise the the temperature of the sensed system. This routine helps 
//       verify whether this has indeed happened
#include <stdint.h>
#define True 1
#define False 0

// Return the computed Mean
// Inputs: Readings is an array of 16-bit temperature measurements
//         N is the number of elements in the array
// Output: Average of the data
// Notes: you do not need to implement rounding
int16_t Find_Mean(int16_t const Readings[], int32_t const N){
	int32_t a = 0; //a is my index
	int i = 0; //i is my sum of the values of the array
	int16_t avg = 0; //for my average, we specify 16 bits is because the values given in the array are 16bits
	for (a = 0; a < N; a++) //the for statement contains the conditional statement that keeps it in the loop; it's not equal to because then it will exceed the array amount
	{ 
		i += Readings[a]; //take the value in i and add it to the measurements in the reading array N number of times and store that number back into i 
	}
		avg = i/N; //we taking the average here
  return avg;
}
// Convert temperature in Farenheit to temperature in Centigrade
// Inputs: temperature in Farenheit 
// Output: temperature in Centigrade
// Notes: you do not need to implement rounding
int16_t FtoC(int16_t const TinF){
	int16_t TinC = 0; //creating the name of the output measurement
	
		TinC = TinF - 32; //first part of the formula
		TinC *= 5; //do separate steps because we declared it as an integer and if combined then it may give a decimal thus causing wrong rounding
		TinC /= 9; 
		
  return TinC;
}

// Return True of False based on whether the readings
// are an increasing monotonic series
// Inputs: Readings is an array of 16-bit temperature measurements
//         N is the number of elements in the array
// Output: true if monotonic increasing, false if nonmonotonic
int IsMonotonic(int16_t const Readings[],int32_t const N){
	int i = 1; //index is at one value above what you are looking at so you want this one to be larger than the other one
	
	for (i = 1; i < N; i++)
	{
		if (Readings[i] < Readings[i-1])
		{
		return 0;
		}
		
	}
		return 1; 
	}
 