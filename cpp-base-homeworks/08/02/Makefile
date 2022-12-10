all: a.out

INCDIR=inc
ODIR=obj

CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -I$(INCDIR)

_DEPS = figure.h triangle.h rightTriangle.h isosTriangle.h\
		equilTriangle.h quadrilateral.h rectangle.h square.h\
		parallelogram.h rhombus.h exceptions.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ = main.o figure.o triangle.o rightTriangle.o\
	   isosTriangle.o equilTriangle.o quadrilateral.o\
	   rectangle.o square.o parallelogram.o rhombus.o exceptions.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

a.out: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: all clean

clean:
	rm -f $(OBJ) *~ $(INCDIR)*~ a.out