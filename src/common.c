// Copyright (c) 2016 Upamanyu Sharma

#include "common.h"

// Returns a positive integer less than n that is congruent to k (mod n).
static int mod(int k, int n)
{
	int j = k % n;
	if (j < 0)
	{
		 j = j + n;
	}
	return j;
}

char
shift_letter(char plainchar, int shift_value)
{
	int plainchar_value = (int)plainchar - (int)'a';
	int shiftedchar_value = mod((plainchar_value + shift_value), 26);
	char shiftedchar = (char)shiftedchar_value + 'a';
	return shiftedchar;
}
