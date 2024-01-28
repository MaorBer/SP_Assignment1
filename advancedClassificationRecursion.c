#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "NumClass.h"
#define NumOfDigits(a) floor(log10(a)) + 1

int isArmstrongRec(int x, int nDigits)
{
    if (x > 0)
    {
        return (pow((x % 10), nDigits) + isArmstrongRec((x / 10), nDigits));
    }
    return 0;
}

int isArmstrong(int y)
{
    int Yarm = isArmstrongRec(y, NumOfDigits(y));
    if (y == Yarm)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int reverse(int num)
{ // get the reverse number
    int digit = log10(num);
    if (num == 0)
    {
        return 0;
    }
    return (int)((num % 10 * pow(10, digit)) + reverse(num / 10));
}

int isPalindrome(int num)
{ // if it is palindrome return 1, else return 0
    if (num == reverse(num))
    {
        return 1;
    }
    return 0;
}