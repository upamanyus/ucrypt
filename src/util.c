#include "util.h"
#include "vigenere.h"
#include "caesar.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>

char *read_full_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	size_t len = ftell(file);
	rewind(file);

	char *content = (char*)malloc(len + 1);
	size_t num_read = fread(content, len, 1, file);

	if (num_read != 1)
	{
		free(content);
		return NULL;
	}

	fclose(file);
	return content;
}

struct operation_t
get_operation(int argc, char **argv)
{
	int option;
	struct operation_t operation;

	operation.outfilename = NULL;
	operation.infilename = NULL;
	operation.is_valid = true;
	operation.operationtype = NOTHING;
	operation.ciphertype = CAESAR;

	opterr = 0;
	int long_option_index = 0;

	static struct option long_options[] =
	{
		{"cipher", required_argument, 0, 'c'},
	};
	while ( (option = getopt_long(argc, argv, "edo:c:", long_options, &long_option_index)) != -1 )
	{
		switch (option)
		{
			case 'o':
				operation.outfilename = optarg;
				break;
			case 'c':
				if (strcmp(optarg, "vigenere") == 0)
				{
					operation.ciphertype = VIGENERE;
				}
				else if (strcmp(optarg, "caesar") == 0)
				{
					operation.ciphertype = CAESAR;
				}
				break;
			case 'e':
				if (operation.operationtype == NOTHING)
				{
					operation.operationtype = ENCRYPT;
				}
				else
				{
					printf("Warning: multiple actions specified (option -%c).", optopt);
				}
				break;
			case 'd':
				if (operation.operationtype == NOTHING)
				{
					operation.operationtype = DECRYPT;
				}
				else
				{
					printf("Warning: multiple actions specified (option -%c).", optopt);
				}
				break;
			case '?':
				if (optopt == 'o')
				{
					printf("Option -%c requires argument.\n", optopt);
				}
				else if (optopt == 'c')
				{
					printf("Please provide cipher name.\n");
				}
				operation.is_valid = false;
				break;
			default:
				printf("Option -%c unrecognized.\n", option);
				operation.is_valid = false;
		}
	}

	if (optind >= argc)
	{
		printf("Input file must be provided\n");
		operation.is_valid = false;
		return operation;
	}
	operation.infilename = argv[optind];
	
	if (optind >= argc - 1)
	{
		printf("Key must be provided\n");
		operation.is_valid = false;
		return operation;
	}
	operation.key = argv[optind + 1];
	return operation;
}

static int run_operation_vigenere(const struct operation_t *operation);
static int run_operation_caesar(const struct operation_t *operation);

int
run_operation(struct operation_t *operation)
{
	if (operation->ciphertype == VIGENERE)
	{
		return run_operation_vigenere(operation);
	}
	else if (operation->ciphertype == CAESAR)
	{
		return run_operation_caesar(operation);
	}
	return 0;
}

int run_operation_vigenere(const struct operation_t *operation)
{
	if (operation->operationtype == ENCRYPT)
	{
		char *plaintext = read_full_file(operation->infilename);
		if (plaintext == NULL)
		{
			printf("Unable to open input file \"%s\"\n", operation->infilename);
			return 1;
		}
		char *ciphertext = vigenere_encrypt(plaintext, operation->key);

		if (operation->outfilename != NULL)
		{
			FILE *outfile = fopen(operation->outfilename, "w");
			if (outfile != NULL)
			{
				fprintf(outfile, "%s", ciphertext);
			}
			else
			{
				return 1;
			}
			fclose(outfile);
		}
		else
		{
			printf("%s", ciphertext);
		}

		free(plaintext);
		free(ciphertext);
	}
	else if (operation->operationtype == DECRYPT)
	{
		char *ciphertext = read_full_file(operation->infilename);
		if (ciphertext == NULL)
		{
			printf("Unable to open input file \"%s\"\n", operation->infilename);
			return 1;
		}
		char *plaintext = vigenere_decrypt(ciphertext, operation->key);

		if (operation->outfilename != NULL)
		{
			FILE *outfile = fopen(operation->outfilename, "w");
			if (outfile != NULL)
			{
				fprintf(outfile, "%s", plaintext);
			}
			else
			{
				return 1;
			}
			fclose(outfile);
		}
		else
		{
			printf("%s", plaintext);
		}
		free(ciphertext);
		free(plaintext);
	}

	return 0;
}

int run_operation_caesar(const struct operation_t *operation)
{
	if (operation->operationtype == ENCRYPT)
	{
		char *plaintext = read_full_file(operation->infilename);
		if (plaintext == NULL)
		{
			printf("Unable to open input file \"%s\"\n", operation->infilename);
			return 1;
		}
		char *endptr;
		int caesar_key = strtol(operation->key, &endptr, 10);
		if (endptr == operation->key)
		{
			printf("Invalid number entered for key\n");
			return 1;
		}

		char *ciphertext = caesar_encrypt(plaintext, caesar_key);

		if (operation->outfilename != NULL)
		{
			FILE *outfile = fopen(operation->outfilename, "w");
			if (outfile != NULL)
			{
				fprintf(outfile, "%s", ciphertext);
			}
			else
			{
				return 1;
			}
			fclose(outfile);
		}
		else
		{
			printf("%s", ciphertext);
		}

		free(plaintext);
		free(ciphertext);
	}
	else if (operation->operationtype == DECRYPT)
	{
		char *ciphertext = read_full_file(operation->infilename);
		if (ciphertext == NULL)
		{
			printf("Unable to open input file \"%s\"\n", operation->infilename);
			return 1;
		}

		char *endptr;
		int caesar_key = strtol(operation->key, &endptr, 10);
		if (endptr == operation->key)
		{
			printf("Invalid number entered for key\n");
			return 1;
		}
		char *plaintext = caesar_decrypt(ciphertext, caesar_key);

		if (operation->outfilename != NULL)
		{
			FILE *outfile = fopen(operation->outfilename, "w");
			if (outfile != NULL)
			{
				fprintf(outfile, "%s", plaintext);
			}
			else
			{
				return 2;
			}
			fclose(outfile);
		}
		else
		{
			printf("%s", plaintext);
		}
		free(ciphertext);
		free(plaintext);
	}

	return 0;
}
