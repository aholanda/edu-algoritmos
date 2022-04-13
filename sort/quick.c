/* particiona() recebe um vetor v[inf..sup] com inf<=sup. Rearranja os
   elementos do vetor e devolve j em inf..sup tal que 
   v[inf..j-1] <= v[j] < v[j+1..sup]. Author: Bob Sedgewick. */
long particiona(long v[], long inf, long sup) {
	long i=inf, j=sup+1;
	long t /* temporaria */, x = v[inf]; /* seleciona pivo */

	while (1) {
		while(v[++i] < x)
			if (i==sup)
				break; /*i->*/
		while(x < v[--j])
			if (j==inf)
				break; /*<-j*/
             
		if (i>=j)
			break; 
		t = v[j], v[j] = v[i], v[i] = t; /*i<->j*/
	}
	v[inf] = v[j], v[j] = x; /*inf<->j */

	return j;
}

/** quicksort() seleciona um pivoh usando a funcao particiona() e
    recursivamente aplica o mesmo procedimento nos 2 subvetores com
    elementos maiores e menores que o pivoh cada. */
void quicksort(long v[], long inf, long sup) {
	long p;

	if (inf<sup) {
		p = particiona(v, inf, sup);
		quicksort(v, inf, p-1);
		quicksort(v, p+1, sup);
	}
}


