ELF = a.out

all: dirs $(ELF)

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -g\
		   -I include\
		   -I include/air\
		   -I include/ground

LDFLAGS="-Wl,-rpath=."
MKDIR_P = mkdir -p

_DEPS_GROUND_DIR = include/ground
_DEPS_AIR_DIR = include/air
_DEPS_OTHER_DIR = include

_DEPS_GROUND = ground.h camel.h camelSpeed.h centaur.h terrainBoots.h
_DEPS_AIR = air.h broom.h carpetPlane.h eagle.h
_DEPS_OTHER = race.h racepool.h transport.h

DEPS_AIR = $(patsubst %,$(_DEPS_AIR_DIR)/%,$(_DEPS_AIR))
DEPS_GROUND = $(patsubst %,$(_DEPS_GROUND_DIR)/%,$(_DEPS_GROUND))
DEPS_OTHER = $(patsubst %,$(_DEPS_OTHER_DIR)/%,$(_DEPS_OTHER))

OBJ_DIR = obj

_OBJ_GROUND = race.o racepool.o transport.o ground.o camel.o camelSpeed.o centaur.o terrainBoots.o
_OBJ_AIR = air.o broom.o carpetPlane.o eagle.o
_OBJ_OTHER = race.o racepool.o transport.o

OBJ_GROUND = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ_GROUND))
OBJ_AIR = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ_AIR))
OBJ_OTHER = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ_OTHER))

LIB_NAME = race
LIB_DIR = lib
LIB = $(LIB_DIR)/$(LIB_NAME).so

SRC_GROUND = sources/ground
SRC_AIR = sources/air
SRC_OTHER = sources


dirs:
	${MKDIR_P} $(LIB_DIR)
	${MKDIR_P} $(OBJ_DIR)


$(ELF): $(LIB)
	$(CXX) -o $@ main.cc -L. -l:$^ $(LDFLAGS) $(CXXFLAGS)

$(LIB): $(OBJ_GROUND) $(OBJ_AIR) $(OBJ_OTHER)
	$(CXX) -shared -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_GROUND)/%.cc $(DEPS_GROUND)
	$(CXX) -c -fpic -o $@ $< $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_AIR)/%.cc $(DEPS_AIR)
	$(CXX) -c -fpic -o $@ $< $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_OTHER)/%.cc $(DEPS_OTHER)
	$(CXX) -c -fpic -o $@ $< $(CXXFLAGS)


.PHONY: clean

clean:
	rm -f $(OBJ_GROUND) $(OBJ_AIR) $(OBJ_OTHER) $(ELF) $(LIB)
	rm -rf $(LIB_DIR) $(OBJ_DIR)