//Bit, Byte, KiloByte, MegaByte, GigaByte, TeraByte Converter

#include <stdio.h>
#include "OzgurLibrary.h"

void PrintUnits();
void DecideForUnitName(char* unitNameArray,const int unitID);
long double CalculateSecondAmount(const int firstUnitID, const long double firstUnitAmount, const int secondUnitNumber);

void RunStorageUnitConverter()
{
    int firstUnitID;
    char firstUnitName[8];
    ClearCharArray(firstUnitName, sizeof firstUnitName); //Allocated addresses may not be empty
    long double firstUnitAmount;

    int secondUnitID;
    char secondUnitName[8];
    ClearCharArray(secondUnitName, sizeof secondUnitName); //Allocated addresses may not be empty
    long double secondUnitAmount;

    //GET THE FIRST UNIT
    printf("Please select the unit that you want to convert \"from\":\n");
    PrintUnits();
    while (1) {
        scanf("%d", &firstUnitID);
        if (firstUnitID > 0 && firstUnitID < 5) break;
        else printf("Error. Enter a number between 0 and 5:\n");
    }
    DecideForUnitName(firstUnitName, firstUnitID);

    //GET THE FIRST UNIT AMOUNT
    printf("Please enter the amount of ");
    PrintArray(firstUnitName, sizeof firstUnitName, CHAR);
    printf(" you want to convert:\n");
    scanf("%Lf", &firstUnitAmount);

    //GET THE SECOND UNIT
    printf("Please select the unit that you want to convert \"to\":\n");
    PrintUnits();
    while (1) {
        scanf("%d", &secondUnitID);
        if (secondUnitID > 0 && secondUnitID < 5) break;
        else printf("Error. Enter a number between 0 and 5:\n");
    }
    DecideForUnitName(secondUnitName, secondUnitID);

    //CALCULATE AND PRINT THE SECOND UNIT AMOUNT
    secondUnitAmount = CalculateSecondAmount(firstUnitID, firstUnitAmount, secondUnitID);
    printf("%Lf ", firstUnitAmount);
    PrintArray(firstUnitName, sizeof firstUnitName, CHAR);
    printf(" is equal to %Lf ", secondUnitAmount);
    PrintArray(secondUnitName, sizeof secondUnitName, CHAR);
}

void PrintUnits()
{
    printf("0: Bit\n1: Byte\n2: KiloByte\n3: MegaByte\n4: GigaByte\n5: TeraByte\n");
}

void DecideForUnitName(char* unitNameArray, const int unitID)
{
    //Since the last char of the strings are automatically '\0', their sizes are one more of the letter number
    //It's not important for 8 letter units though, since the UnitName arrays' lengths are 8
    if (unitID == 0) CopyPasteArray(unitNameArray, sizeof unitNameArray, "Bit", 4);
    else if (unitID == 1) CopyPasteArray(unitNameArray, sizeof unitNameArray, "Byte", 5);
    else if (unitID == 2) CopyPasteArray(unitNameArray, sizeof unitNameArray, "KiloByte", 9);
    else if (unitID == 3) CopyPasteArray(unitNameArray, sizeof unitNameArray, "MegaByte", 9);
    else if (unitID == 4) CopyPasteArray(unitNameArray, sizeof unitNameArray, "GigaByte", 9);
    else if (unitID == 5) CopyPasteArray(unitNameArray, sizeof unitNameArray, "TeraByte", 9);
}

long double CalculateSecondAmount(const int firstUnitID, const long double firstUnitAmount, const int secondUnitNumber)
{
    int step = secondUnitNumber - firstUnitID;

    //To convert bit, we need to multiply by 8 in the last step. So we have to use separate the ways to converting

    //If none of the units are Bit
    if (firstUnitID != 0 && secondUnitNumber != 0)
    {
        if (step < 0) return firstUnitAmount * CalculatePower(2, 10 * -step);
        else if (step > 0) return firstUnitAmount / CalculatePower(2, 10 * step);
        else return firstUnitAmount;
    }

    //If one of the units is Bit
    else
    {
        if (step < 0) return firstUnitAmount * CalculatePower(2, 10 * (-step - 1)) * 8;
        else if (step > 0) return firstUnitAmount / CalculatePower(2, 10 * (step - 1)) / 8;
        else return firstUnitAmount;
    }
}