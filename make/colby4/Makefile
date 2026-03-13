IDIR = ../include
CC = clang
CFLAGS = -I$(IDIR)

ODIR = obj
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


# What if we want to put .h files in an 'include' directory, source in 'src' directory and local libs in a 'lib directory?

# Defines paths to the 'include' and 'lib' directories
# Places the object files in an 'obj' subdirectory within the src directory
# It also has a macro defined for any libraries you want to include, such as the math library -lm

# This makefile should be located in the 'src' directory

# It also includes a rule for cleaning up your source and object directories if you type make clean
# The .PHONY rule keeps make from doing something with a file named clean
# You can add multiple rules to a makefile; you can even create rules that call other rules