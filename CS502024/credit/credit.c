#include <cs50.h>
#include <stdio.h>

int getDigitEODSL(long int cardN, long int mult);
int getDigitEODL(long int cardN, long int mult);
int getDigitEODSLRaw(long int cardN, long int mult);

int main()
{
    long int cardNumber = get_long("Number: ");
    int cksum1 = 0;
    int cksum2 = 0;
    int cardT = 0; // 1 - Visa | 2 - MasterCard | 3 - AMEX
    long int multiplier = 1;
    for (int i = 0; i < 8; i++)
    { // Picks numbers skiping a decimal place
        cksum1 += getDigitEODSL(cardNumber, multiplier);
        multiplier *= 100;
    }
    multiplier = 1;
    for (int i = 0; i < 8; i++)
    { // Picks numbers skiping a decimal place starting with the last
        cksum2 += getDigitEODL(cardNumber, multiplier);
        multiplier *= 100;
    }
    multiplier /= 100;
    if (getDigitEODSLRaw(cardNumber, multiplier) == 4 ||
        getDigitEODL(cardNumber, multiplier / 100) == 4)
    {
        cardT = 1;
    }
    else if (getDigitEODSLRaw(cardNumber, multiplier) == 5 &&
             getDigitEODL(cardNumber, multiplier) > 0 && getDigitEODL(cardNumber, multiplier) < 6)
    {
        cardT = 2;
    }
    else if (getDigitEODSLRaw(cardNumber, multiplier) == 0 &&
             getDigitEODL(cardNumber, multiplier) == 3 &&
             (getDigitEODSLRaw(cardNumber, multiplier / 100) == 4 ||
              getDigitEODSLRaw(cardNumber, multiplier / 100) == 7))
    {
        cardT = 3;
    }
    if ((cksum1 + cksum2) % 10 == 0)
    {
        if (cardT == 1)
        {
            printf("VISA\n");
        }
        else if (cardT == 2)
        {
            printf("MASTERCARD\n");
        }
        else if (cardT == 3)
        {
            printf("AMEX\n");
        }
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

int getDigitEODSL(long int cardN, long int mult)
{ // Every Other Digit Starting from Second to Last
    int temp = cardN % (100 * mult) / (10 * mult) * 2;
    if (temp >= 10)
    {
        temp = temp % 10 + 1;
    }
    return temp;
}

int getDigitEODL(long int cardN, long int mult)
{ // Every Other Digit Starting from Last
    return cardN % (10 * mult) / (1 * mult);
}

int getDigitEODSLRaw(long int cardN, long int mult)
{ // Every Other Digit Starting from Second to Last
    return cardN % (100 * mult) / (10 * mult);
}
