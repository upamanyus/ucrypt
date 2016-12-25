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

	int option = 0;
	const char *outfilename = NULL;

	opterr = 0;
	while ( (option = getopt(argc, argv, "edo:")) != -1 )
	{
		switch (option)
		{
			case 'o':
				outfilename = optarg;
				break;
			case '?':
				if (optopt == 'o')
				{
					printf("Option -%c requires argument.\n", optopt);
				}
				usage();
				return 1;
			default:
				printf("%c", option);
				usage();
				return 1;
		}
	}

	if (optind >= argc)
	{
		usage();
		printf("Input file must be provided\n");
		return 2;
	}
	else if (optind >= argc - 1)
	{
		usage();
		printf("Key must be provided\n");
		return 2;
	}
	char *plaintext = read_full_file(argv[optind]);
	if (plaintext == NULL)
	{
		printf("Could not read file \"%s\".\n", argv[optind]);
		return 3;
	}
	const char *key = argv[optind + 1];

	char *ciphertext = vigenere_encrypt(plaintext, key);

	if (outfilename == NULL)
	{
		printf("%s", ciphertext);
	}
	else
	{
		FILE *out = fopen(outfilename, "w");
		fprintf(out, "%s", ciphertext);
		fclose(out);
	}

	free(plaintext);
	free (ciphertext);

	return 0;
}

void usage()
{
	printf("Usage: ucrypt [-o output_file] input_file key\n");
}
