# Makefile for CLBlackjack

# Compiler
CXX = g++
CXXFLAGS = -std=c++20

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))
DEPS = $(wildcard $(INCDIR)/*.h)

# Executable
EXECUTABLE = CLBlackjack.exe

# Build rules
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCDIR)

.PHONY: clean, run

clean:
	del /Q $(BUILDDIR)\*.o $(EXECUTABLE)

run: $(EXECUTABLE)
	.\$(EXECUTABLE)
