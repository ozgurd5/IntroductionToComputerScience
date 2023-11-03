//Base conversion: 2-8-10-16

#include <stdio.h>
#include "OzgurLibrary.h"
#include "BaseConverter.h"

int IsInputInTheRightFormat(const int inputBase, const char* userInput, const size_t userInputSize);

int IsCharArrayBase2(const char* charArray, const size_t charArraySize);
int IsCharArrayBase8(const char* charArray, const size_t charArraySize);
int IsCharArrayBase10(const char* charArray, const size_t charArraySize);
int IsCharArrayBase16(const char* charArray, const size_t charArraySize);

int From2To10(const char* input, const int inputRealSize);
void From2To8(const char* input, const int inputRealSize, char* resultCharArray);

void RunBaseConverter()
{
    int inputBase;
    int outputBase;
    int inputRealSize;
    char input[20];
    ClearCharArray(input, sizeof input);
    char output[20];
    ClearCharArray(output, sizeof output);


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
    inputRealSize = FindRealSizeOfTheCharArray(input, sizeof input);

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
    if (inputBase == 2 && outputBase == 10) {
        printf("%d", From2To10(input, inputRealSize));
        return;
    }

    if (inputBase == 2 && outputBase == 8) From2To8(input, inputRealSize, output);
    PrintCharArray(output, sizeof output);
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

#pragma region ArrayBaseCheck
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
#pragma endregion

#pragma Converter Functions
void From2To8(const char* input, const int inputRealSize, char* resultCharArray)
{
    //Divides binary number into groups of three (reverse), converts each group decimal and puts them in the resultCharArray (reverse).

    int resultDigitNumber;
    if (inputRealSize % 3 == 0) resultDigitNumber = inputRealSize / 3;
    else resultDigitNumber = inputRealSize / 3 + 1;

    char trio[3];
    ClearCharArray(trio, sizeof trio);

    int currentTrioIndex = 2;
    int currentResultCharArrayIndex = resultDigitNumber - 1;

    for (int i = inputRealSize - 1; i >= 0; --i)
    {
        trio[currentTrioIndex] = input[i];

        if (currentTrioIndex == 0)
        {
            resultCharArray[currentResultCharArrayIndex] = TurnSingleDigitToChar(From2To10(trio, 3));

            currentTrioIndex = 3; //It has to be 3, because of the "currentTrioIndex--;" in the last line of the loop.
            currentResultCharArrayIndex--;
            ClearCharArray(trio, sizeof trio);
        }

        currentTrioIndex--;
    }

    if (currentTrioIndex != 2)
    {
        //In this condition trio may be (x is '\0'): xx0, x00, xx1, x11. To make things by the book we have to make trio start with a number, not..
        //..with an empty character. This still works because TurnCharToInt method returns 0 when it encounters with '\0' and it accidentally doesn't..
        //..break anything in the From2To10() function.

        //TODO: UPDATE THIS COMMENT AFTER LIBRARY CHANGING
        //We can reverse the trio array but ReverseCharArray() function doesn't reverse a char array directly, it's specialized to reverse char..
        //..arrays with empty characters at the end of it.

        resultCharArray[currentResultCharArrayIndex] = TurnSingleDigitToChar(From2To10(trio, 3));
    }
}

int From2To10(const char* input, const int inputRealSize)
{
    int intResult = 0;

    int j = 0;
    for (int i = inputRealSize - 1; i >= 0; --i)
    {
        intResult += TurnCharToInt(input[i]) * (int)CalculatePower(2, j);
        j++;
    }

    return intResult;
}

void From2To16()
{
    
}

void From10To2()
{

}

void From8To2()
{

}

void From16To2()
{

}
#pragma endregion