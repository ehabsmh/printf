#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * struct format_spec - struct for format spec handles
 * @specifier: the character indicates a specifier
 * @print_format: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
struct format_spec
{
	char specifier;
	int (*print_format)(va_list, int *, char *);
};

typedef struct format_spec fmt;

/* CUSTOM PRINTF FUNCTION */
int _printf(const char *, ...);

/* HELPER FUNCTIONS */
int _putchar(char);
int _strlen(char *);
int power_of_10(int);
void rev_string(char *);
char *_strcpy(char *, char *);

/* HANDLE PRINT */
int print_char(va_list args, int *curr_index, char *buffer);
int print_str(va_list args, int *curr_index, char *buffer);
int print_percent(va_list args, int *curr_index, char *buffer);

/* HANDLE PRINTF */
int format_handler(va_list, const char *);

/* HANDLE WRITE */
char *int_to_str(int n, char *converted_str);


#endif
