set autoscale
set terminal pdf enh color
set style data lines
set logscale y 2
set output 'bench.pdf'
set title "Comparação dos algoritmos de ordenação"
set xlabel 'N'
set ylabel 't (ms)'
plot 'bench.dat' using 1:2 title 'insertionsort()', \
     '' using 1:3 title 'mergesort()', \
     '' using 1:4 title 'quicksort()'
