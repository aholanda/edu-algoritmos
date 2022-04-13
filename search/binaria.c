/* Esta funcao recebe um vetor crescente $v[0..N-1]$
   com $N\geq 1$ e um inteiro $k$. Ela retorna um indice
   $i$ em $0\leq i\leq N-1$, se a chave for encontrada, 
   caso contrario retorna -1. */
int BuscaBinaria(int k, int N, int v[])
{
	int e, m, d;		/* esquerda, meio, direita */
	e = -1;
	d = N;
	while (e <= d) {
	  m = e + (d - e) / 2; /* evita estouro de capacidade do tipo */
	  if (k > v[m])
	  	e = m + 1;
	  else if (k < v[m])
		d = m - 1;
	  else 
		return m;
	}
	return -1;
}
