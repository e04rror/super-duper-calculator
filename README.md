# super-duper-calculator

This project is a simple implementation of a basic calculator in C. It supports basic arithmetic operations, including parentheses (although it does not handle nested parentheses correctly).

I made this project to learn more about function pointers, and for fun - after all, how hard could it be to make a simple calculator? There are still many bugs, and I plan to improve the implementation over time.

## Works Only In Shell

The program reads the string of operands and operators from the command line argument.


### Example usage:
./calc 1 + 2

If you are using parentheses '(', ')' or the multiplication symbol '*', you will need to escape them to prevent them from being interpreted by the shell:

./calc '\'(1 '\'* 2'\') + 5

## Future improvements
* Switching from command line arguments to interactive mode 
* Support for nested parentheses
* Bug fixes
