CXX = g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++11
LDFLAGS="-Wl,-rpath=."

RELDIR = ../../06/03

_DEPS = figure.h triangle.h rightTriangle.h isosTriangle.h\
		equilTriangle.h quadrilateral.h rectangle.h square.h\
		parallelogram.h rhombus.h
DEPS = $(patsubst %,$(RELDIR)/%,$(_DEPS))

_OBJ = figure.o triangle.o rightTriangle.o\
	   isosTriangle.o equilTriangle.o quadrilateral.o\
	   rectangle.o square.o parallelogram.o rhombus.o
OBJ = $(patsubst %,$(RELDIR)/%,$(_OBJ))

LIB_NAME = figures
LIB = $(LIB_NAME).so
ELF = a.out

$(ELF): $(LIB)
	$(CXX) -o $@ main.cc -L. -l:$^ $(LDFLAGS)

$(LIB): $(OBJ)
	$(CXX) -shared -o $@ $^

$(RELDIR)/%.o: $(RELDIR)/%.cc $(DEPS)
	$(CXX) -c -fpic -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f *.out *.so *.o $(RELDIR)/*.o