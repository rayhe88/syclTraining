CC := icx
CFLAGS := -fsycl -Wall -pedantic
LDFLAGS := -lm -lstdc++ -lsycl

OBJS = addVec.o func.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LDFLAGS)

addVec.o: addVec.cpp func.hpp
	$(CC) $(CFLAGS) addVec.cpp -c

func.o: func.cpp func.hpp
	$(CC) $(CFLAGS) func.cpp -c

.Phony: clean
clean:
	rm -f *.o $(EXE)

