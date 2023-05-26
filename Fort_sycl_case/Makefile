CC := icpx
FC := ifx
CFLAGS := -fsycl -Wall -pedantic
LDFLAGS := -lsycl -lstdc++

OBJS = func_fort.o func.o addVec.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(FC) -fsycl $(OBJS) -o $(EXE)  $(LDFLAGS)

func_fort.o: func_fort.f90
	$(FC)  func_fort.f90 -c

func.o: func.cpp func.hpp
	$(CC) $(CFLAGS) func.cpp -c

addVec.o: addVec.f90
	$(FC) addVec.f90 -c

.Phony: clean
clean:
	rm -f *.o $(EXE) *.mod

