CXXFLAGS=-Wall -Wextra -pedantic -std=c++11
INC=greeter.h
LIB_NAME=greeter
LIB=$(LIB_NAME).a
ELF=a.out

$(ELF): $(LIB)
	$(CXX) -o $@ main.cc -L. -l:$^
	rm -f *.o

$(LIB): $(LIB_NAME).o
	ar rcs $@ $^

$(LIB_NAME).o: $(LIB_NAME).cc $(INC)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f *.a *.o *.out