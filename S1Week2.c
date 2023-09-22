//Base conversion: 2-4-8-10-16

#include <stdio.h>
#include "OzgurLibrary.h"
#include "S1Week2.h"

int IsInputInTheRightFormat(const int inputBase, const char* userInput, const size_t userInputSize);
int IsCharArrayBase2(const char* charArray, const size_t charArraySize);
int IsCharArrayBase4(const char* charArray, const size_t charArraySize);
int IsCharArrayBase8(const char* charArray, const size_t charArraySize);
int IsCharArrayBase10(const char* charArray, const size_t charArraySize);
int IsCharArrayBase16(const char* charArray, const size_t charArraySize);

void S1Week2()
{
    int inputBase;
    int outputBase;
    char userInput[20];
    ClearCharArray(userInput, sizeof userInput);

    //TAKE INPUT BASE
    printf("Select number base to convert \"from\" (2-4-8-10-16):\n");
    do
    {
        scanf("%d", &inputBase);
    } while (inputBase != 2 && inputBase != 4 && inputBase != 8 && inputBase != 10 && inputBase != 16);
    //TAKE INPUT BASE

    //TAKE INPUT
    printf("Enter the number in the base of %d you want to convert: (Max 20 digit, no 0 at the beginning, positive only)\n", inputBase);
    do
    {
        scanf("%s", userInput);
    } while (!IsInputInTheRightFormat(inputBase, userInput, sizeof userInput));
    //TAKE INPUT

    //TAKE OUTPUT BASE
    printf("Select base to convert \"to\" (2-4-8-10-16):\n");
    do
    {
        scanf("%d", &outputBase);
    } while (outputBase != 2 && outputBase != 4 && outputBase != 8 && outputBase != 10 && outputBase != 16);
    //TAKE OUTPUT BASE



    PrintCharArray(userInput, sizeof userInput);
}

int IsInputInTheRightFormat(const int inputBase, const char* userInput, const size_t userInputSize)
{
    //Check if it's start with zero
    if (userInput[0] == '0') return 0;

    //Check the format
    if (inputBase == 2) return IsCharArrayBase2(userInput, userInputSize);
    else if (inputBase == 4) return IsCharArrayBase4(userInput, userInputSize);
    else if (inputBase == 8) return IsCharArrayBase8(userInput, userInputSize);
    else if (inputBase == 10) return IsCharArrayBase10(userInput, userInputSize);
    else return IsCharArrayBase16(userInput, userInputSize);
}

int IsCharArrayBase2(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return 1;
        else if (charArray[i] != '0' && charArray[i] != '1') return 0;
    }

    return 1;
}

int IsCharArrayBase4(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return 1;
        else if (charArray[i] != '0' && charArray[i] != '1' && charArray[i] != '2' && charArray[i] != '3') return 0;
    }

    return 1;
}

int IsCharArrayBase8(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return 1;
        else if (charArray[i] != '0' && charArray[i] != '1' && charArray[i] != '2' && charArray[i] != '3' && charArray[i] != '4'
        && charArray[i] != '5' && charArray[i] != '6' && charArray[i] != '7') return 0;
    }

    return 1;
}

int IsCharArrayBase10(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return 1;
        else if (charArray[i] != '0' && charArray[i] != '1' && charArray[i] != '2' && charArray[i] != '3' && charArray[i] != '4'
                 && charArray[i] != '5' && charArray[i] != '6' && charArray[i] != '7' && charArray[i] != '8' && charArray[i] != '9') return 0;
    }

    return 1;
}

int IsCharArrayBase16(const char* charArray, const size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return 1;
        //else if TODO
    }

    return 1;
}