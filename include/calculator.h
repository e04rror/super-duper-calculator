#ifndef CALCULATOR_H 
#define CALCULATOR_H

#include <stdbool.h>
#include <stddef.h>
// for addition
double add(double augend, double addend);

// for subtraction
double subtract(double minuend, double subtrahend);

// for multiplication
double multiply(double multiplicand, double multiplier);

// for division
double divide(double dividend, double divisor); 

// for checking if the next symbol is '*' or '/'
bool check_multiply_division(char symbol);

// for choosing operation
double (*ch_operation(char operator))(double, double);

// for calculating multiplication and division
//double calculate_multi_div(double *arr_numbers, char *arr_char, size_t *begin_index);

double multi_division(double *numbers, char *operators, size_t number_operations);

double addition_subtraction(double *numbers, char *operators, size_t number_operations);

double calculation(char *string);

#endif


