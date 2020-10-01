/*
 *Nathaniel Callahan
 *hw3
 *
 *
 *
 * */
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "stack.h"

//static char prec(char operator);
//static int isNumeric(char *num);
char* to_postfix(char* equ);
int eval(char* equ);

#endif
