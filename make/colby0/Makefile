hellomake: hellomake.c hellofunc.c
	clang -I. hellomake.c hellofunc.c -o hellomake


# -I. → flag that makes compiler look in current directory (.) for the included .h file
# Needed if your #include is with <> instead of ""
# E.g. #include <hellomake.h> instead of #include "hellomake.h"


# You can also state other PATHs insteaad of current directory
# -Iinclude/
# -Isrc/
# -I../headers
# CFLAGS = -Iinclude -I../common -I/usr/local/include


# 'hellomake' is the target
# Target is everything on the left of :
# Rule is the whole block
# Every tule teaches Make how to build that target
# Make always run the first rule in file. That's why the executable rule is always the first one

# You can run any rule manually:
# make hellomake → Executes the executable
# make hellomake.o → compile specific .o file
# make clean → runs 'clean' rule

# Other rules:
# all → runs everything
# clean → cleans .o files and the executable
# test → compiles and runs tests