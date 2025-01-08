# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files (all .cpp files in the directory)
SRCS = $(wildcard *.cpp)

# Executables (replace .cpp with no extension)
EXES = $(SRCS:.cpp=)

# Rule to build all executables
all: $(EXES)

# Rule to build each executable from its source
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean rule to remove all executables
clean:
	rm -f $(EXES)

# PHONY targets
.PHONY: all clean
