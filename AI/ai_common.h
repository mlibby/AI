#ifndef _AI_COMMON_H
#define _AI_COMMON_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef long int(*ptr_getline)(char**, long unsigned int*, struct _IO_FILE*);
typedef int(*ptr_printf)(const char*, ...);

void sort_char_in_place(int list_size, char **list);
int get_numeric_input(char *prompt, int min, int max, ptr_getline _getline, ptr_printf _printf);

#endif /* _AI_COMMON_H */
