// Copyright (c) 2016 Upamanyu Sharma

#ifndef _VIGENERE_H_
#define _VIGENERE_H_

// Encrypts a single character.
// -> (plainchar):  A single plaintext character to be encrypted; must be a
//     lower-case alphabet letter.
// -> (keychar): The key character; must be a lower-case alphabet letter.
// <- (return): The encrypted character of `plainchar` using `keychar`.
char
vigenere_encrypt_char(char plainchar, char keychar);

// Encrypts a single character.
// -> (cipherchar):  A single ciphertext character to be decrypted; must be a
//     lower-case alphabet letter.
// -> (keychar): The key character; must be a lower-case alphabet letter.
// <- (return): The decrypted character of `ciphercar` using `keychar`.
char
vigenere_decrypt_char(char cipherchar, char keychar);

// Encrypts text by tiling the key, and shifting the plaintext by the key amount
// at each character position.
// -> (plaintext): The plaintext to be encrypted. This can contain punctuation
//     and upper and lowercase letters.
// -> (key): The key to use. This can contain lower and upper case alphabet
//     characters, but nothing else (no spaces, punctuation, etc.)
// <- (return): The encrypted text. This will preserve punctuation and case. The
//     returned string will be newly malloc'd, so it is the responsibility of
//     the user to call free() on it.
char*
vigenere_encrypt(const char *plaintext, const char *key);

// Decrypts text that was encrypted using the `vigenere_encrypt` method.
// -> (ciphertext): The ciphertext to be decrypted. This can contain punctuation
//     and upper and lowercase letters.
// -> (key): The key to use. This can contain lower and upper case alphabet
//     characters, but nothing else (no spaces, punctuation, etc.)
// <- (return): The decrypted text. This will preserve punctuation and case. The
//     returned string will be newly malloc'd, so it is the responsibility of
//     the user to call free() on it.
char*
vigenere_decrypt(const char *plaintext, const char *key);

#endif // _VIGENERE_H_
