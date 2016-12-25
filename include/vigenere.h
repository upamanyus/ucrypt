#ifndef _VIGENERE_H_
#define _VIGENERE_H_

// Shifts plainchar by keychar, both must be lowercase letters.
char vigenere_encrypt_char(char plainchar, char keychar);

// Inputs must be valid null-terminated strings. Preserves punctuation and
// capitalization.
char*
vigenere_encrypt(const char *plaintext, const char *key);

// Shifts plainchar by keychar, both must be lowercase letters.
char
vigenere_decrypt_char(char plainchar, char keychar);

// Inputs must be valid null-terminated strings. Preserves punctuation and
// capitalization.
char*
vigenere_decrypt(const char *plaintext, const char *key);

#endif // _VIGENERE_H_
