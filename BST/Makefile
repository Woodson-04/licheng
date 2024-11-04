# Compiler and options
CXX = g++
CXXFLAGS = -Wall -std=c++14
LATEX = pdflatex

# Files
EXECUTABLE = BinarySearchTree
SOURCES = BinarySearchTree.h main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEXFILE = report.tex
PDF_REPORT = report.pdf

# Default target
all: $(EXECUTABLE)

# Compile and link C++ program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile C++ sources to objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target to run the program and display the test results
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Target to compile LaTeX document to PDF
report: $(TEXFILE)
	$(LATEX) $(TEXFILE)
	$(LATEX) $(TEXFILE)  # Run twice if needed for references
	mv report.pdf $(PDF_REPORT)

# Clean up objects, executables, and LaTeX generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(PDF_REPORT) report.aux report.log report.out

# Phony targets
.PHONY: all run report clean