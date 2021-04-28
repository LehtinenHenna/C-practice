This repository is a collection of school tasks with the objective of learning C programming.

For Exercise 9 there are two parts: task 2 and task 3 (other tasks were not code related).

Task 2:
  The objective was to learn about structs by creating an array of struct elements and printing them out.
  I made an Orchard struct that has four variables: name, produce, kgPerHarvest and sizeInSquareKm.
  The struct is defined in Struct.h file. Struct.c has implementations to create an array containing 
  orchard type struct elements according to user input. For user input validation there's also a function
  for validating integer types and float types to make sure the user inputs an integer for kgPerHarvest and
  a float for sizeInSquareKm. Struct.c also has a function to print out the array that consists of orchard 
  type struct elements. 
  
  All the functions are called in the main function in Exercise9.c.
  
Task 3:
  For task 3 the objective was to solve the problem number 36 in the Project Euler website. 
  Description:
    The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
    Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
    (The palindromic number, in either base, may not include leading zeros.)
 		
  The function palindrome in Palindrome.c checks all numbers from 0 to n (n <= 1 000 001) and saves those numbers which are 
  palindromic in both binary and decimal base to an array.  
  Besides the primary function of Palindrome.c there is a function turnNumberToArray that takes an integer
  as input and turns it into an array. This array is used later to check if the number is palindromic or not.
  There's also a function called convertToBinary which takes an integer number and converts it to binary in array format.
  The function checkIfArrayIsPalindromic is used to check both the decimal base array that was created in function
  turnNumberToArray and for the binary array. If both these are true then the number in question is added to an array that 
  collects all the numbers that are palindromic in both decimal and binary base. There's also a function called arrayPrinter in
  Palindrome.c to print out the elements of any array.
  Just for practice, Once the list of palindromic numbers is complete, the elements get written to a file in function 
  writeNumbersToFile that is implemented in FileIO.c. The numbers are then read from the file using function readNumbersFromFile
  in FileIO.c and their sum is calculated in function sumNumbersInArray, which is also in FileIO.c.
  
  Again the functions get called inside the main function in Exercise9.c
  
  I checked the resulting sum that I got from running this program in the Project Euler website, and it was correct.
 			
