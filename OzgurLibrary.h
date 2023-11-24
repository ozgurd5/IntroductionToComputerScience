#ifndef INTRODUCTIONTOCOMPUTERSCIENCE_OZGURLIBRARY_H
#define INTRODUCTIONTOCOMPUTERSCIENCE_OZGURLIBRARY_H

#include <stdio.h>

void ClearCharArray(char* charArray, const size_t charArraySize); //done //keep
int FindRealSizeOfTheCharArray(const char* array, const size_t arraySize); //done
void CopyPasteCharArray(char* arrayToPaste, const size_t arrayToPasteSize, const char* arrayToCopy, const size_t arrayToCopySize); //done
void PrintCharArray(const char* charArray, const size_t charArraySize); //done
int IsCharArrayContainsOnlyNumber(const char* charArray, const size_t charArraySize); //done
void TurnIntToCharArray(int intValue, char* charArray, const size_t charArraySize); //done
int TurnCharArrayToInt(const char* charArray, const size_t charArraySize); //done
char TurnSingleDigitToChar(const int singleDigitValue); //keep
int TurnCharToInt(const char charValue); //keep
void ReverseCharArray(char* charArray, const size_t charArraySize); //done //make reverse array
long double CalculatePower(const long double base, const long double exponent); //keep

#endif
