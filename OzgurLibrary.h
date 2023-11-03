#ifndef INTRODUCTIONTOCOMPUTERSCIENCE_OZGURLIBRARY_H
#define INTRODUCTIONTOCOMPUTERSCIENCE_OZGURLIBRARY_H

#include <stdio.h>

void ClearCharArray(char* charArray, const size_t charArraySize);
int FindRealSizeOfTheCharArray(const char* array, const size_t arraySize);
void CopyPasteCharArray(char* arrayToPaste, const size_t arrayToPasteSize, const char* arrayToCopy, const size_t arrayToCopySize);
void PrintCharArray(const char* charArray, const size_t charArraySize);
int IsCharArrayContainsOnlyNumber(const char* charArray, const size_t charArraySize);
void TurnIntToCharArray(int intValue, char* charArray, const size_t charArraySize);
void ReverseCharArray(char* charArray, const size_t charArraySize);
long double CalculatePower(const long double base, const long double exponent);

#endif
