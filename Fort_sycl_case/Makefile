CC := icx
FC := ifort
CFLAGS := -fsycl -Wall -pedantic
LDFLAGS := -lm -lstdc++ -lsycl

OBJS = func_fort.o addVec.o func.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(FC) $(OBJS) -o $(EXE) -lgfortran  $(LDFLAGS)

func_fort.o: func_fort.f90
	$(FC) $(FFLAGS) func_fort.f90 -c

func.o: func.cpp func.hpp
	$(CC) $(CFLAGS) func.cpp -c

addVec.o: addVec.f90 
	$(FC) $(FFLAGS) addVec.f90 -c  $(LDFLAGS)

.Phony: clean
clean:
	rm -f *.o $(EXE) *.mod

