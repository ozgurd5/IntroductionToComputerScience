#include "OzgurLibrary.h"

//Makes all the elements of the array empty char. Because when we declare an array the addresses allocated for it may not be empty
void ClearCharArray(char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        charArray[i] = '\0';
    }
}

void CopyPasteArray(char* arrayToPaste, const size_t arrayToPasteSize, const char* arrayToCopy, const size_t arrayToCopySize)
{
    int forLoopCycleAmount;

    if (arrayToCopySize < arrayToPasteSize) forLoopCycleAmount = (int)arrayToCopySize;
    else forLoopCycleAmount = (int)arrayToPasteSize;

    for (int i = 0; i < forLoopCycleAmount; ++i)
    {
        if (arrayToCopy[i] == '\0') return;
        else arrayToPaste[i] = arrayToCopy[i];
    }
}

void PrintCharArray(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return;
        else printf("%c", charArray[i]);
    }
}

int IsCharArrayContainsOnlyNumber(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return 1;
        else if (charArray[i] != '0' && charArray[i] != '1' && charArray[i] != '2' && charArray[i] != '3' && charArray[i] != '4'
        && charArray[i] != '5' && charArray[i] != '6' && charArray[i] != '7' && charArray[i] != '8' && charArray[i] != '9') return 0;
    }

    return 1;
}

long double CalculatePower(const long double base, const long double exponent)
{
    long double result = 1;

    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }

    return result;
}