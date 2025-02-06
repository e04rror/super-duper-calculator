#include "calculator.h"
#include "stack.h"
#include "queue.h"
// #include "stack_numbers.h"
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

bool check_add_sub(char symbol){
    return (symbol == '+' || symbol == '-');
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

int precedence(char operat){
    if(check_multiply_division(operat)){
        return 1;
    }
        
    return 0;
    
}

double calculation(char *string){
    // i will change here, i know the code is messy 
    char *current = string,
         *end_number;
    double number;
    
    queue output;
    initialize_queue(&output);
    
    stack operators;
    initialize_stack(&operators);
    bool check = false;

    while(*current != '\0'){
        number = strtod(current, &end_number);
        if(current != end_number){
            
            // add the number to the queue
            enqueue_double(&output, number);
            current = end_number;
            if(*current == ')'){
                 while(!is_empthy(&operators) && top_char(&operators) != '('){
                         enqueue_char(&output, top_char(&operators)); 
                         pop(&operators);
                    }
                     pop(&operators);
                     check = false;
                     current++;
                
                if(ch_operation(*current)){
                     while(!is_empthy(&operators) && precedence(top_char(&operators)) >= precedence(*current)){
                        enqueue_char(&output, top_char(&operators));
                        pop(&operators);
                }

                push_char(&operators, *current);
                current++;
            }
            }else if(ch_operation(*current)){
                while(!is_empthy(&operators) && precedence(top_char(&operators)) >= precedence(*current) && !check ){
                    enqueue_char(&output, top_char(&operators));
                    pop(&operators);
                }

                push_char(&operators, *current);
                current++;
    
              }   
        } else if(*current == '('){
                push_char(&operators, *current);
                check = true;
                current++;
        } else if(ch_operation(*current) ){
                while(!is_empthy(&operators) && precedence(top_char(&operators)) >= precedence(*current) && !check){
                    enqueue_char(&output, top_char(&operators));
                    pop(&operators);
                }
		        push_char(&operators, *current);
                current++;
        }
        else {
            current++;
        }
      }       
    
    while(!is_empthy(&operators)){
        enqueue_char(&output, top_char(&operators));
        pop(&operators);
    }
    
    stack numbers;
    initialize_stack(&numbers);

    double (*operation)(double, double);
    node_q *temp = get_front(&output);
    double result; 
    while(!is_empty(&output)){
         if(temp->type == DOUBLE){
            push_double(&numbers, temp->data.num);
         } else if(temp->type == CHAR){
            operation = ch_operation(temp->data.op);
            
            double temp1 = top_double(&numbers);
            pop(&numbers);
            
            double temp2 = top_double(&numbers);
            pop(&numbers);
            
            result = operation(temp2, temp1);
            printf("Res: %f\n", result);
            push_double(&numbers, result);
        }
        dequeue(&output);
        temp = get_front(&output);
    }
    
    return result;
}
