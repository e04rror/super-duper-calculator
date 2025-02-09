#include <stdio.h>
#include "calculator.h"
#include <string.h> // for strcat, and strlen
#include <stdlib.h> // for malloc

char *concatenete_arguments(int argc, char **argv){
    
    // simple function to calculate whole size
    size_t whole_size_all_arguments = 0;
    for(size_t i = 1; i < argc; i++){
        whole_size_all_arguments += strlen(argv[i]);
    }
    
    char *one_big_string = (char*)malloc(sizeof(char)*whole_size_all_arguments); // how can i discover the size of all array
    if(one_big_string == NULL){
        fprintf(stderr, "Error: Dynamically allocation failed!\n"); 
        return NULL;
    }
    char *pointer_to_each_arg = NULL;
    size_t current_char = 0;
    for(size_t i = 1; i < argc; i++){
        // strcat(one_big_string, argv[i]);
        pointer_to_each_arg = argv[i];
        while(*pointer_to_each_arg){
            if(*pointer_to_each_arg !=' '){
                one_big_string[current_char++] = *pointer_to_each_arg;
                pointer_to_each_arg++;
            } else {
                pointer_to_each_arg++;
            }

        }
    }
    

    return one_big_string;
}


int main(int argc, char **argv){
    
    //if(argc > 2){
        // call the function that concatenate all the arguments 
        // in the one big string
    
    char *string = concatenete_arguments(argc, argv);
    
    printf("The whole arguments: %s\n", string);

	
    double result_of_calculation = calculation(string);
	printf("The result is %f\n", result_of_calculation);
    free(string);
	return 0;
}
