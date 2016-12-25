// Copyright (c) 2016 Upamanyu Sharma

#include "vigenere.h"
#include "common.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char *vigenere_encrypt(const char *plaintext, const char *key)
{
	size_t plaintext_size = strlen(plaintext);
	char *ciphertext = (char*)malloc(plaintext_size + 1);
	
	char *ciphertext_start = ciphertext;
	const char *key_start = key;

	while (*plaintext != '\0')
	{
		if (isalpha(*plaintext))
		{
			*ciphertext = vigenere_encrypt_char(tolower(*plaintext), tolower(*key));
			if (isupper(*plaintext))
			{
				*ciphertext = toupper(*ciphertext);
			}

			++key;
			if (*key == '\0')
			{
				key = key_start;
			}
		}
		else
		{
			*ciphertext = *plaintext;
		}
		++plaintext;
		++ciphertext;
	}
	*ciphertext = '\0';

	return ciphertext_start;
}

char *vigenere_decrypt(const char *ciphertext, const char *key)
{
	size_t ciphertext_size = strlen(ciphertext);
	char *plaintext = (char*)malloc(ciphertext_size + 1);

	char *plaintext_start = plaintext;
	const char *key_start = key;

	while (*ciphertext != '\0')
	{
		if (isalpha(*ciphertext))
		{
			*plaintext = vigenere_decrypt_char(tolower(*ciphertext), tolower(*key));
			if (isupper(*ciphertext))
			{
				*plaintext = toupper(*plaintext);
			}

			++key;
			if (*key == '\0')
			{
				key = key_start;
			}
		}
		else
		{
			*plaintext = *ciphertext;
		}
		++ciphertext;
		++plaintext;
	}
	*plaintext = '\0';

	return plaintext_start;
}
char vigenere_encrypt_char(char plainchar, char keychar)
{
	int keychar_value = (int)keychar - 'a';
	return shift_letter(plainchar, keychar_value);
}

char vigenere_decrypt_char(char cipherchar, char keychar)
{
	int keychar_value = (int)keychar - 'a';
	return shift_letter(cipherchar, -keychar_value);
}
