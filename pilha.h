/*
Referências:
https://www.ic.unicamp.br/~lehilton/mc202de/08-unidade-pilhafila.pdf
https://www.ime.usp.br/~pjssilva/disciplinas/2009/mac122/codigo/pilha/
https://www.cos.ufrj.br/~rfarias/cos121/pilhas.html

*/


#include <stdio.h>
#include <stdlib.h>


 typedef struct no{
 
   	char info;
	struct no *proximo;
 
 } NO;

 typedef struct pilha{
 NO *topo;
 } PILHA_DINAMICA;



PILHA_DINAMICA *criaPilha(void){

  PILHA_DINAMICA *p = (PILHA_DINAMICA*) malloc(sizeof(PILHA_DINAMICA));
  p-> topo = NULL;
  return p;

}


NO *insere(NO* lista, char valor){
  
  
  NO* novo_no = (NO*) malloc(sizeof(NO));
  novo_no -> info = valor;
  novo_no -> proximo = lista;
  return novo_no;
  
  
}



NO* retira(NO* lista){

  NO* aux = lista;
  lista = aux-> proximo;
  free(aux);
  return lista;

}


void push(PILHA_DINAMICA *p, char valor){
  
  p-> topo = insere(p->topo, valor);
  
}


int pilhaVazia(PILHA_DINAMICA *p){
  
  return(p->topo == NULL);
  
}


char pop(PILHA_DINAMICA *p){
  
  char valor;
  if(pilhaVazia(p)){
    
    printf("A Pilha esta vazia.\n");
    exit(1);
    
  }
  
  valor = p->topo->info;
  p->topo = retira(p->topo);
  
  return valor;

}


void liberaPilha(PILHA_DINAMICA *p){
  
  NO *q = p->topo;
  
  while(q !=NULL){
    
    NO *t = q-> proximo;
    free(q);
    q = t;
    
  }
  
  free(p);

}
