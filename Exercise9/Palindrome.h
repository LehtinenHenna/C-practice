/* 
 * File:   		Palindrome.h
 * Author: 		Henna Lehtinen	
 * Description: Header file for Palindrome.c
 */

#ifndef PALINDROME_H
#define PALINDROME_H


// Function prototypes here
int *palindrome(int n, int *pointer, int *palindromeArraySize);
int *turnNumberToArray(int number, int *pointer, int *arraySizePointer);
int *convertToBinary(int number, int *pointer, int *arraySizePointer);
int checkIfArrayIsPalindromic(int *arrayPointer, int arraySize);
void arrayPrinter(int *arrayPointer, int arraySize);


#endif /* PALINDROME_H */ 
