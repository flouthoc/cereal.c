CC=gcc
CFLAGS=-Wall -g
OBJ=cereal.o
DEPS=cereal.h

%.o: %.c (DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

test: test.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean cleanall

clean:
	rm *.o test
