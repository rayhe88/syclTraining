CC := icpx
CFLAGS :=  -fsycl -Wall 
LDFLAGS := -lm -lsycl

OBJS = func.o addVec.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -fsycl $(OBJS) -o $(EXE) $(LDFLAGS)

addVec.o: addVec.cpp func.hpp
	$(CC) $(CFLAGS) addVec.cpp -c

func.o: func.cpp func.hpp
	$(CC) $(CFLAGS) func.cpp -c

.Phony: clean
clean:
	rm -f *.o $(EXE)

