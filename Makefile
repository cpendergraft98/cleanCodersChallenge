# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
SRCS = main.cpp ticTacToe.cpp

# Object files
OBJS = main.o ticTacToe.o

# Header files
HEADER = prototypes.h

# Target executable
TARGET = ticTacToe

# Default rule: compile program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.o
main.o: main.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile board.o
ticTacToe.o: ticTacToe.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c ticTacToe.cpp

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
