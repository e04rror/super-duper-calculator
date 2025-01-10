#include <stdio.h>
#include "calculator.h"


int main(int argc, char **argv){
	

	if(argc < 4 )
	{
		printf("You need to enter two numbers and operation between them('+', '-', '*', '/')\n");
		printf("Example: 5 * 2\n");
		return 1;
	}
	
    double result_of_calculation = calculation(argc, argv);
	printf("The result is %f\n", result_of_calculation);

	return 0;
}
