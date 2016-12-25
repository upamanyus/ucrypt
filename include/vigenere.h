// Copyright (c) 2016 Upamanyu Sharma

#ifndef _VIGENERE_H_
#define _VIGENERE_H_

// These functions encrypt/decrypt a single character.
char
vigenere_encrypt_char(char plainchar, char keychar);

char
vigenere_decrypt_char(char cipherchar, char keychar);

// Inputs must be valid null-terminated strings. Preserves punctuation and
// capitalization.
char*
vigenere_encrypt(const char *plaintext, const char *key);

// Inputs must be valid null-terminated strings. Preserves punctuation and
// capitalization.
char*
vigenere_decrypt(const char *plaintext, const char *key);

#endif // _VIGENERE_H_
