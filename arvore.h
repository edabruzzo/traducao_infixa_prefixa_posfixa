/*

REFERENCIAS:
https://www.ime.usp.br/~pf/algoritmos/aulas/bint.html
https://www.ime.usp.br/~pf/mac0122-2002/aulas/trees.html

Nota��es infixa, posfixa e prefixa.  
A varredura e-r-d (esquerda - raiz - direita ) da �rvore de uma express�o aritm�tica corresponde exatamente � representa��o infixa da express�o.  
A varredura e-d-r (esquerda-direita-raiz) da �rvore de uma express�o aritm�tica corresponde exatamente � representa��o da express�o em nota��o posfixa.  
A a varredura r-e-d (raiz - esquerda - direita ) da �rvore de uma express�o aritm�tica corresponde exatamente � nota��o prefixa.


*/


#include <stdio.h>
#include <stdlib.h>


typedef struct arvoreBinaria{
	
	char info;
	struct arvoreBinaria* sae;//SUB-ARVORE ESQUERDA
	struct arvoreBinaria* sad;//SUB-ARVORE DIREITA 
	
}Arvore;


int vazia(Arvore *a);
Arvore *inicializa();
Arvore *criaArvore();
void imprimeOrdemPrefixa(Arvore *arv);
void imprimeOrdemPosFixa(Arvore *arv);
void imprimeOrdemInfixa(Arvore *arv);
Arvore *libera(Arvore *arv);




int vazia(Arvore *a){
	
	return (a==NULL);
	
}


Arvore *criaArvore(){
	
	Arvore *arv = (Arvore *) malloc(sizeof(Arvore));
	return arv;

}





void imprimeOrdemPrefixa(Arvore *arv){
	
	
	if(!vazia(arv)){
		
		printf("%c", arv->info );//RAIZ = OPERADOR
		imprimeOrdemPrefixa(arv->sae); //OPERANDO ESQUERDA 
		imprimeOrdemPrefixa(arv->sad); //OPERANDO DIREITA
		
	}
	
	
}

void imprimeOrdemPosFixa(Arvore *arv){

	if(!vazia(arv)){
		imprimeOrdemPosFixa(arv->sae);//OPERANDO ESQUERDA
		imprimeOrdemPosFixa(arv->sad);//OPERANDO DIREITA
		printf("%c", arv->info);//RAIZ = OPERADOR
	
	}	
	
}


void imprimeOrdemInfixa(Arvore *arv){
	
	if(!vazia(arv)){
		printf("(");
		imprimeOrdemInfixa(arv->sae);//OPERANDO ESQUERDA
		printf("%c", arv->info); //OPERADOR = RAIZ 
		imprimeOrdemInfixa(arv->sad); //OPERANDO DIREITA 
		printf(")");

	}	
	
}



Arvore *libera(Arvore *arv){
	
	if(!vazia(arv)){
		
		libera(arv->sae);//libera sub-�rvore esquerda
		libera(arv ->sad);//libera sub-�rvore direita
		free(arv);
		
	}
	
	return NULL;
}
