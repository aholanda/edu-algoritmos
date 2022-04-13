/*
  Author: Adriano J. Holanda 
  Version: 20160406 
  
  Este programa testa, usando uma pilha, se uma sequencia de chaves e
  parenteses é bem-formada. A sequencia 
         {(){{()}}
  eh bem-formada enquanto que 
         {(})
  eh mal-formada.
  A ideia foi baseada no livro Algoritmos em C de Feofiloff, capitulo 6.
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

#define TAM_BUF 128 /* tamanho do buffer */

int main()
{
  char seq[TAM_BUF];
  int n, i, c;
  Pilha *pil;

  pil = pilha_cria();

  printf("Nao insira espacos para a sequencia a seguir!\n");
  printf("Entre com a sequencia de parenteses e chaves: ");
  n = scanf("%s", seq);
  if (n == 0) {
    printf("A sequencia esta vazia!\n");
    goto saida;
  } else {
    for (i = 0; seq[i] != '\0'; i++) {
      switch(seq[i]) {
      case '(':
	pilha_push(pil, '(');
	break;
      case '{':
	pilha_push(pil, '{');
	break;
      case ')':
	if (pilha_vazia(pil))
	  goto mal_formada;

	c = pilha_pop(pil);
	if (c != '(')
	  goto mal_formada;
	break;
      case '}':
	if (pilha_vazia(pil))
	  goto mal_formada;

	c = pilha_pop(pil);
	if (c != '{')
	  goto mal_formada;
	break;
      default:
	printf("Erro, caracter invalido: %c\n", seq[i]);
	goto saida;
	break;
      }
    }
  }

  if (pilha_vazia(pil)) {
    printf("A sequencia eh bem-formada!\n");
    goto saida;
  }
  
 mal_formada:
  printf("A sequencia eh mal-formada!\n");

 saida:
  pilha_libera(pil);
  return 0;
}
