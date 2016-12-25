// Copyright (c) 2016 Upamanyu Sharma

#ifndef _CAESAR_H_
#define _CAESAR_H_

// These functions encrypt/decrypt a single character.
char
caesar_encrypt_char(char plainchar, int key);

char
caesar_decrypt_char(char cipherchar, int key);

// The plaintext must be a valid null-terminated string. Preserves punctuation
// and capitalization.
char*
caesar_encrypt(const char *plaintext, int key);

// The ciphertext must be a valid null-terminated string. Preserves punctuation
// and capitalization.
char*
caesar_decrypt(const char *ciphertext, int key);

#endif // _CAESAR_H_
