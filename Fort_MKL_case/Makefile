CC := icpx
FC := ifx
CFLAGS := -fsycl -std=c++17 -Wall -pedantic
LDFLAGS := -lsycl -lstdc++ -lmkl_sycl -lmkl_intel_ilp64 -lmkl_sequential -lmkl_core

OBJS = func_fort.o func.o addVec.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(FC) -fsycl  $(OBJS) -o $(EXE)  $(LDFLAGS)

func_fort.o: func_fort.f90
	$(FC)  func_fort.f90 -c

func.o: func.cpp func.hpp
	$(CC) $(CFLAGS) func.cpp -c

addVec.o: addVec.f90
	$(FC) addVec.f90 -c

.Phony: clean
clean:
	rm -f *.o $(EXE) *.mod

