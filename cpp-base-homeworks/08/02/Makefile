CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -I.

DEPS = figure.h triangle.h rightTriangle.h isosTriangle.h equilTriangle.h\
	   quadrilateral.h rectangle.h square.h parallelogram.h rhombus.h exceptions.h

OBJ = main.o figure.o triangle.o rightTriangle.o isosTriangle.o equilTriangle.o\
	  quadrilateral.o rectangle.o square.o parallelogram.o rhombus.o exceptions.o

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) a.out