// Copyright (c) 2016 Upamanyu Sharma

#ifndef _UTIL_H_
#define _UTIL_H_
#include <stdbool.h>

// Returns a newly malloc'd string with the contents of the file with the given
// name. If for some reason, the file could not be opened or the contents could
// not be read, this returns NULL.
char *read_full_file(const char *filename);

enum ciphertype_t {
	VIGENERE,
	CAESAR,
};

enum operationtype_t {
	NOTHING,
	ENCRYPT,
	DECRYPT,
	INTERACTIVE,
};

struct operation_t {
	bool is_valid;
	enum ciphertype_t ciphertype;
	enum operationtype_t operationtype;
	const char *infilename;
	const char *outfilename;
	const char *key;
};

// Returns the operation corresponding to the given arguments. If there is
// something wrong with the given arguments, the operation_t.is_valid flag is
// set to false.
struct operation_t
get_operation(int argc, char **argv);

// Does whatever the operation specifies. If there is a problem, this will
// return non-zero.
int
run_operation(struct operation_t *operation);

#endif  // _UTIL_H_
