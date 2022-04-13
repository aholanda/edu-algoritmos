main:  main.c count.c insertion.c merge.c quick.c radix.c
	$(CC) $(CFLAGS) $^ -o $@

bench: bench.c insertion.o merge.o quick.o
	$(CC) $(CFLAGS) -o $@ $^ 

trash += bench bench.dat bench.pdf main sort.pdf

include ../Makefile
