CC := icx
FC := ifort
CFLAGS := -Wall -pedantic -std=c99
FFLAGS := -Wall

OBJS = func_fort.o addVec.o func.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(FC) $(FFLAGS) -o $@ $(OBJS) -lgfortran

func_fort.o: func_fort.f90
	$(FC) $(FFLAGS) func_fort.f90 -c

func.o: func.c func.h
	$(CC) $(CFLAGS) func.c -c

addVec.o: addVec.f90 
	$(FC) $(FFLAGS) addVec.f90 -c

.Phony: clean
clean:
	rm -f *.o $(EXE) *.mod

