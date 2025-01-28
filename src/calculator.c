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

// for choosing  operation
double (*ch_operation(char operator))(double, double){
	switch(operator){
		case '+': return add; 
	    case '-': return subtract;
		case '*': return multiply; 
		case '/': return divide;
		default: return NULL;
	}
}


double multi_division(double *numbers, char *operators, size_t number_operations){
    size_t first_number = 0;
    double (*operation)(double, double);
    for(size_t i = 0; i < number_operations;i++){
        if(check_multiply_division(operators[i])){
            first_number++;
            operation = ch_operation(operators[i]);
            numbers[i+1] = operation(numbers[i], numbers[i+1]);
            numbers[i +1 - first_number] = numbers[i+1];
        }            
        else {
            first_number = 0;
        }
    }

    return 0.0;
}

double addition_subtraction(double *numbers, char *operators, size_t number_operations){
    double result = numbers[0];
    double (*operation)(double, double);
    for(size_t i = 0; i < number_operations; i++){
        if(operators[i] == '+' || operators[i] == '-'){
            operation = ch_operation(operators[i]);
            result = operation(result, numbers[i+1]);
        }
    }
    return result;
}

double calculation(char *string){
    const size_t MAX_AMOUNT = 50;
    
    double number = 0.0f;  
    char *current = string; 
    char  *end_number; 
    
    double numbers[MAX_AMOUNT];
    char operations[MAX_AMOUNT];
    size_t amount_numbers = 0, amount_operations = 0;
    

    while(*current != '\0'){

       number = strtod(current, &end_number);
       if(current != end_number){
            numbers[amount_numbers++] = number;
            current = end_number;
            
            if(ch_operation(*end_number)){
                operations[amount_operations++] = *end_number;
                current++;
            }
        } else if(ch_operation(*current)){ // what if someone enter the phrase like this "1+-/2"
            operations[amount_operations] = *current; 
            current++;
        
        } else {
            current++;
        }
    }
    operations[amount_operations] = '\0';

    for(size_t i = 0; i < amount_numbers;i++){
        printf("%f ", numbers[i]);
        if(operations[i]!= '\0'){
            printf("%c", operations[i]); 
        }
        printf("\n");
    }

    double result = 0.0f;
    result = multi_division(numbers, operations, amount_operations);
    result = addition_subtraction(numbers, operations, amount_operations);
    
    return result;
}
