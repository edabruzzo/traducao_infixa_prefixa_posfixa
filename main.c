/*

REFERÃŠNCIAS:

https://www.ime.usp.br/~pf/mac0122-2002/aulas/stacks.html
https://www.cin.ufpe.br/~garme/public/(ebook)Estruturas%20de%20Dados%20Usando%20C%20(Tenenbaum).pdf
http://www.maxpezzin.com.br/aulas/2_ESW_Estruturas_de_Dados/Pesquisa/apostila_estruturas_dados.pdf
https://www.ime.usp.br/~pjssilva/disciplinas/2009/mac122/codigo/pilha/
https://www.tutorialspoint.com/cprogramming/c_memory_management.htm
https://www.ic.unicamp.br/~lehilton/mc202de/09-unidade-pilhaaplicacao.pdf
https://www.ic.unicamp.br/~lehilton/mc202de/
https://document.onl/documents/estrutura-de-dados-i-campus-de-santo-a-oberarquivosdisciplinasestruturaiisiapostila.html


*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

#define TAMANHO_MAX 100

char expressao[TAMANHO_MAX];


//Declaraçao de funcoes
void convertePosfixa_Infixa(PILHA_DINAMICA *pilha, char expressao[]);
void convertePosfixa_Prefixa(PILHA_DINAMICA *pilha, char expressao[]);
void convertePrefixa_Infixa(PILHA_DINAMICA *pilha, char expressao[]);
void convertePrefixa_Posfixa(PILHA_DINAMICA *pilha, char expressao[]);
void converteInfixa_Prefixa(PILHA_DINAMICA *pilha, char expressao[]);
void converteInfixa_Posfixa(PILHA_DINAMICA *pilha, char expressao[]);
int avaliaPrecedencia(PILHA_DINAMICA *pilha, char operador);



void recebeInput(){
	
	printf("Digite uma expressao aritmetica: \n");
    scanf("%s", &expressao);
    printf("Expressao aritmetica digitada: %s \n", expressao);
	
}



int main(){ 

  int tipoExpressao;

  printf("Digite o tipo de expressao a ser traduzida: \n");
  printf("Digite 0 - PREFIXA\n");
  printf("Digite 1 - INFIXA\n");
  printf("Digite 2 - POSFIXA\n");
  printf("\n\n");
  
  scanf("%d", &tipoExpressao);
  
  PILHA_DINAMICA *pilha =  cria();

  switch(tipoExpressao){
      
      case(0):
      
      recebeInput();
      convertePrefixa_Infixa(pilha, expressao);
      convertePrefixa_Posfixa(pilha, expressao);
	  break;
    
      case(1):
      
      recebeInput(); 
      //converteInfixa_Prefixa(expressao);
      converteInfixa_Posfixa(pilha, expressao);
      break;

      case(2):
   
   	  recebeInput();   
      convertePosfixa_Prefixa(pilha, expressao);
      convertePosfixa_Infixa(pilha, expressao);
      break;
      
      default :
      	 
         printf("Opcao invalida\n" );
         
   }
    
  return 0;
  
}


void convertePosfixa_Infixa(PILHA_DINAMICA *pilha, char expressao[]){
/*
NESTA FUNÇÃO TEREI QUE LER A EXPRESSÃO PÓS-FIXA DA DIREITA PARA A ESQUERDA


*/	

	int i = strlen(expressao);
	
	//operacao de leitura reversa da expressão pos-fixa
	while(expressao[i--] != '/0'){
		
		if('a'<=expressao[i] && expressao[i] <='z' ){
			push(pilha, expressao[i]);
		}else {
			
			
				
				
				
			}
			
			
			
			
		}		
		
		
	}
  
  
  
}



void convertePosfixa_Prefixa(PILHA_DINAMICA *pilha, char expressao[]){
  
  
  
}




void convertePrefixa_Infixa(PILHA_DINAMICA *pilha, char expressao[]){
  
  
  
}


void convertePrefixa_Posfixa(PILHA_DINAMICA *pilha, char expressao[]){
  
  
  
}



void converteInfixa_Posfixa(PILHA_DINAMICA *pilha, char expressao[]){
  
  
  int i;
  char ch;
 
   for (i=0; i<strlen(expressao); i++){
   	
   	  if ('a' <= expressao[i] && expressao[i] <= 'z')
            printf("%c ", expressao[i]);
        else 
            switch (expressao[i]) {
            case '(': 
                push(pilha, expressao[i]); 
                break;
            case ')': 
                while ((ch = pop(pilha)) != '(') 
                    printf("%c ", ch); 
                break; 
            default: 
                while (!vazia(pilha) && avaliaPrecedencia(pilha -> topo -> info) >= avaliaPrecedencia(expressao[i]))
                    printf("%c ", pop(pilha));
                push(pilha, expressao[i]); 
            }
   	
   }

      

    while (!vazia(pilha)) 
        printf("%c ", pop(pilha));
    printf("\n"); 

    libera(pilha);
 

}
  
  
  
 
      
    



void converteInfixa_Prefixa(PILHA_DINAMICA *pilha, char expressao[]){
  
  
  
}



int avaliaPrecedencia(char operador) {
    
 switch (operador) {

    case '(': 
        return 0;
        break;

    case '+': 
    case '-':
        return 1;
        break;

    case '*': 
    case '/': 
        return 2;
        break;

    default:
        printf(stderr, "Operador invalido!\n");
        exit(1);
    }


}
