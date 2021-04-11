/* 
 * File:   		FileIO.h
 * Author: 		Henna Lehtinen	
 * Description: Header file for FileIO.c
 */
 
#ifndef FILEIO_H
#define FILEIO_H


// Function prototypes
void writeNumbersToFile(int *arrayPointer, int arraySize, char fileName[]);
int *readNumbersFromFile(int *arrayPointer, char fileName[], int *arraySize);
int sumNumbersInArray(int *arrayPointer, int arraySize);


#endif /* FILEIO_H */ 
