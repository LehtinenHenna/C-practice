/* 
 * File:   		Struct.h
 * Author: 		Henna Lehtinen	
 * Description: Header file for Struct.c
 */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct Orchard {
	char name[30];
	char produce[30];
	int kgPerHarvest;
	float sizeInSquareKm;
} orchard;

// Function prototypes here
struct Orchard *createOrchards(orchard *arrayPointer, int *arraySize);
void printArray(orchard *arrayPointer, int arraySize);
int *validateInteger(char userInput[], int *userInputNumber);
float *validateFloat(char userInput[], float *userInputFloat);

#endif /* STRUCT_H */ 
