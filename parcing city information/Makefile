# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list your .h files here
HEADERS =

# list .cpp files here according to main program, tests, or both
PROGRAM_FILES = main.cpp
TEST_FILES = tests.cpp
SHARED_FILES = postNetFunctions.cpp

.PHONY: all
all: program.exe tests.exe

program.exe: $(PROGRAM_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) $(SHARED_FILES) -o $@

tests.exe: $(TEST_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SHARED_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe tests.exe
