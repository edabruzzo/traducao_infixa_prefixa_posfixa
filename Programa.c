/*
REFERÊNCIAS:

https://www.ime.usp.br/~pf/mac0122-2002/aulas/trees.html
https://pt.stackoverflow.com/questions/311999/estrutura-de-dados-express%C3%B5es-aritm%C3%A9ticas



*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"
# define TAMANHO_MAX 100

Arvore * montaArvoreBinaria();
char expressao[TAMANHO_MAX];
void converterExpressaoAritmetica(char expressaoAvaliada[]);
void atribuirValorExpressaoGlobal(char expressaoAvaliada[]);
int ehOperador(char c);
int i;

/*

  infixa  	(a+(b*c)*(d+e))*f
  posfixa  	abc*de+*+f*
  prefixa  	*+a**bc+def

*/

//  prefixa  *+a**bc+def
char expressaoPREFIXA[] = {'*','+','a','*','*','b','c','+','d','e','f'};

//infixa  	(a+(b*c)*(d+e))*f
char expressaoINFIXA[] =  {'(','a','+','(','b','*','c',')','*','(','d', '+', 'e', ')', ')', '*', 'f'};

// posfixa  	abc*de+*+f*
char expressaoPOSFIXA[] = {'a', 'b', 'c', '*', 'd', 'e', '+', '*', '+', 'f', '*'};




int main(){
	
	converterExpressaoAritmetica(expressaoPREFIXA);	
	
	/*
	
	Arvore *arvoreINFIXA = montaArvoreBinaria(expressaoINFIXA);
	imprimeOrdemPrefixa(arvoreINFIXA);
	printf("\n");
	imprimeOrdemInfixa(arvoreINFIXA);
	printf("\n");
	imprimeOrdemPosFixa(arvoreINFIXA);
	printf("\n");
	

	Arvore *arvorePOSFIXA = montaArvoreBinaria(expressaoPOSFIXA);
	imprimeOrdemPrefixa(arvorePOSFIXA);
	printf("\n");
	imprimeOrdemInfixa(arvorePOSFIXA);
	printf("\n");
	imprimeOrdemPosFixa(arvorePOSFIXA);
	printf("\n");

*/
	
	
}


void converterExpressaoAritmetica(char expressaoAvaliada[]){
	
	atribuirValorExpressaoGlobal(expressaoAvaliada);
	Arvore *arvore = montaArvoreBinaria();
	printf("EXPRESSAO ARITMETICA EM ORDEM PREFIXA: ");
	imprimeOrdemPrefixa(arvore);
	printf("\n\n");
	printf("EXPRESSAO ARITMETICA EM ORDEM INFIXA: ");
	imprimeOrdemInfixa(arvore);
	printf("\n\n");
	printf("EXPRESSAO ARITMETICA EM ORDEM POSFIXA: ");
	imprimeOrdemPosFixa(arvore);
	printf("\n\n");

	
}


Arvore * montaArvoreBinaria(){
	
	char t;
	Arvore *arvore = criaArvore(); 

	t = expressao[i++];	
    arvore->info = t;
    
    if (ehOperador(t)) {
        arvore->sae = montaArvoreBinaria();
        arvore->sad = montaArvoreBinaria();
    }else arvore->sae = arvore->sad = NULL;

	return arvore;
		
}


int ehOperador(char c){
	
	return(c=='+' || c=='-' || c=='*'|| c=='/');
}



void atribuirValorExpressaoGlobal(char expressaoAvaliada[]){
	
	int i;
	printf("Expressao avaliada :   ");
	for(i=0; i<strlen(expressaoAvaliada); i++){
		printf("%c", expressaoAvaliada[i]);
	 	expressao[i] = expressaoAvaliada[i];
    	
	}
	printf("\n\n");
	
}
