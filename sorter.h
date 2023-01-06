#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getCountL(char filename[], int * countLines);
void getLengthL(char filename[], int * countNums, int * countAllNums);
void giveNumsToStrs(char filename[], char * strs[], int countAllNums);
void fillArray (int * arr[], char * strs[], int * countNums, int countLines);
void swap(int * fst, int * snd);
void bubbleSort(int * arr, int countNumsCurr);
void sort(int * arr[], int * countNums, int countLines);
void fillStrs(int * arr[], char * strs[], int * countNums, int countAllNums, int countLines);
void transferToFile(char * strs[], int * countNums, int countLines);