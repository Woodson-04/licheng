# Compiler and options
CXX = g++
CXXFLAGS = -g -Wall -std=c++14 -O2
LATEX = xelatex

# Files
EXECUTABLE = expression_evauator
SOURCES = main.cpp
HEADERS = expression_evaluator.h
OBJECTS = $(SOURCES:.cpp=.o)
TEXFILE = report.tex
PDF_REPORT = report.pdf

# Default target
all: $(EXECUTABLE) report

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
	mv $(TEXFILE:.tex=.pdf) $(PDF_REPORT)

# Clean up objects, executables, and LaTeX generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(PDF_REPORT) $(TEXFILE:.tex=.aux) $(TEXFILE:.tex=.log) $(TEXFILE:.tex=.out)

# Phony targets
.PHONY: all run report clean