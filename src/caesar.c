// Copyright (c) 2016 Upamanyu Sharma

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "caesar.h"
#include "common.h"

char
caesar_encrypt_char(char plainchar, int key)
{
	return shift_letter(plainchar, key);
}

char
caesar_decrypt_char(char cipherchar, int key)
{
	return shift_letter(cipherchar, -key);
}

char*
caesar_encrypt(const char *plaintext, int key)
{
	size_t plaintext_size = strlen(plaintext);
	char *ciphertext = (char*)malloc(plaintext_size + 1);
	char *ciphertext_start = ciphertext;
	
	while (*plaintext != '\0')
	{
		if (isalpha(*plaintext))
		{
			*ciphertext = caesar_encrypt_char(tolower(*plaintext), key);
			if (isupper(*plaintext))
			{
				*ciphertext = toupper(*ciphertext);
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

char*
caesar_decrypt(const char *ciphertext, int key)
{
	size_t ciphertext_size = strlen(ciphertext);
	char *plaintext = (char*)malloc(ciphertext_size + 1);
	char *plaintext_start = plaintext;
	
	while (*ciphertext != '\0')
	{
		if (isalpha(*ciphertext))
		{
			*plaintext = caesar_encrypt_char(tolower(*ciphertext), key);
			if (isupper(*ciphertext))
			{
				*plaintext = toupper(*plaintext);
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
