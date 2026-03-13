CC = clang
CFLAGS = -I.

hellomake: hellomake.o hellofunc.o
	$(CC) hellomake.o hellofunc.o -o hellomake


# CC → macro to identify the compiler to be used
# CFLAGS → list of flags to pass to the compilation command

# By putting the object files (.o) in the dependency list and in the rule, 
# make knows it must first compile the .c versions individually, and then 
# build the executable hellomake

# Warning
# Any changes to hellomake.h make would not recompile the .c files
# To fix that, we need to tell make that all .c files depend on certain .h files

# By using .o files, the target relyes on the .o files, instead of the .o files
# 'make' automatically compiles .c files into .o files
# The advantage to rely on .o files: if a .c file changes, only that related .o file is recompiled, making the compiler faster
# By relying on .c files, everytime all files are recompiled