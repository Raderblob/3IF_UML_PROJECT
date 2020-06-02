
CC = g++
DEBUG=no
ifeq ($(DEBUG),yes)
	CFLAGS=-Wall -ansi -pedantic -std=c++11 -g -D MAP
	LDFLAGS=
else
	CFLAGS=-Wall -ansi -pedantic -std=c++11 -O3
	LDFLAGS=
endif
EXEC = bin/GLProject(name of executable)
SRC= AirCleaner.cpp AirQualityData.cpp AirQualityManager.cpp CompanyEmployee.cpp Coordinate.cpp GLProject.cpp GovEmployee.cpp PrivateIndividual.cpp Sensor.cpp User.cpp UserManager.cpp Util.cpp QuadTree.cpp Reading.cpp
OBJ= $(SRC:.cpp=.o)
HEDR = $(SRC:.cpp=.h)


all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif
	rm -rf *.o
	@echo "The dataset needs to be the in the working dir of the cmd that launches the executable"


$(EXEC): $(OBJ)
	mkdir -p bin
	g++ -o $@ $^ $(LDFLAGS)


GLProject.o: GLProject.cpp
	g++ -c $< $(CFLAGS)

%.o: %.cpp %.h
	g++ -c $< $(CFLAGS)

.PHONY = clean

clean:
	rm -rf *.o
