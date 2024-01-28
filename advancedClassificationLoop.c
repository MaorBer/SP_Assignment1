// Made by Shalev and Yuval
#include <math.h>
#include "NumClass.h"
#include <stdbool.h>

int isPalindrome(int num) {
	if (num < 0)
		return false;
	if (num == 0)
		return true;
    int temp = num, reversedNum = 0;
    while (temp != 0) {
        reversedNum = (reversedNum * 10) + (temp % 10);
        temp /= 10;
    }
	return (num == reversedNum) ? true : false;
}

int isArmstrong (int num) {
    if (num < 0)
		return false;
	if (num == 0)
		return true;
	int temp = num;
	double numLength = (int) log10(num) + 1;
	int sum = 0;
	while (temp != 0) {
		sum += (int) pow((temp % 10), numLength);
		temp /= 10;
	}
	return (sum == num)? true : false;
}