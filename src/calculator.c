#include "calculator.h"
#include <stdlib.h> // for exit and strtod
#include <stdio.h> // for fprintf and stderr

// for addition
double add(double augend, double addend){
	return augend + addend;
}

// for subtraction
double subtract(double minuend, double subtrahend){
	return minuend - subtrahend;
}

// for multiplication
double multiply(double multiplicand, double multiplier){
	return multiplicand * multiplier;
}

// for division
double divide(double dividend, double divisor){
	if((int)divisor == 0){
		fprintf(stderr, "Error: Division by zero is not allowed!\n");
		exit(EXIT_FAILURE);
	}
	return dividend / divisor;
}

// for checking if the next symbol is '*' or '/'
bool check_multiply_division(char symbol){
	return (symbol == '*' || symbol == '/');
}

//for choosing  operation
double (*ch_operation(char operator))(double, double){
	switch(operator){
		case '+': return add; 
	    case '-': return subtract;
		case '*': return multiply; 
		case '/': return divide;
		default: return NULL;
	}
}

double calculation(char *string){
    double result = 0.0f,
           number = 0;
    double (*operation)(double, double) = add;
    char *current = string; 
    char  *end_number;
    while(*current != '\0'){
        number = strtod(current, &end_number);
        if(current != end_number){
            
            result = operation(result, number);
            
            current = end_number;
            
            if(ch_operation(*end_number)){
                operation = ch_operation(*end_number);
                current++;
            }
        }else if(ch_operation(*current)){
            operation = ch_operation(*current);
            current++;
        }else {
            current++;
        }
    }

    return result;
}
