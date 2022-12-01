CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -I.
DEPS = counter.h
OBJ = main.o counter.o

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) a.out