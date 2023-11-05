#include "StorageUnitConverter.h"
#include "BaseConverter.h"

#include "OzgurLibrary.h"
#include "OzgurString.h"

#include <stdio.h>

int main()
{
    //RunStorageUnitConverter();
    //RunBaseConverter();

    ///CREATING OZGUR STRINGS
    char arr1[5];
    OzgurString ozgurString1;
    CreateOzgurString(&ozgurString1, arr1, sizeof arr1);

    //FEATURE WILL BE ADDED
    ozgurString1._charArray[0] = '1';
    ozgurString1._charArray[1] = '2';
    ozgurString1._charArray[2] = '3';
    ozgurString1._charArray[3] = '4';
    ozgurString1._charArray[4] = '\0';
    CalculateStringSize(&ozgurString1); //THIS MUST BE CALLED IN THE FEATURE AND BE PRIVATE
    //FEATURE WILL BE ADDED

    char arr2[5];
    OzgurString ozgurString2;
    CreateOzgurString(&ozgurString2, arr2, sizeof arr2);

    //FEATURE WILL BE ADDED
    ozgurString2._charArray[0] = '5';
    ozgurString2._charArray[1] = '6';
    ozgurString2._charArray[2] = '7';
    ozgurString2._charArray[3] = '8';
    ozgurString2._charArray[4] = '\0';
    CalculateStringSize(&ozgurString2); //THIS MUST BE CALLED IN THE FEATURE AND BE PRIVATE
    //FEATURE WILL BE ADDED

    ///TESTS
    PrintOzgurString(&ozgurString1); //TODO: AUTO NEXT LINE PARAMETER
    printf(": ozgurString1\n");

    ReverseOzgurString(&ozgurString1);
    PrintOzgurString(&ozgurString1); //TODO: AUTO NEXT LINE PARAMETER
    printf(": ozgurString1 reversed\n");

    int castedInt = CastOzgurStringToInt(&ozgurString1);
    printf("%d: ozgurString1 reversed in integer\n", castedInt);

    int intToCast = 9876; //TODO: SMALLER SIZE DOESN'T WORK AND ADD BIGGER SIZE CHECK
    CastIntToOzgurString(intToCast, &ozgurString1);
    PrintOzgurString(&ozgurString1); //TODO: AUTO NEXT LINE PARAMETER
    printf(": ozgurString1 as the integer 9876\n");

    CopyPasteOzgurString(&ozgurString2, &ozgurString1);
    PrintOzgurString(&ozgurString1); //TODO: AUTO NEXT LINE PARAMETER
    printf(": ozgurString1 as the ozgurString2\n");

    return 1;
}