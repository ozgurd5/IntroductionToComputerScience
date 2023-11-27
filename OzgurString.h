#ifndef INTRODUCTIONTOCOMPUTERSCIENCE_OZGURSTRING_H
#define INTRODUCTIONTOCOMPUTERSCIENCE_OZGURSTRING_H

#include <stdio.h>

//_variable means it's read only. Don't change them, change them using its setter if it has any.
typedef struct OzgurString OzgurString;
struct OzgurString {
    char* _charArray;
    int _stringSize;
    size_t _arraySize;
};

void RunOzgurStringTests();
void CreateOzgurString(OzgurString* ozgurString, char* charArray, size_t charArraySize);
void CalculateOzgurStringSize(OzgurString* ozgurString);
void PrintOzgurString(OzgurString* ozgurString, short int hasEndLine);
void CopyPasteOzgurString(OzgurString* ozgurStringToCopy, OzgurString* ozgurStringToPaste);
void ReverseOzgurString(OzgurString* ozgurString);
int CastOzgurStringToInt(OzgurString* ozgurString);
void CastIntToOzgurString(int intValue, OzgurString* ozgurString);
int IsOzgurStringContainsOnlyNumber(OzgurString* ozgurString);
void ClearOzgurString(OzgurString* ozgurString);
void FillOzgurStringWithZero(OzgurString* ozgurString);
void MakeEmptyCharsZeroOzgurString(OzgurString* ozgurString);

#endif //INTRODUCTIONTOCOMPUTERSCIENCE_OZGURSTRING_H
