# Compiler and options  
CXX = g++  
CXXFLAGS = -Wall -std=c++14  
LATEX = pdflatex  
  
# Files  
EXECUTABLE = List  
SOURCES = List.h List.cpp  
OBJECTS = $(SOURCES:.cpp=.o)  
TEXFILE = report.tex  
  
# Default target  
all: $(EXECUTABLE)  
  
# Compile and link C++ program  
$(EXECUTABLE): $(OBJECTS)  
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@  
  
# Compile C++ sources to objects  
%.o: %.cpp  
	$(CXX) $(CXXFLAGS) -c $< -o $@  
  
# Target to compile LaTeX document to PDF  
report: $(TEXFILE)  
	$(LATEX) $(TEXFILE)  
	$(LATEX) $(TEXFILE)  # Run twice if needed for references  
  
# Clean up objects, executables, and LaTeX generated files  
clean:  
	rm -f $(OBJECTS) $(EXECUTABLE) report.pdf report.aux report.log report.out  
  
# Phony targets  
.PHONY: all report clean  
