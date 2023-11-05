#include "OzgurString.h"

#pragma region Private
void CalculateStringSize(OzgurString* ozgurString)
{
    int stringSize = 0;

    for (int i = 0; i < ozgurString->_arraySize; ++i)
    {
        if (ozgurString->_charArray[i] == '\0') break;
        stringSize++;
    }

    ozgurString->_stringSize = stringSize;
}
#pragma endregion

#pragma region Public
void CreateOzgurString(OzgurString* ozgurString, const char* charArray, const size_t charArraySize)
{
    //TODO: size_t - const params
    ozgurString->_charArray = charArray;
    ozgurString->_arraySize = charArraySize;
    ozgurString->_stringSize = 0;

    ClearOzgurString(ozgurString);
}

void ClearOzgurString(OzgurString* ozgurString)
{
    for (int i = 0; i < ozgurString->_arraySize; ++i)
    {
        ozgurString->_charArray[i] = '\0';
    }

    ozgurString->_stringSize = 0;
}

void PrintOzgurString(OzgurString* ozgurString)
{
    for (int i = 0; i < ozgurString->_stringSize; ++i)
    {
        printf("%c", ozgurString->_charArray[i]);
    }
}

void CopyPasteOzgurString(OzgurString* ozgurStringToCopy, OzgurString* ozgurStringToPaste)
{
    short int isPasteArrayBigger = 0; //We have to delete the remaining indexes //TODO: BOOL
    int copyLoopAmount;

    if (ozgurStringToCopy > ozgurStringToPaste) {
        copyLoopAmount = ozgurStringToPaste->_stringSize;
    }
    else {
        copyLoopAmount = ozgurStringToCopy->_stringSize;
        isPasteArrayBigger = 1;
    }

    for (int i = 0; i < copyLoopAmount; ++i)
    {
        ozgurStringToPaste->_charArray[i] = ozgurStringToCopy->_charArray[i];
    }

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

    int j = ozgurString->_stringSize - 1;
    for (int i = 0; i <= ozgurString->_stringSize / 2; ++i)
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
        result += placeValue * ((int)ozgurString->_charArray[i] - 48); //Numbers starts from 48 in ASCII
        placeValue *= 10;
    }

    return result;
}

void CastIntToOzgurString(int intValue, OzgurString* ozgurString)
{
    int newStringSize = 0;

    for (int i = 0; i < ozgurString->_arraySize; ++i)
    {
        ozgurString->_charArray[i] = (char)(intValue % 10 + 48); //Numbers starts from 48 in ASCII
        intValue /= 10;
        newStringSize++;

        if (intValue == 0) break;
    }

    ReverseOzgurString(ozgurString);
    //TODO: MAKE REMAINING INDEXES '\0'
    ozgurString->_stringSize = newStringSize;
}
#pragma endregion