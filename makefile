# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Ilib -Wextra -g

# Executable name
TARGET = build/main

# Source files
SOURCES = main.c lib/functions_definition.c

# Object files
OBJECTS = $(SOURCES:%.c %lib/.c=build/%.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile .c files to .o files in the build directory
build/%.o: %.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it does not exist
build:
	mkdir -p build

# Clean up build files
clean:
	rm -rf build
