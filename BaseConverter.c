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

//TODO: carry these to the ozgurLibrary
char TurnDecimalDigitToHexadecimalDigit(const int decimalDigit);
int TurnHexadecimalDigitToDecimal(const char hexadecimalDigit);

int From2To10(const OzgurString * inputString);
void From2To8or16(OzgurString* inputString, OzgurString * outputString, short int isToHex);
void From10To2(OzgurString* inputString, OzgurString* outputString);
void From8or16To2(OzgurString* inputString, OzgurString* outputString, short int isFromHex);

//TODO: input size restrictions
//TODO: negative conversion
//TODO: 2to10 returns ozgurString
//TODO: general xTo10 function

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
    printf("(%d) \"to\" (2-8-10-16, different from the input base):\n", inputBase);
    while (1)
    {
        scanf("%d", &outputBase);
        if (outputBase != inputBase && (outputBase == 2 || outputBase == 8 || outputBase == 10 || outputBase == 16)) break;
        else printf("Error. Please select a base again: (2-8-10-16, different from the input base)\n");
    }

    //Calculate Output
    if (inputBase == 2) From2To8or16(&inputString, &outputString, outputBase == 16);
    else if (outputBase == 2) From8or16To2(&inputString, &outputString, inputBase == 16);

    else if (inputBase == 10)
    {
        if (outputBase == 2) From10To2(&inputString, &outputString);

        else
        {
            char tempChar[20];
            ClearCharArray(tempChar, 20);
            OzgurString tempString;
            CreateOzgurString(&tempString, tempChar, 20);

            From10To2(&inputString, &tempString);
            From2To8or16(&tempString, &outputString, outputBase == 16);
        }
    }

    else if (outputBase == 10)
    {
        if (inputBase == 2) CastIntToOzgurString(From2To10(&inputString), &outputString);

        else
        {
            From8or16To2(&inputString, &outputString, inputBase == 16);
            CastIntToOzgurString(From2To10(&outputString), &outputString);
        }
    }

    //8 -> 16 or 16 -> 8
    else
    {
        char tempChar[20];
        ClearCharArray(tempChar, 20);
        OzgurString tempString;
        CreateOzgurString(&tempString, tempChar, 20);

        From8or16To2(&inputString, &tempString, inputBase == 16);
        From2To8or16(&tempString, &outputString, outputBase == 16);
    }

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

    CalculateOzgurStringSize(outputString);

    //We have to reverse the output string because we put the remainders in order. We should put remainders in reverse
    ReverseOzgurString(outputString);
}

void From2To8or16(OzgurString* inputString, OzgurString * outputString, short int isToHex)
{
    //Starting from the end, divides binary number into groups of three or four, converts each group to decimal and puts them in the outputString.
    //Example: 10101 (base2) = (10)(101) (base2) = (2)(5) (base8) = 25 (base8)
    //Example: 10101 (base2) = (1)(0101) (base2) = (1)(5) (base16) = 15 (base16)

    //Calculate group size
    int groupSize;
    if (isToHex) groupSize = 4;
    else groupSize = 3;

    //We will put numbers to the outputString reverse but not starting from the end, this will help us where to start.
    int outputDigitNumber;
    if (inputString->_stringSize % groupSize == 0) outputDigitNumber = inputString->_stringSize / groupSize;
    else outputDigitNumber = inputString->_stringSize / groupSize + 1;

    //This will carry groups of 3 or 4
    char bufferArray[groupSize];
    ClearCharArray(bufferArray, groupSize);
    OzgurString bufferString;
    CreateOzgurString(&bufferString, bufferArray, groupSize);

    //We are reading input from the end, so we have to put numbers to the buffer from the end: 011 -> xx1 -> x11 -> 011
    int currentBufferIndex = groupSize - 1;

    //This is where to start putting numbers to the outputString: (2)(5)(base8) -> XXxxx -> X5xxx -> 25xxx
    int currentOutputStringIndex = outputDigitNumber - 1;

    //Starting from the end, numbers to the buffer, convert buffer to the decimal and put it to the outputString
    for (int i = inputString->_stringSize - 1; i >= 0; --i)
    {
        //Put numbers to the buffer
        bufferString._charArray[currentBufferIndex] = inputString->_charArray[i];
        //CalculateOzgurStringSize(&bufferString); //Inefficient, no need to calculate it everytime. Calculate it when needed
        currentBufferIndex--;

        if (currentBufferIndex == -1) //When the group is full
        {
            //Convert bufferString to decimal, make it char and put it to the outputString
            CalculateOzgurStringSize(&bufferString);
            outputString->_charArray[currentOutputStringIndex] = TurnDecimalDigitToHexadecimalDigit(From2To10(&bufferString));
            currentOutputStringIndex--;

            //Make bufferString ready for another group
            currentBufferIndex = groupSize - 1;
            ClearOzgurString(&bufferString);
        }
    }

    //When the last group is not full: x11, xx01, x10, xx01 etc.
    if (currentBufferIndex != groupSize - 1)
    {
        //x11 or xxx1 is not a correct form. It should be 11x or 1xxx. Arrange buffer
        //TODO: function?
        for (int i = 0; i < groupSize; ++i) //Try to find empty character
        {
            if (bufferArray[i] == '\0') //Empty character found
            {
                for (int j = i + 1; j < groupSize; ++j) //Try to find a normal character after the empty character
                {
                    if (bufferArray[j] != '\0') //Normal character found
                    {
                        //Swap them
                        char temp = bufferArray[i];
                        bufferArray[i] = bufferArray[j];
                        bufferArray[j] = temp;

                        break;
                    }
                }
            }
        }

        //Put the last group to the outputString
        CalculateOzgurStringSize(&bufferString);
        outputString->_charArray[currentOutputStringIndex] = TurnSingleDigitToChar(From2To10(&bufferString));
    }

    CalculateOzgurStringSize(outputString);
}

void From8or16To2(OzgurString* inputString, OzgurString* outputString, short int isFromHex)
{
    //Starting from the end, converts each digit to binary and puts them in the outputString

    //Calculate group size
    int groupSize;
    if (isFromHex) groupSize = 4;
    else groupSize = 3;

    //This will carry decimal equivalent of each digit, so we can convert them to binary. Its size is 2 because hex letters are 2 digits numbers
    char decimalBufferArray[2];
    ClearCharArray(decimalBufferArray, 2);
    OzgurString decimalBufferString;
    CreateOzgurString(&decimalBufferString, decimalBufferArray, 2);

    //This will carry binary equivalent of each digit.
    char binaryBufferArray[groupSize];
    ClearCharArray(binaryBufferArray, groupSize);
    OzgurString binaryBufferString;
    CreateOzgurString(&binaryBufferString, binaryBufferArray, groupSize);

    int currentOutputStringIndex = 0;
    for (int i = 0; i < inputString->_stringSize; ++i)
    {
        CastIntToOzgurString(TurnHexadecimalDigitToDecimal(inputString->_charArray[i]), &decimalBufferString);
        From10To2(&decimalBufferString, &binaryBufferString);

        //We don't need to format the binaryBufferString because outputString must not start with 0, so we won't execute the first if statement.
        if (i == 0)
        {
            //TODO: explain
            for (int j = 0; j < binaryBufferString._stringSize; ++j)
            {
                outputString->_charArray[currentOutputStringIndex] = binaryBufferString._charArray[j];
                currentOutputStringIndex++;
            }
            continue;
        }

        //binaryBufferString's stringSize must always be equal to groupSize. If we are converting from hexadecimal then it must be 0110..
        //..instead of 110 or 0010 instead of 10. If we are converting from octal than it must be 011 instead of 11 etc.
        //To do that we must shift numbers to the right and add zero(es) to the beginning.

        //If From10To2() function gives a correct digit output (4 digits for hex, 3 digits for octal) (which means stringSize == arraySize)..
        //..don't shift anything
        if (binaryBufferString._stringSize != binaryBufferString._arraySize)
        {
            int shiftAmount = groupSize - binaryBufferString._stringSize;

            MakeEmptyCharsZeroOzgurString(&binaryBufferString);
            for (int j = binaryBufferString._stringSize - 1; j >= 0 ; --j)
            {
                binaryBufferString._charArray[j + shiftAmount] = binaryBufferString._charArray[j];
                binaryBufferString._charArray[j] = '0';
                //CalculateOzgurStringSize(&binaryBufferString) //We don't need the stringSize of the binaryBufferString after here
            }
        }

        //Put the decimalBufferString to the outputString
        for (int j = 0; j < groupSize; ++j)
        {
            outputString->_charArray[currentOutputStringIndex] = binaryBufferString._charArray[j];
            currentOutputStringIndex++;
        }

        ClearOzgurString(&binaryBufferString);
    }

    CalculateOzgurStringSize(outputString);
}
#pragma endregion