CC = clang
CFLAGS = -I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o
	$(CC) hellomake.o hellofunc.o -o hellomake


# DEPS → the set of .h files on which the .c files depend

# %.o: %.c $(DEPS) → rule applied to all files ending with .o
# %.c → .c file with same name
# That rule says that -o file depends upon the .c version of the file and the .h files included in DEPS macro
# In other words: To generate any .o file, relies on its correspondent .c file + all headders defined on DEPS
# The rule then says that to generate .o file, make need to compile the .c file using the compiler definde in CC macro
# That rule is just to generate the .o files


# $@ $< → are the left and right sides of the :, respectively


# -c → flag to generate the object file
# -o $@ → put the output of the compilation in the file named on the left side of the :
# $< → the first item in the dependencies list
# Wants to build hellomake.o
# Target ($@) is hellomake.o
# Its dependency (the file that generated that .o file) is hellomkae.c → $<

# Again, compiler will understand any order:
# -c -o $@ $<
# -c $< -o $@