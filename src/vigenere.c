// Copyright (c) 2016 Upamanyu Sharma

#include "vigenere.h"

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char shift_char(char plainchar, char keychar)
{
	char cipherchar = plainchar;
	if (isalpha(plainchar) && isalpha(keychar))
	{
		int plainchar_value = (int)plainchar - 'a';
		int keychar_value = (int)keychar - 'a';
		int cipherchar_value = (plainchar_value + keychar_value) % 26;
		cipherchar = (char)(cipherchar_value + 'a');
	}
	return cipherchar;
}

char *vigenere_encrypt(const char *plaintext, const char *key)
{
	size_t plaintext_size = strlen(plaintext);
	char *ciphertext = (char*)malloc(plaintext_size);
	
	char *ciphertext_start = ciphertext;
	const char *key_start = key;

	while (*plaintext != '\0')
	{
		*ciphertext = shift_char(*plaintext, *key);

		++plaintext;
		++ciphertext;
		++key;
		if (*key == '\0')
		{
			key = key_start;
		}
	}
	*ciphertext = '\0';

	return ciphertext_start;
}
