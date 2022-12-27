CXXFLAGS=-Wall -Wextra -pedantic -std=c++11
LDFLAGS="-Wl,-rpath=."
INC=leaver.h
LIB_NAME=leaver
LIB=$(LIB_NAME).so
ELF=a.out

$(ELF): $(LIB)
	$(CXX) -o $@ main.cc -L. -l:$^ $(LDFLAGS)

$(LIB): $(LIB_NAME).o
	$(CXX) -shared -o $@ $^

$(LIB_NAME).o: $(LIB_NAME).cc $(INC)
	$(CXX) -c -fpic -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f *.out *.so *.o