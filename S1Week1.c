//Bit, Byte, KiloByte, MegaByte, GigaByte, TeraByte Converter
//TODO: IDE recommendations
//TODO: Units as structs and recursive functions inside of them
//TODO: Unit codes, units and amounts are always staying in the screen

#include <stdio.h>

void ClearCharArray(char* charArray, size_t charArraySize);
void PrintUnits();
void DecideForUnitName(char* unitNameArray, const int unitNumber);
void CopyPasteArray(char* arrayToPaste, const size_t arrayToPasteSize, const char* arrayToCopy, const size_t arrayToCopySize);
void PrintCharArray(const char* charArray, size_t charArraySize);
long double CalculateSecondAmount(const int firstUnitNumber, const long double firstUnitAmount, const int secondUnitNumber);
long double CalculatePower(long double base, long double exponent);

void S1Week1()
{
    int firstUnitNumber;
    char firstUnitName[8];
    ClearCharArray(firstUnitName, sizeof firstUnitName);
    long double firstUnitAmount;

    int secondUnitNumber;
    char secondUnitName[8];
    ClearCharArray(secondUnitName, sizeof secondUnitName);
    long double secondUnitAmount;

    //GET THE FIRST UNIT
    printf("Please select the unit that you want to convert \"from\":\n");
    PrintUnits();
    do
    {
        scanf("%d", &firstUnitNumber);
    }
    while (firstUnitNumber < 0 || firstUnitNumber > 5);
    DecideForUnitName(firstUnitName, firstUnitNumber);
    //GET THE FIRST UNIT

    //GET THE FIRST UNIT AMOUNT
    printf("Please enter the amount of ");
    PrintCharArray(firstUnitName, sizeof firstUnitName);
    printf(" you want to convert:\n");
    scanf("%Lf", &firstUnitAmount);
    //GET THE FIRST UNIT AMOUNT

    //GET THE SECOND UNIT
    printf("Please select the unit that you want to convert \"to\":\n");
    PrintUnits();
    do
    {
        scanf("%d", &secondUnitNumber);
    }
    while (secondUnitNumber < 0 || secondUnitNumber > 5);
    DecideForUnitName(secondUnitName, secondUnitNumber);
    //GET THE SECOND UNIT

    //CALCULATE AND PRINT THE SECOND UNIT AMOUNT
    secondUnitAmount = CalculateSecondAmount(firstUnitNumber, firstUnitAmount, secondUnitNumber);
    printf("%Lf ", firstUnitAmount);
    PrintCharArray(firstUnitName, sizeof firstUnitName);
    printf(" is equal to %Lf ", secondUnitAmount);
    PrintCharArray(secondUnitName, sizeof secondUnitName);
    //CALCULATE AND PRINT THE SECOND UNIT AMOUNT
}

//Makes all the elements of the array empty char. Because when we declare an array the addresses allocated for it may not be empty
void ClearCharArray(char* charArray, size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        charArray[i] = '\0';
    }
}

void PrintUnits()
{
    printf("0: Bit\n1: Byte\n2: KiloByte\n3: MegaByte\n4: GigaByte\n5: TeraByte\n");
}

void DecideForUnitName(char* unitNameArray, const int unitNumber)
{
    //Since the last char of the strings are automatically '\0', their sizes are one more of the letter number
    //It's not important for 8 letter units though, since the UnitName arrays' lengths are 8
    if (unitNumber == 0) CopyPasteArray(unitNameArray, sizeof unitNameArray, "Bit", 4);
    else if (unitNumber == 1) CopyPasteArray(unitNameArray, sizeof unitNameArray, "Byte", 5);
    else if (unitNumber == 2) CopyPasteArray(unitNameArray, sizeof unitNameArray, "KiloByte", 9);
    else if (unitNumber == 3) CopyPasteArray(unitNameArray, sizeof unitNameArray, "MegaByte", 9);
    else if (unitNumber == 4) CopyPasteArray(unitNameArray, sizeof unitNameArray, "GigaByte", 9);
    else if (unitNumber == 5) CopyPasteArray(unitNameArray, sizeof unitNameArray, "TeraByte", 9);
}

void CopyPasteArray(char* arrayToPaste, const size_t arrayToPasteSize, const char* arrayToCopy, const size_t arrayToCopySize)
{
    int forLoopCycleAmount;

    if (arrayToCopySize < arrayToPasteSize) forLoopCycleAmount = (int)arrayToCopySize;
    else forLoopCycleAmount = (int)arrayToPasteSize;

    for (int i = 0; i < forLoopCycleAmount; ++i)
    {
        if (arrayToCopy[i] == '\0') return;
        else arrayToPaste[i] = arrayToCopy[i];
    }
}

void PrintCharArray(const char* charArray, size_t charArraySize)
{
    for (int i = 0; i < charArraySize; ++i)
    {
        if (charArray[i] == '\0') return;
        else printf("%c", charArray[i]);
    }
}

long double CalculateSecondAmount(const int firstUnitNumber, const long double firstUnitAmount, const int secondUnitNumber)
{
    int step = secondUnitNumber - firstUnitNumber;

    //To convert bit, we need to multiply by 8 in the last step. So we have to use separate the ways to converting

    //If none of the units are Bit
    if (firstUnitNumber != 0 && secondUnitNumber != 0)
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

long double CalculatePower(long double base, long double exponent)
{
    long double result = 1;

    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }

    return result;
}