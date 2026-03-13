/*
.h
Declaration files
Inside of them we put prototypes, macros, structs, etc.
Allows that multiple .c files use the same function without repeating code
Best practice is to create one .h file for each .c file


.o
Binary files
Compiled code in binary
Each .c turns into a .o after compilation
*/


/*
Make file
Best practice:

COMPILER FLAGS .c FILES -o NAME
e.g. clang -I. hellomake.c hellofunc.c -o hellomake

But compiler undertand other orientations like:
clang hellomake.c hellofunc.c -o hellomake -I.
clang -o hellomake hellomake.c hellofunc.c -I.
*/