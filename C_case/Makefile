CC := icx
CFLAGS := -Wall -pedantic -std=c99
LDFLAGS := -lm

OBJS = addVec.o func.o

EXE = addVec.x

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LDFLAGS)

addVec.o: addVec.c func.h
	$(CC) $(CFLAGS) addVec.c -c

func.o: func.c func.h
	$(CC) $(CFLAGS) func.c -c

.Phony: clean
clean:
	rm -f *.o $(EXE)

