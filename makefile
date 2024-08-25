# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Executable name
TARGET = build/main

# Source files
SOURCES = main.c

# Object files
OBJECTS = $(SOURCES:%.c=build/%.o)

# Default target
all: build $(TARGET)

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
