TGT=main
CXX=g++
CXXFLAGS = -Wall -Wextra -pedantic
MODE ?= 0

$(TGT): $(TGT).cc
	$(CXX) $(CXXFLAGS) -D MODE=$(MODE) $(TGT).cc

clean:
	$(RM) a.out