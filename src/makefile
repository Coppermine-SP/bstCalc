CC=gcc
CFLAGS=-I. -g
DEPS = bst.h calc.h
SRC = bst.c calc.c main.c
OBJ = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bstcalc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o