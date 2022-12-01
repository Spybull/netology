CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -I.
DEPS = mathfunc.h
OBJ = main.o mathfunc.o

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) a.out