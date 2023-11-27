#include "OzgurString.h"

void CreateOzgurString(OzgurString* ozgurString, char* charArray, size_t charArraySize)
{
    ozgurString->_charArray = charArray;
    ozgurString->_arraySize = charArraySize;
    CalculateOzgurStringSize(ozgurString);
}

void CalculateOzgurStringSize(OzgurString* ozgurString)
{
    int stringSize = 0;

    for (int i = 0; i < ozgurString->_arraySize; ++i)
    {
        if (ozgurString->_charArray[i] == '\0') break;
        stringSize++;
    }

    ozgurString->_stringSize = stringSize;
}

void ClearOzgurString(OzgurString* ozgurString)
{
    for (int i = 0; i < ozgurString->_arraySize; ++i)
    {
        ozgurString->_charArray[i] = '\0';
    }

    ozgurString->_stringSize = 0;
}

void FillOzgurStringWithZero(OzgurString* ozgurString)
{
    for (int i = 0; i < ozgurString->_stringSize; ++i) ozgurString->_charArray[i] = '0';
}

void MakeEmptyCharsZeroOzgurString(OzgurString* ozgurString)
{
    for (int i = ozgurString->_stringSize; i < ozgurString->_arraySize; ++i) ozgurString->_charArray[i] = '0';

    ozgurString->_stringSize = (int)ozgurString->_arraySize;
}


void PrintOzgurString(OzgurString* ozgurString, short int hasEndLine)
{
    for (int i = 0; i < ozgurString->_stringSize; ++i)
    {
        printf("%c", ozgurString->_charArray[i]);
    }

    if (hasEndLine) printf("\n");
}

void CopyPasteOzgurString(OzgurString* ozgurStringToCopy, OzgurString* ozgurStringToPaste)
{
    short int isPasteArrayBigger = 0; //We have to delete the remaining indexes if it is
    int copyLoopAmount;

    //Calculation of the copy loop amount based on smaller array
    if (ozgurStringToCopy > ozgurStringToPaste)
    {
        copyLoopAmount = ozgurStringToPaste->_stringSize;
    }
    else
    {
        copyLoopAmount = ozgurStringToCopy->_stringSize;
        isPasteArrayBigger = 1;
    }

    for (int i = 0; i < copyLoopAmount; ++i)
    {
        ozgurStringToPaste->_charArray[i] = ozgurStringToCopy->_charArray[i];
    }

    //Make the excess part empty
    if (isPasteArrayBigger)
    {
        for (int i = copyLoopAmount; i < ozgurStringToPaste->_stringSize; ++i)
        {
            ozgurStringToPaste->_charArray[i] = '\0';
        }
    }

    ozgurStringToPaste->_stringSize = copyLoopAmount;
}

void ReverseOzgurString(OzgurString* ozgurString)
{
    char temp;

    //i starts from beginning and goes to the middle, j starts from the end and goes to the middle
    int j = ozgurString->_stringSize - 1;
    for (int i = 0; i < ozgurString->_stringSize / 2; ++i)
    {
        temp = ozgurString->_charArray[i];
        ozgurString->_charArray[i] = ozgurString->_charArray[j];
        ozgurString->_charArray[j] = temp;

        j--;
    }
}

int CastOzgurStringToInt(OzgurString* ozgurString)
{
    int result = 0;
    int placeValue = 1;

    for (int i = ozgurString->_stringSize - 1; i >= 0; --i)
    {
        //If number is negative
        if (ozgurString->_charArray[i] == '-')
        {
            result *= -1;
            break;
        }

        result += placeValue * ((int)ozgurString->_charArray[i] - 48); //Numbers starts from 48 in ASCII
        placeValue *= 10;
    }

    return result;
}

void CastIntToOzgurString(int intValue, OzgurString* ozgurString)
{
    short int isIntValueNegative = 0;

    if (intValue < 0)
    {
        isIntValueNegative = 1;
        intValue *= -1;
    }

    int newStringSize = 0;

    //Put every digit into the array, starting from ones place
    int i; //We have to keep that value for negative
    for (i = 0; i < ozgurString->_arraySize; ++i)
    {
        ozgurString->_charArray[i] = (char)(intValue % 10 + 48); //Numbers starts from 48 in ASCII
        intValue /= 10;
        newStringSize++;

        if (intValue == 0) break;
    }

    //Put '-' at the end if intValue is negative
    if (isIntValueNegative)
    {
        ozgurString->_charArray[i + 1] = '-';
        newStringSize++;
    }

    //Make the rest of the array empty after putting every digit
    for (i = newStringSize; i < ozgurString->_arraySize; ++i)
    {
        ozgurString->_charArray[i] = '\0';
    }

    ozgurString->_stringSize = newStringSize;

    //Since we started putting numbers in the array starting form ones place, we need to reverse the array in the end
    ReverseOzgurString(ozgurString);
}

int IsOzgurStringContainsOnlyNumber(OzgurString* ozgurString)
{
    for (int i = 0; i < ozgurString->_stringSize; ++i)
    {
        if (ozgurString->_charArray[i] != '0' && ozgurString->_charArray[i] != '1' && ozgurString->_charArray[i] != '2' &&
            ozgurString->_charArray[i] != '3' && ozgurString->_charArray[i] != '4' && ozgurString->_charArray[i] != '5' &&
            ozgurString->_charArray[i] != '6' && ozgurString->_charArray[i] != '7' && ozgurString->_charArray[i] != '8' &&
            ozgurString->_charArray[i] != '9' && ozgurString->_charArray[0] != '-') return 0;
    }

    return 1;
}

void RunOzgurStringTests()
{
    OzgurString ozgurString1;
    OzgurString ozgurString2;

    char array1[] = "-1234";
    char array2[] = "-5678";

    CreateOzgurString(&ozgurString1, array1, 5);
    CreateOzgurString(&ozgurString2, array2, 5);

    PrintOzgurString(&ozgurString1, 0);
    printf(": ozgurString1\n");

    PrintOzgurString(&ozgurString2, 0);
    printf(": ozgurString2\n");

    int castedInt = CastOzgurStringToInt(&ozgurString1);
    printf("%d: ozgurString1 as integer\n", castedInt);

    ReverseOzgurString(&ozgurString1);
    PrintOzgurString(&ozgurString1, 0);
    printf(": ozgurString1 reversed\n");

    int intToCast = -9876;
    CastIntToOzgurString(intToCast, &ozgurString1);
    PrintOzgurString(&ozgurString1, 0);
    printf(": ozgurString1 as the integer %d\n", intToCast);

    CopyPasteOzgurString(&ozgurString2, &ozgurString1);
    PrintOzgurString(&ozgurString1, 0);
    printf(": ozgurString1 as the ozgurString2\n");

    int isOzgurStringContainsOnlyNumber = IsOzgurStringContainsOnlyNumber(&ozgurString1);
    printf("%d: Is ozgurString1 contains only number", isOzgurStringContainsOnlyNumber);

    ClearOzgurString(&ozgurString1);
    PrintOzgurString(&ozgurString1, 1);
    printf(": ozgurString1 cleaned");
}