#include "OzgurLibrary.h"

char TurnSingleDigitToChar(const int singleDigitValue)
{
    return (char)(singleDigitValue + 48); //Numbers starts from 48 in ASCII
}

int TurnCharToInt(const char charValue)
{
    if (charValue == '\0') return 0;
    else return (int)charValue - 48; //Numbers starts from 48 in ASCII
}

void ClearCharArray(char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        charArray[i] = '\0';
    }
}

void CopyPasteArray(void* arrayToPaste, size_t arrayToPasteSize, void* arrayToCopy, size_t arrayToCopySize)
{
    //Casting void pointers to char pointers makes us use pointer arithmetics, so byte to byte copy-paste
    char* arrayToPasteChar = (char*) arrayToPaste;
    char* arrayToCopyChar = (char*) arrayToCopy;

    int forLoopCycleAmount;
    if (arrayToCopySize < arrayToPasteSize) forLoopCycleAmount = (int)arrayToCopySize;
    else forLoopCycleAmount = (int)arrayToPasteSize;

    for (int i = 0; i < forLoopCycleAmount; ++i)
    {
        arrayToPasteChar[i] = arrayToCopyChar[i];
    }
}

void PrintArray(void* array, size_t arraySize, dataType dataType)
{
    switch (dataType)
    {
        case INT:
        {
            int* intArray = (int*) array;
            for (int i = 0; i < arraySize; ++i) printf("%d", intArray[i]);
            break;
        }
        case FLOAT:
        {
            float* floatArray = (float*) array;
            for (int i = 0; i < arraySize; ++i) printf("%f", floatArray[i]);
            break;
        }
        case CHAR:
        {
            char* charArray = (char*) array;
            for (int i = 0; i < arraySize; ++i) printf("%c", charArray[i]);
            break;
        }
    }
}

void ReverseCharArray(char* charArray, size_t charArraySize)
{
    char temp;

    //i starts from beginning and goes to the middle, j starts from the end and goes to the middle
    int j = (int)charArraySize - 1;
    for (int i = 0; i < charArraySize / 2; ++i)
    {
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;

        j--;
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