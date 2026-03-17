/*
.h
Declaration files
Inside of them we put prototypes, macros, structs, etc.
Allows that multiple .c files use the same function without repeating code
Best practice is to create one .h file for each .c file, always that .h declares a function (which is implemented on the .c)

Sometimes, .h files don't need a .c version:
- Defining file formats and protocols
- Shared data types
- Constants / Global macros
- Third libraries / Standards


.o
Binary files
Compiled code in binary
Each .c turns into a .o after compilation
*/


/*
Make file
A text file that tells how to build a program


Best practice:

COMPILER FLAGS .c FILES -o NAME
e.g. clang -I. hellomake.c hellofunc.c -o hellomake

But compiler undertand other orientations like:
clang hellomake.c hellofunc.c -o hellomake -I.
clang -o hellomake hellomake.c hellofunc.c -I.
*/


/*
Every Makefile has rules:

TARGET: dependencies
    command1
    command2

The default rule (that will be executed when user types 'make'):
all: program

or just

program:
*/



/*
Phony Targets
Some targets don't generate a file
You must tell Make by using .PHONY
*/


/*
Variables
2 ways to declare them:

CC := gcc
CFLAGS = -Wall

:=  → safer
=   recursive (allows yo use the same variable later on)

FOO = $(BAR)
BAR = hello
In this example, FOO is "hello" when used, even though BAR was declared later

FOO := $(BAR)
BAR = hello
In this example, FOO is empty, because BAR didn't exist on declaration



# Diretórios
IDIR / INCLUDE_DIR = ../include
ODIR / OBJDIR = obj
@mkdir -p $(OBJDIR) → automatically creates de OBJ dir
LDIR / LIBDIR = ../lib
OBJ / SRCDIR = .
BIN / BINDIR

# Compilador e flags
CC       = clang
CPPFLAGS = -I$(INCLUDE_DIR)
CFLAGS   = -Wall -Wextra -Werror -O2 -g
LDFLAGS  =
LIBS / LDLIBS   = -lm

# Arquivos
DEPS / HEADERS  = hellomake.h
SOURCES  = hellomake.c hellofunc.c
OBJECTS  = $(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))
TARGET   = hellomake
*/


/*
Special variables
$@ → target's name
$< → name of firts dependency
$^ → all dependencies
$* → name without sufix
$? → newer dependencies than target
*/



/*
Flags

Warnings (diagnósticos) → ALWAYS USE ON DEVELOPMENT
-Wall -Wextra -Wpedantic → Base → Always needed in most cases → Shows most erros → ALWAYS USE
-Werror / -Werror=return-type → Transform warnings into error → ALWAYS USE
-Weverything → (Clang only) - Too agressive → good for clean new code
-Wconversion → Warns when mixing signed with unsigned, or float with int in a dangerous way
-Wshadow → warns when declaring a variable with the same name as another (shadowing)
-Wnull-dereference → dereference of null pointers
-Wformat-security → protects agains security issues with formated functions (e.g. printf(), sprintf())
-Wno-unused-parameter -Wno-unused-function -Wno-unused-variable → Turns off usual warning
-Wno-unused-but-set-variable → turns off warning for declared but not used variable

-Wunused-function / -Wunused-variable → warns about unused functions/variables

-Wno-padded → USE WITH -Weverything → turns off warnings about paddings (extra spaces added by compiler in memory)

- Wextra → Shows extra errors → Use with -Wall
-pedantic-errors → Treats compiler's extensions (not C default) as errors. Makes you write C in ISO. Warns everything that isn't 100% C


Language Default → ALWAYS USE
-std=c11 / -std=c17 / -std=gnu17 (C) 
-std=c++20 / -std=c++23 / -std=gnu++20 (C++)

-std=c17 → tells the compiler to only accept Cfrom 2017/2018. Use c11 for more compatibility


Otimização
-O0 (debug) → Turns off optimization → Code will be just like you wrote
-Og → Optimization for debug, better than O0 → Use in place of O0 when program gets too slower
-O1 / -O2 / -O3 (release) 
-Os (small size) 
-Ofast → Breaks IEEE (carefull!)


Debug
-g / -g3 / -ggdb / -ggdb3 → Generates debug info on executable
-fno-omit-frame-pointer → Improve stack traces


Sanitizers → Use one per time, carefull when mixing → Makes program slower → Use on DEBUG
Sanitizers add run time verificatio
-fsanitize=address (ASan) → search for memory leaks, buffer overflow, use-after-free
-fsanitize=undefined (UBSan) → numeric logic or bit operations → detects undefined behavios (e.g. overflow with signed integers, invalid shift)
-fsanitize=thread (TSan) → only if uses threads. Detects race conditions in multithreading
-fsanitize=leak → use with -fsanitize-address → detecs memory leaks
-fsanitize=integer → detects overflows and zero divisions by integers

E.g. CFLAGS += -fsanitize=address -g


Outros úteis
-fcolor-diagnostics (color erros) / -fdiagnostics-show-caret → Improve errors' style in terminal
-MMD -MP → Generates .d files automatically → USE IT WITH DEPFLAGS and CPPFLAGS instead of CFLAGS
-march=native / -mtune=native → Improves to CPU
-flto (Link Time Optimization) → Link otimization
*/