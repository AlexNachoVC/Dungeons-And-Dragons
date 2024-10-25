# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall --pedantic -Iinclude -Ilib/templates -Ilib/helpers

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Source files
SRCS = $(wildcard $(SRC_DIR)/main.cpp $(SRC_DIR)/game_logic/*.cpp)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Executable
TARGET = $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/game_logic
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full $(TARGET)