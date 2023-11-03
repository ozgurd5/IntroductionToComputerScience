//Base conversion: 2-8-10-16

#include <stdio.h>
#include "OzgurLibrary.h"
#include "S1Week2.h"

int IsInputInTheRightFormat(const int inputBase, const char* userInput, const size_t userInputSize);

int IsCharArrayBase2(const char* charArray, const size_t charArraySize);
int IsCharArrayBase8(const char* charArray, const size_t charArraySize);
int IsCharArrayBase10(const char* charArray, const size_t charArraySize);
int IsCharArrayBase16(const char* charArray, const size_t charArraySize);

int From2To10(const char* userInput, const int userInputRealSize);

void S1Week2()
{
    int inputBase;
    int outputBase;
    char output[20];
    char input[20];
    ClearCharArray(input, sizeof input);
    int userInputRealSize;


    //TAKE INPUT BASE
    printf("Select number base to convert \"from\" (2-8-10-16):\n");
    while (1)
    {
        scanf("%d", &inputBase);
        if (inputBase == 2 || inputBase == 8 || inputBase == 10 || inputBase == 16) break;
        else printf("Error. Please select a base again: (2-8-10-16)\n");
    }

    //TAKE INPUT
    printf("Enter the number in the base of %d you want to convert: (Max 20 digit, no 0 at the beginning, positive only)\n", inputBase);
    while (1)
    {
        scanf("%s", input);
        if (IsInputInTheRightFormat(inputBase, input, sizeof input)) break;
        else printf("Error. Please enter the number in the base of %d again: (Max 20 digit, no 0 at the beginning, positive only)\n", inputBase);
    }
    userInputRealSize = FindRealSizeOfTheCharArray(input, sizeof input);
    printf("\naaa: %d\n", userInputRealSize);

    //TAKE OUTPUT BASE
    printf("Select base to convert ");
    PrintCharArray(input, sizeof input);
    printf("(%d) \"to\" (2-8-10-16):\n", inputBase);
    while (1)
    {
        scanf("%d", &outputBase);
        if (outputBase == 2 || outputBase == 8 || outputBase == 10 || outputBase == 16) break;
        else printf("Error. Please select a base again: (2-8-10-16)\n");
    }

    //CALCULATE OUTPUT NUMBER
    if (inputBase == 2 && outputBase == 10) printf("%d", From2To10(input, userInputRealSize));
}

int IsInputInTheRightFormat(const int inputBase, const char* userInput, const size_t userInputSize)
{
    //Check if it's start with zero
    if (userInput[0] == '0') return 0;

    //Check the format
    if (inputBase == 2) return IsCharArrayBase2(userInput, userInputSize);
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
        else if (charArray[i] != '0' && charArray[i] != '1' && charArray[i] != '2' && charArray[i] != '3' && charArray[i] != '4'
                && charArray[i] != '5' && charArray[i] != '6' && charArray[i] != '7' && charArray[i] != '8' && charArray[i] != '9'
                && charArray[i] != 'A' && charArray[i] != 'B' && charArray[i] != 'C' && charArray[i] != 'D' && charArray[i] != 'E'
                && charArray[i] != 'F') return 0;
    }

    return 1;
}

void From2To8(const char* userInput, const int userInputRealSize, const char* resultArray)
{

}

void From8To2()
{

}

int From2To10(const char* userInput, const int userInputRealSize)
{
    int intResult = 0;

    int j = 0;
    for (int i = 0; i < userInputRealSize; ++i)
    {
        intResult += userInput[i] * (int)CalculatePower(2, j);
        j++;
    }

    return intResult;
}

void From10To2()
{

}

void From2To16()
{

}

void From16To2()
{

}