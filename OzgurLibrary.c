#include "OzgurLibrary.h"

//Makes all the elements of the array empty char. Because when we declare an array, the addresses allocated for it may not be empty
void ClearCharArray(char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        charArray[i] = '\0';
    }
}

//A char array may be partially full. For example: char[10] = "example". In this array only first 7 indexes are full and the last 3 indexes are..
//..empty. This function returns the real size of a char array, which is 7 in our example string.
int FindRealSizeOfTheCharArray(const char* array, const size_t arraySize)
{
    int realSize = 0;

    for (int i = 0; i < arraySize; ++i)
    {
        if (array[i] == '\0') break;
        else realSize++;
    }

    return realSize;
}

void CopyPasteCharArray(char* arrayToPaste, const size_t arrayToPasteSize, const char* arrayToCopy, const size_t arrayToCopySize)
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

void TurnIntToCharArray(int intValue, char* charArray, const size_t charArraySize)
{
    //TODO: NEGATIVE NUMBERS

    for (int i = 0; i < charArraySize - 1; ++i)
    {
        charArray[i] = (char)((intValue % 10) + 48); //Numbers starts from 48 in ASCII
        intValue /= 10;
    }

    ReverseCharArray(charArray, charArraySize);
}

void ReverseCharArray(char* charArray, const size_t charArraySize)
{
    char temp;

    //i will count forward, j will count down and they swap indexes. While they do that, they must not touch the '\0' in the end of the array.
    int i = 0;
    int j = (int)charArraySize - 2;

    //"(charArraySize - 1) / 2" provides that no matter the char array size is odd or even, it swaps the indexes without repetition.
    for (int k = 0; k < (charArraySize - 1) / 2; ++k)
    {
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;

        j--;
        i++;
    }
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