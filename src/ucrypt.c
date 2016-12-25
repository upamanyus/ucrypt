// Copyright (c) 2016 Upamanyu Sharma
//
// Cryptography utilities for puzzling and fun

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "vigenere.h"

char *read_full_file(const char *filename);
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
	const char *plaintext = read_full_file(argv[optind]);
	const char *key = argv[optind + 1];

	const char *ciphertext = vigenere_encrypt(plaintext, key);
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
	return 0;
}

char *read_full_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	fseek(file, 0, SEEK_END);
	size_t len = ftell(file);
	rewind(file);
	char *content = (char*)malloc(len + 1);
	fread(content, len, 1, file);
	fclose(file);
	return content;
}

void usage()
{
	printf("Usage: ucrypt [-o output_file] input_file key\n");
}
