set autoscale
set terminal pdf enh color
set style data lines
set output 'sort.pdf'
set title "Funções de custo dos algoritmos de ordenação"
# Axes label
set xlabel 'n'
set ylabel 'f(n)'
# Axes ranges
set xrange [1:100]
f(x) = x*x
g(x) = x*(log10(x)/log10(2))
# Plot
plot f(x) title 'n^2' with lines linestyle 1, \
     g(x) title 'nlog_2n' with lines linestyle 2
