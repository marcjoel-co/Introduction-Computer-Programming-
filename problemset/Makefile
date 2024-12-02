# File: Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files and their corresponding executables
SOURCES = \
    p1_odd_even.c \
    p2_pos_net_zero.c \
    p3_grade_class.c \
    p4_largest_three.c \
    p5_leap_year.c \
    p6_simple_calc.c \
    p7_tringle_type.c

EXECUTABLES = \
    p1_odd_even \
    p2_pos_net_zero \
    p3_grade_class \
    p4_largest_three \
    p5_leap_year \
    p6_simple_calc \
    p7_tringle_type

# Default target to build all executables
all: $(EXECUTABLES)

# Generic rule to build each executable
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove all executables
clean:
	rm -f $(EXECUTABLES)

# Phony targets

.PHONY: all clean
