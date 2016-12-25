#ifndef _UTIL_H_
#define _UTIL_H_

// Returns a newly malloc'd string with the contents of the file with the given
// name. If for some reason, the file could not be opened or the contents could
// not be read, this returns NULL.
char *read_full_file(const char *filename);

#endif  // _UTIL_H_
