// Copyright (c) 2016 Upamanyu Sharma
//
// Cryptography utilities for puzzling and fun

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "vigenere.h"
#include "util.h"

void usage();

int main(int argc, char **argv)
{
	struct operation_t operation = get_operation(argc, argv);

	if (operation.is_valid == false)
	{
		usage();
		return 1;
	}

	return run_operation(&operation);
	return 0;
}

void usage()
{
	printf("Usage: ucrypt [--cipher caesar|vigenere] [-ed] [-o output_file] input_file key\n");
}
