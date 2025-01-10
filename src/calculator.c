#include "calculator.h"
#include <stdlib.h> // for exit and atof
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

double calculation(int argc, char **argv){
	
	double result = atof(argv[1]);
	double next_number = 0;
	double (*operation)(double, double) = NULL;
	bool calculation_multiply_division = false;
    int counter_priority_operations = 0;
    
	for(int i = 2; i < argc; i+=2){	
        if((i+2) < argc && check_multiply_division(argv[i+2][0])) {
            calculation_multiply_division = true;
            counter_priority_operations+=2;
            continue;
        }

        if(calculation_multiply_division){
            
            double priority_calculation = atof(argv[i-1]);
            next_number = atof(argv[i+1]);
            operation = ch_operation(argv[i][0]);
            priority_calculation = operation(priority_calculation, next_number);
            for(int index_prev_oper = 2; index_prev_oper < counter_priority_operations; index_prev_oper+=2){
                
                int index = i - index_prev_oper;
                operation = ch_operation(argv[index][0]);
                double previous_number = atof(argv[index - 1]);
                priority_calculation = operation(previous_number, priority_calculation);
            }

            operation = ch_operation(argv[i-counter_priority_operations][0]);
            result = operation(result, priority_calculation);
            calculation_multiply_division = false;
            counter_priority_operations = 0;
        
        } else {
		    operation = ch_operation(argv[i][0]);
		    next_number = atof(argv[i+1]);
		    result = operation(result, next_number);
	    }

    }
	return result;
}
