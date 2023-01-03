CC=gcc
FLAGS= -Wall -g

all: isort txtfind

isort: isort_main.o sorter.o
	$(CC) $(FLAGS) -o $@ $^

txtfind: txtfind_main.o finder.o
	$(CC) $(FLAGS) -o $@ $^

sorter.o: sorter.c sorter.h
	$(CC) $(FLAGS) -c $<

finder.o: finder.c finder.h
	$(CC) $(FLAGS) -c $<

isort_main.o: isort_main.c sorter.h
	$(CC) $(FLAGS) -c $<

txtfind_main.o: txtfind_main.c finder.h
	$(CC) $(FLAGS) -c $<

.PHONY: c clean all

c: clean

clean:
	rm -f *.o isort txtfind