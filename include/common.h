// Copyright (c) 2016 Upamanyu Sharma
//
// Common functions used for the various ucrypt functions.

#ifndef _COMMON_H_
#define _COMMON_H_

// Shifts the plaintext character by shift_value. Assumes that plainchar is a
// lowercase letter.
char
shift_letter(char plainchar, int shift_value);

#endif
