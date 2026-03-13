IDIR = ../include  # .h files
CC = clang
CFLAGS = -I$(IDIR)

ODIR = obj  # .o files
LDIR = ../lib

LIBS = -lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~


# What if we want to put .h files in an 'include' directory, source in 'src' directory and local libs in a 'lib' directory?

# Defines paths to the 'include' and 'lib' directories
# Places the .o files in an 'obj' subdirectory within the src directory
# It also has a macro defined for any libraries you want to include, such as the math library -lm

# This makefile should be located in the 'src' directory

# 'patsubst' → creates the full path

# src/ → all .c files
# include/ → all .h files
# obj/ → all .o files
# bin/ → executable
# lib/ → other compiled libraries


# It also includes a rule for cleaning up your source and object directories if you type make clean
# The .PHONY rule keeps Make from doing something with a file named clean (if you have a file with that same name)
# 'make clean' → erases all .o files and all temporary files
# You can add multiple rules to a makefile; you can even create rules that call other rules


# Another way to create the PATH
_DEPS = hellomake.h
DEPS = $(addprefix ../include/,$(_DEPS))