#ifndef _VIGENERE_H_
#define _VIGENERE_H_

// Inputs must be valid null-terminated strings. Assumes everything is
// lowercase.
char *vigenere_encrypt(const char *plaintext, const char *key);

// Shifts plainchar by keychar, both must be lowercase letters.
char shift_char(char plainchar, char keychar);

#endif // _VIGENERE_H_
