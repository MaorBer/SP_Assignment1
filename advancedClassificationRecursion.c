#include <math.h>
#include "NumClass.h"
#include <stdbool.h>
int reverseNum(int);
int createArmstrong(int, int);

int isPalindrome(int num) {
    if (num < 0)
        return false;
    if (num == reverseNum(num))
        return true;
    return false;
}

int reverseNum (int num) {
    if (num == 0)
        return false;
    int numLength = (int) log10(num);
    return (int) ((num % 10) * pow(10, numLength)) + reverseNum(num / 10);
}

int isArmstrong (int num) {
    if (num < 0)
        return false;
    if (num == createArmstrong(num, (int) log10(num) + 1))
        return true;
    return false;
}

int createArmstrong (int num, int numLength) {
    if (num == 0)
        return false;
    return (int) pow(num % 10, numLength) + createArmstrong(num / 10, numLength);
}