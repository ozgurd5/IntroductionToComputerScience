#ifndef INTRODUCTIONTOCOMPUTERSCIENCE_OZGURSTRING_H
#define INTRODUCTIONTOCOMPUTERSCIENCE_OZGURSTRING_H

#include <stdio.h>

//_variable means it's read only. Don't change them, change them using its setter if it has any.
typedef struct OzgurString OzgurString;
struct OzgurString {
    char* _charArray;
    int _stringSize;
    int _arraySize;
};

void CreateOzgurString(OzgurString* ozgurString, const char* charArray, const size_t charArraySize);
void ClearOzgurString(OzgurString* ozgurString);
void PrintOzgurString(OzgurString* ozgurString);
void CopyPasteOzgurString(OzgurString* ozgurStringToCopy, OzgurString* ozgurStringToPaste);
void ReverseOzgurString(OzgurString* ozgurString);
int CastOzgurStringToInt(OzgurString* ozgurString);
void CastIntToOzgurString(int intValue, OzgurString* ozgurString);

void CalculateStringSize(OzgurString* ozgurString);

#endif //INTRODUCTIONTOCOMPUTERSCIENCE_OZGURSTRING_H
