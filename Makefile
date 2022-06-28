CC=gcc
CFLAGS=-I.
DEPS = linkedlist.h
OBJ = linkedlist.o tester.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o 
