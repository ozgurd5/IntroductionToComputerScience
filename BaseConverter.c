//Base conversion: 2-8-10-16

#include <stdio.h>
#include "OzgurLibrary.h"
#include "OzgurString.h"
#include "BaseConverter.h"

int IsInputInTheRightFormat(const int inputBase, const OzgurString* inputString);

int IsCharArrayBase2(const OzgurString* inputString);
int IsCharArrayBase8(const OzgurString* inputString);
int IsCharArrayBase10(const OzgurString* inputString);
int IsCharArrayBase16(const OzgurString* inputString);

char TurnDecimalDigitToHexadecimalDigit(const int decimalDigit);
int TurnHexadecimalDigitToDecimal(const char hexadecimalDigit);
int From2To10(const OzgurString * inputString);
void From2To8(OzgurString* inputString, OzgurString * outputString);
void From2To16(OzgurString* inputString, OzgurString * outputString);
void From10To2(OzgurString* inputString, OzgurString* outputString);
void From8To2(OzgurString* inputString, OzgurString* outputString);
void From16To2(OzgurString* inputString, OzgurString* outputString);

//TODO: input size restrictions
//TODO: negative conversion

void RunBaseConverter()
{
    int inputBase;
    int outputBase;
    char inputArray[20];
    char outputArray[20];
    OzgurString inputString;
    OzgurString outputString;

    ClearCharArray(outputArray, 20);
    ClearCharArray(inputArray, 20);
    CreateOzgurString(&inputString, inputArray, 20);
    CreateOzgurString(&outputString, outputArray, 20);

    //Take Input Base
    printf("Select number base to convert \"from\" (2-8-10-16):\n");
    while (1)
    {
        scanf("%d", &inputBase);
        if (inputBase == 2 || inputBase == 8 || inputBase == 10 || inputBase == 16) break;
        else printf("Error. Please select a base again: (2-8-10-16)\n");
    }

    //Take Input
    printf("Enter the number in the base of %d you want to convert: (Max 10 digit, no 0 at the beginning, positive only)\n", inputBase);
    while (1)
    {
        scanf("%s", inputString._charArray);
        CalculateOzgurStringSize(&inputString);
        if (IsInputInTheRightFormat(inputBase, &inputString)) break;
        else printf("Error. Please enter the number in the base of %d again: (Max 10 digit, no 0 at the beginning, positive only)\n", inputBase);
    }

    //Update Input String Size
    CalculateOzgurStringSize(&inputString);

    //Take Output Base
    printf("Select base to convert ");
    PrintCharArray(inputArray, sizeof inputArray);
    printf("(%d) \"to\" (2-8-10-16):\n", inputBase);
    while (1)
    {
        scanf("%d", &outputBase);
        if (outputBase == 2 || outputBase == 8 || outputBase == 10 || outputBase == 16) break;
        else printf("Error. Please select a base again: (2-8-10-16)\n");
    }

    //Calculate Output
    if (outputBase == 10)
    {
        if (inputBase == 2) CastIntToOzgurString(From2To10(&inputString), &outputString);

        else if (inputBase == 8)
        {
            From8To2(&inputString, &outputString);
            CastIntToOzgurString(From2To10(&outputString), &outputString);
        }

        else if (inputBase == 16)
        {
            From16To2(&inputString, &outputString);
            CastIntToOzgurString(From2To10(&outputString), &outputString);
        }
    }

    else if (inputBase == 2 && outputBase == 8) From2To8(&inputString, &outputString);
    else if (inputBase == 2 && outputBase == 16) From2To16(&inputString, &outputString);
    else if (inputBase == 10 && outputBase == 2) From10To2(&inputString, &outputString);
    else if (inputBase == 8 && outputBase == 2) From8To2(&inputString, &outputString);
    else if (inputBase == 16 && outputBase == 2) From16To2(&inputString, &outputString);

    //Print Output
    CalculateOzgurStringSize(&outputString);
    PrintOzgurString(&outputString, 0);
}

int IsInputInTheRightFormat(const int inputBase, const OzgurString* inputString)
{
    //Check if it's start with zero
    if (inputString->_charArray[0] == '0') return 0;

    //Check the format
    if (inputBase == 2) return IsCharArrayBase2(inputString);
    else if (inputBase == 8) return IsCharArrayBase8(inputString);
    else if (inputBase == 10) return IsCharArrayBase10(inputString);
    else return IsCharArrayBase16(inputString);
}

#pragma region ArrayBaseCheck
int IsCharArrayBase2(const OzgurString* inputString)
{
    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        if (inputString->_charArray[i] == '\0') return 1;
        else if (inputString->_charArray[i] != '0' && inputString->_charArray[i] != '1') return 0;
    }

    return 1;
}

int IsCharArrayBase8(const OzgurString* inputString)
{
    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        if (inputString->_charArray[i] == '\0') return 1;
        else if (inputString->_charArray[i] != '0' && inputString->_charArray[i] != '1' && inputString->_charArray[i] != '2' &&
                inputString->_charArray[i] != '3' && inputString->_charArray[i] != '4' && inputString->_charArray[i] != '5' &&
                inputString->_charArray[i] != '6' && inputString->_charArray[i] != '7') return 0;
    }

    return 1;
}

int IsCharArrayBase10(const OzgurString* inputString)
{
    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        if (inputString->_charArray[i] == '\0') return 1;
        else if (inputString->_charArray[i] != '0' && inputString->_charArray[i] != '1' && inputString->_charArray[i] != '2' &&
                inputString->_charArray[i] != '3' && inputString->_charArray[i] != '4' && inputString->_charArray[i] != '5' &&
                inputString->_charArray[i] != '6' && inputString->_charArray[i] != '7' && inputString->_charArray[i] != '8' &&
                inputString->_charArray[i] != '9') return 0;
    }

    return 1;
}

int IsCharArrayBase16(const OzgurString* inputString)
{
    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        if (inputString->_charArray[i] == '\0') return 1;
        else if (inputString->_charArray[i] != '0' && inputString->_charArray[i] != '1' && inputString->_charArray[i] != '2' &&
                inputString->_charArray[i] != '3' && inputString->_charArray[i] != '4' && inputString->_charArray[i] != '5' &&
                inputString->_charArray[i] != '6' && inputString->_charArray[i] != '7' && inputString->_charArray[i] != '8' &&
                inputString->_charArray[i] != '9' && inputString->_charArray[i] != 'A' && inputString->_charArray[i] != 'B' &&
                inputString->_charArray[i] != 'C' && inputString->_charArray[i] != 'D' && inputString->_charArray[i] != 'E' &&
                inputString->_charArray[i] != 'F') return 0;
    }

    return 1;
}
#pragma endregion

#pragma region Converter Functions
char TurnDecimalDigitToHexadecimalDigit(const int decimalDigit)
{
    if (decimalDigit >= 0 && decimalDigit <= 9) return TurnSingleDigitToChar(decimalDigit);
    else return (char)(decimalDigit - 10 + 65); //Capital letters starts from 65 in ASCII
}

int TurnHexadecimalDigitToDecimal(const char hexadecimalDigit)
{
    if (hexadecimalDigit >= '0' && hexadecimalDigit <= '9') return TurnCharToInt(hexadecimalDigit);
    else return (int)hexadecimalDigit - 55; //Capital letters starts from 65 in ASCII. Example: hex: A -> ascii: 65 -> decimal: 10
}

void From2To8(OzgurString* inputString, OzgurString * outputString)
{
    //Divides binary number into groups of three, converts each group to decimal and puts them in the outputString.
    //We have to group and put them in reverse. Example: 1001 (base2) = (1)(001) (base2) = (1)(1) (base8) = 11 (base8)

    int outputDigitNumber;
    if (inputString->_stringSize % 3 == 0) outputDigitNumber = inputString->_stringSize / 3;
    else outputDigitNumber = inputString->_stringSize / 3 + 1;

    char trioArray[3];
    ClearCharArray(trioArray, 3);

    OzgurString trioString;
    CreateOzgurString(&trioString, trioArray, 3);

    int currentTrioIndex = 0;
    int currentOutputStringIndex = outputDigitNumber - 1;

    for (int i = inputString->_stringSize - 1; i >= 0; --i)
    {
        trioString._charArray[currentTrioIndex] = inputString->_charArray[i];
        currentTrioIndex++;

        if (currentTrioIndex == 3)
        {
            trioString._stringSize = 3; //TODO: illegal?

            outputString->_charArray[currentOutputStringIndex] = TurnSingleDigitToChar(From2To10(&trioString));
            currentOutputStringIndex--;

            currentTrioIndex = 0;
            ClearOzgurString(&trioString);
        }
    }

    if (currentTrioIndex != 0) //In this condition trio may be (x is '\0'): 0xx, 00x, 1xx, 11x
    {
        trioString._stringSize = currentTrioIndex;
        outputString->_charArray[currentOutputStringIndex] = TurnSingleDigitToChar(From2To10(&trioString));
    }

    CalculateOzgurStringSize(outputString);
}

int From2To10(const OzgurString * inputString)
{
    int intResult = 0;

    int j = 0;
    for (int i = inputString->_stringSize - 1; i >= 0; --i)
    {
        intResult += TurnCharToInt(inputString->_charArray[i]) * (int)CalculatePower(2, j);
        j++;
    }

    return intResult;
}

//TODO: 2to8 and 2to16 very similar, DRY!

void From2To16(OzgurString* inputString, OzgurString * outputString)
{
    //Divides binary number into groups of three, converts each group to decimal and puts them in the outputString.
    //We have to group and put them in reverse. Example: 101101 (base2) = (10)(1101) (base2) = (2)(D) (base16) = 2D (base16)

    int outputDigitNumber;
    if (inputString->_stringSize % 4 == 0) outputDigitNumber = inputString->_stringSize / 4;
    else outputDigitNumber = inputString->_stringSize / 4 + 1;

    char quadArray[4];
    ClearCharArray(quadArray, 4);

    OzgurString quadString;
    CreateOzgurString(&quadString, quadArray, 4);

    int currentQuadIndex = 0;
    int currentOutputStringIndex = outputDigitNumber - 1;

    for (int i = inputString->_stringSize - 1; i >= 0; --i)
    {
        quadString._charArray[currentQuadIndex] = inputString->_charArray[i];
        currentQuadIndex++;

        if (currentQuadIndex == 4)
        {
            quadString._stringSize = 4; //TODO: illegal?

            outputString->_charArray[currentOutputStringIndex] = TurnDecimalDigitToHexadecimalDigit(From2To10(&quadString));
            currentOutputStringIndex--;

            currentQuadIndex = 0;
            ClearOzgurString(&quadString);
        }
    }

    if (currentQuadIndex != 0) //In this condition quad may be (x is '\0'): 0xxx, 00xx, 000x, 1xxx, 11xx, 111x
    {
        quadString._stringSize = currentQuadIndex;
        outputString->_charArray[currentOutputStringIndex] = TurnDecimalDigitToHexadecimalDigit(From2To10(&quadString));
    }

    CalculateOzgurStringSize(outputString);
}

void From10To2(OzgurString* inputString, OzgurString* outputString)
{
    int intInput = CastOzgurStringToInt(inputString);

    int i = 0;
    while (intInput != 0)
    {
        outputString->_charArray[i] = TurnSingleDigitToChar(intInput % 2);
        intInput /= 2;
        i++;
    }

    //We have to reverse the output string because we put the remainders in order. We should put remainders in reverse
    outputString->_stringSize = i; //TODO: illegal?
    ReverseOzgurString(outputString);
}

void From8To2(OzgurString* inputString, OzgurString* outputString)
{
    char trioArray[3];
    ClearCharArray(trioArray, 3);

    OzgurString trioString;
    CreateOzgurString(&trioString, trioArray, 3);

    char currentDigit = '\0';
    OzgurString currentDigitString;
    CreateOzgurString(&currentDigitString, &currentDigit, 1);

    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        From10To2(&currentDigitString, &trioString);

        for (int j = 0; j < 3; ++j) outputString->_charArray[i + j] = trioString._charArray[j];
    }
}

void From16To2(OzgurString* inputString, OzgurString* outputString)
{
    char quadArray[4];
    ClearCharArray(quadArray, 4);

    OzgurString quadString;
    CreateOzgurString(&quadString, quadArray, 4);

    char currentDigit = '\0';
    OzgurString currentDigitString;
    CreateOzgurString(&currentDigitString, &currentDigit, 1);

    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        currentDigitString._charArray[0] = inputString->_charArray[i];
        From10To2(&currentDigitString, &quadString);

        for (int j = 0; j < 4; ++j) outputString->_charArray[i + j] = quadString._charArray[j];
    }
}
#pragma endregion