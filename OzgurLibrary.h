#ifndef INTRODUCTIONTOCOMPUTERSCIENCE_OZGURLIBRARY_H
#define INTRODUCTIONTOCOMPUTERSCIENCE_OZGURLIBRARY_H

#include <stdio.h>

typedef enum dataType dataType;
enum dataType
{
    INT,
    CHAR,
    FLOAT
};

char TurnSingleDigitToChar(const int singleDigitValue);
int TurnCharToInt(const char charValue);

void ClearCharArray(char* charArray, const size_t charArraySize);
void CopyPasteArray(void* arrayToPaste, size_t arrayToPasteSize, void* arrayToCopy, size_t arrayToCopySize);
void PrintArray(void* array, size_t arraySize, dataType dataType);
void ReverseCharArray(char* charArray, const size_t charArraySize);

long double CalculatePower(const long double base, const long double exponent);

#endif
