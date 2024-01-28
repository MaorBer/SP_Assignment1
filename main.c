// Made by Shalev and Yuval
#include <stdio.h>
#include "NumClass.h"

int main(){
    int x, y, min, max;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Error: Input Error");
        goto skip;
    }
    max = (y > x) ? y : x;
    min = (y > x) ? x : y;
    printf("The Armstrong numbers are:");
    for (int i = min; i <= max; i++) {
        if (isArmstrong(i))
            printf(" %d", i);
    }
    printf("\nThe Palindromes are:");
    for (int i = min; i <= max; i++) {
        if (isPalindrome(i))
            printf(" %d", i);
    }
    printf("\nThe Prime numbers are:");
    for (int i = min; i <= max; i++) {
        if (isPrime(i))
            printf(" %d", i);
    }
    printf("\nThe Strong numbers are:");
    for (int i = min; i <= max; i++) {
        if (isStrong(i))
            printf(" %d", i);
    }
    printf("\n");
    skip:
    return 0;
}