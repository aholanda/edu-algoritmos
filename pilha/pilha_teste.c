/* 
   versao: 20160402 
   programa para testar a implementacao da pilha.
   simplesmente empilha e desempilha chaves fornecidas 
   pelo usuario, imprimindo na tela o rasultado.
 */


#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

int main()
{
	int opcao, k;
	Pilha *p;

	p = pilha_cria();
	while (1) {
	menu:
		printf("\n1) Empilha uma chave.\n");
		printf("2) Desempilha a chave.\n");
		printf("3) Sair do programa.\n");
		printf("Entre com a opcao desejada: ");
		scanf("%d", &opcao);

		if (opcao == 1) {
			if (pilha_cheia(p)) {
				printf("\nA pilha esta cheia, desempilhe primeiro.\n");
				goto menu;
			}			

			printf("Entre com o valor inteiro a ser empilhado: ");
			scanf("%d", &k);
			
			pilha_push(p, k);
			printf("\n\tempilha(%d)\n", k);
		} else if (opcao == 2) {
			if (pilha_vazia(p)) {
				printf("\nA pilha esta vazia, empilhe primeiro.\n");
				goto menu;
			} 
			printf("\n\t%d <= desempilha()\n", pilha_pop(p));
		} else if (opcao == 3) {
			goto saida;
		} else {
			printf("\n\tOpcao invalida.\n");
			goto menu;
		}
		
	}
	
saida:
	pilha_libera(p);
	return 0;
}
