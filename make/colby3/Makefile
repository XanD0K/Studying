CC = clang
CFLAGS = -I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

hellomake: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@  


# All of the include files should be listed as part of the macro DEPS
# All of the object files should be listed as part of the macro OBJ

# $^ → all files after :