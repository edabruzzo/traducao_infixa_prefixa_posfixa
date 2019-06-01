/*
REFERÊNCIAS:

https://www.ime.usp.br/~pf/mac0122-2002/aulas/trees.html
https://pt.stackoverflow.com/questions/311999/estrutura-de-dados-express%C3%B5es-aritm%C3%A9ticas



*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define TAMANHO_MAX 100


int i;

Arvore * montaArvoreBinaria();
int ehOperador(char c);

char expressao[] = {'*','+','a','*','*','b','c','+','d','e','f'};

int main(){
	
	
	Arvore *arvore = montaArvoreBinaria(expressao);
	imprimeOrdemPrefixa(arvore);
	printf("\n");
	imprimeOrdemInfixa(arvore);
	printf("\n");
	imprimeOrdemPosFixa(arvore);
	printf("\n");
	
}


Arvore * montaArvoreBinaria(){
	
	
	char t;
    

    t = expressao[i++];
    Arvore *arvore = criaArvore(); 
    arvore->info = t;
    if (ehOperador(t)) {
        arvore->sae = montaArvoreBinaria();
        arvore->sad = montaArvoreBinaria();
    }else 
		arvore->sae = arvore->sad = NULL;
    return arvore;
	
	
}


int ehOperador(char c){
	
	return(c=='+' || c=='-' || c=='*'|| c=='/');
}

