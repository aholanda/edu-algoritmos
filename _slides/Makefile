VPATH = ../search ../fila ../pilha ../sort

main.pdf: main.tex
	-lualatex $<
	-lualatex $<

main.tex: buscasequencial.tex buscabinaria.tex pilha.tex insertionsort.tex mergesort.tex

insertionsort.tex: insertion.c shell.c

buscasequencial.tex: busca.h sequencial.c

buscabinaria.tex: binaria.c

pilha.tex: pilha.h

%.h: ../search
