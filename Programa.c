/*
REFERÊNCIAS:

https://www.ime.usp.br/~pf/mac0122-2002/aulas/trees.html
https://pt.stackoverflow.com/questions/311999/estrutura-de-dados-express%C3%B5es-aritm%C3%A9ticas
https://slideplayer.com.br/slide/2694123/

https://www.ime.usp.br/~pf/mac0122-2002/aulas/stacks.html
https://www.cin.ufpe.br/~garme/public/(ebook)Estruturas%20de%20Dados%20Usando%20C%20(Tenenbaum).pdf
http://www.maxpezzin.com.br/aulas/2_ESW_Estruturas_de_Dados/Pesquisa/apostila_estruturas_dados.pdf
https://www.ime.usp.br/~pjssilva/disciplinas/2009/mac122/codigo/pilha/
https://www.tutorialspoint.com/cprogramming/c_memory_management.htm
https://www.ic.unicamp.br/~lehilton/mc202de/09-unidade-pilhaaplicacao.pdf
https://www.ic.unicamp.br/~lehilton/mc202de/
https://document.onl/documents/estrutura-de-dados-i-campus-de-santo-a-oberarquivosdisciplinasestruturaiisiapostila.html
http://www.ic.uff.br/~ferraz/EDI/Ppt/P05ExpressoesAritmeticas1.ppt


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
	converterExpressaoAritmetica(expressaoINFIXA);	
	converterExpressaoAritmetica(expressaoPOSFIXA);	
	
	
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
	
	int i = 0;
	printf("Expressao avaliada :   ");
	for(i; i<strlen(expressaoAvaliada); i++){
		printf("%c", expressaoAvaliada[i]);
	 	expressao[i] = expressaoAvaliada[i];
    	
	}
	printf("\n\n");
	
}
