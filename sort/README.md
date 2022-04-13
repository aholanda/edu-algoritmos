# Visualização das funções n<sup>2</sup> e nlog<sub>2</sub>n

Para visualizar o comportamento das funções n<sup>2</sup> e nlog<sub>2</sub>n, execute os comandos:

````
$ git clone git@github.com:ajholanda/edu-alg.git alg
$ cd alg/sort
$ gnuplot sort.gp
$ evince sort.pdf
````

# Comparação entre os algoritmos de ordenação:

* [*insertionsort*](insertion.c);
* [*mergesort*](merge.c);
* [*quicksort*](quick.c).

O programa [](bench.c) armazena o tempo de execução para dos
algoritmos de ordenação para diferentes tamanhos de entrada de dados 
em um arquivo chamada `bench.dat`. Os seguintes comandos podem 
ser executados no `terminal` para a geração dos dados:

````
$ make bench
$ ./bench
````

Um gráfico pode ser construído usando programas que leiam os valores
tabulados em `bench.dat`, tais como o Excel ou LibreOffice Calc, aqui
utilizaremos um `script` pronto para o programa
[`gnuplot`](http://www.gnuplot.info/) que é executado da seguinte
forma:

````
$ gnuplot bench.gp
````

Abra o arquivo pdf gerado usando qualquer visualizador de pdf, aqui usaremos o `evince`:

````
$ evince bench.pdf
````

------------------------------------------
