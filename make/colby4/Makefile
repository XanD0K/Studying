# ====================== DIRECTORIES ======================
INCLUDE_DIR = ../include   # where .h files live
OBJDIR      = obj          # where .o files will be placed
LIBDIR      = ../lib       # (optional - for your own .a libraries)

# ====================== COMPILER AND FLAGS ======================
CC       = clang
CPPFLAGS = -I$(INCLUDE_DIR)          # headers + defines only (-I, -D, etc.)
CFLAGS   = -Wall -Wextra -Werror -O2 -g   # compiler warnings, optimization, debug
LDFLAGS  =                           # linker flags (-L, etc.) - empty for now
LDLIBS   = -lm                       # libraries to link (-lm = math library)

# ====================== SOURCE FILES ======================
# List of headers (without path)
_HEADERS = hellomake.h

# Full path to headers
HEADERS  = $(addprefix $(INCLUDE_DIR)/,$(_HEADERS))

# List of source files (.c)
SOURCES  = hellomake.c hellofunc.c

# Object files with full path
OBJECTS  = $(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))

# Final executable name
TARGET   = hellomake

# ====================== BUILD RULES ======================

# Pattern rule: how to compile each .c → .o
$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJDIR)                  # create obj/ folder if it doesn't exist
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

# Link rule: build the final executable
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# ====================== CLEAN ======================
.PHONY: clean

clean:
	rm -rf $(OBJDIR) *~ core


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