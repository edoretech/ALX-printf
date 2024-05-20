#ifndef MAIN_H
#define MAIN_H
#define UNNSED(x) (void)x
#define BUFFER_SIZE 1024


/*Standard Libraries*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


/*Defined functions*/
int _printf(char *str, ...);
int print_int(int num);
int print_unsigned(unsigned int num);



#endif
