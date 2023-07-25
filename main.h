/**
 * struct print - struct for printer functions
 * @print_format: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct
{
  char specifier;
  int (*print_format)(va_list *, int *, char *);
} fmt;

/* CUSTOM PRINTF FUNCTION */
int _printf(const char *, ...);

/* HELPER FUNCTIONS */
int _putchar(char);
int _strlen(char *);
int power_of_10(int);
void rev_string(char *);
char *_strcpy(char *, char *);

/* HANDLE PRINT */
int print_char(va_list *args, int *curr_index, char *buffer);
int print_str(va_list *args, int *curr_index, char *buffer);
int print_percent(va_list *args, int *curr_index, char *buffer);

/* HANDLE PRINTF */
int format_handler(va_list *, const char *);

#endif
