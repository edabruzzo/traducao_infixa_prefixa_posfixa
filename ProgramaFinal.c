
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvoreTESTE.h"
#include "pilha.h"

#define TAMANHO_MAX 100

char expressao[TAMANHO_MAX];

void recebeInput();
Arvore* montarArvoreBinaria(char expressao[]);
Arvore * montarArvorePrefixa(expressao){
int avaliaPrecedencia(char operador);
int determinarTipoExpressao(char expressao[]);
int ehOperador(char c);
int ehOperando(char c);



int main(){
	
	recebeInput();
	Arvore *arvore = montarArvoreBinaria(expressao);
	
	
	return 0;
}


Arvore* montarArvoreBinaria(char expressao[]){
	
	/*
	
	REFERENCIAS:
	https://www.ime.usp.br/~song/mac5710/slides/05tree
	https://web.fe.up.pt/~rcamacho/cadeiras/bioinformatica/docs/arvores.pdf
	https://www.ime.uerj.br/~pauloedp/ESTD/Download/EDAP2006.pdf
	
	
	
	CHEGOU UMA EXPRESSAO E NESTE PONTO EU NÃO SEI EM QUAL NOTAÇÃO ELA ESTA
	QUERO MONTAR A ARVORE BINARIA A PARTIR DE QUALQUER NOTACAO
	
	+*1+23*2-41
	1*(2+3)+(2*(4-1))
	123+*241-*+
	
	*/
	
	int tipoExpressao;
	tipoExpressao = determinarTipoExpressao(expressao);
	
	Arvore *arvore;
	
	switch(tipoExpressao){
		
		//prefixa
		case(0):

			arvore = montarArvorePrefixa(expressao);



			break;
		
		
		
		
	}
	
	
	return NULL;
}


Arvore* montarArvorePrexixa(expressao){
	
	
	//  *+a**bc+def
	//	+*1+23*2-41
	
	PILHA_DINAMICA* pilhaOperadores = cria();
	PILHA_DINAMICA* pilhaOperandos = cria();
	PILHA_ARVORES* pilhaArvores = criaPilhaArvores();
	
	for(i=0; i<strlen(expressao); i++)){
		
			if(ehOperador(expressao[i]))
			push(pilhaOperadores, cria(expre));
	if(ehOperando(expressao[i]))
			push(pilhaOperandos, expressao[i]);
			
	}
	
	
	
	return arvore;
}




int determinarTipoExpressao(char expressao[]){
	
	
	int i;
	int tipoExpressao;
	//laço para leitura dos dois primeiros caracteres da expressao
	for(i=0; i< 2; i++){
		
		/*
		0 = prefixa
		1 = infixa 
		2 = posfixa
				
		*/
		//dois operadores seguidos prefixa
		if(ehOperador(expressao[0]))
			tipoExpressao = 0;
				
		//operandos e operador seguidos = infixa		
	    else if(ehOperando(expressao[i]) && ehOperador(expressao[i+1])
			tipoExpressao = 2;

		//dois operandos seguidos = posfixa		
	    else if(ehOperando(expressao[i]) && ehOperando(expressao[i+1])
			tipoExpressao = 2;
			
		
	}
	
	return tipoExpressao;
	
	
}


void recebeInput(){
	
	printf("Digite uma expressao aritmetica: \n");
    scanf("%s", &expressao);
    printf("Expressao aritmetica digitada: %s \n", expressao);
	
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
        fprintf(stderr, "Operador invalido!\n");
        exit(1);
    }
    
}


int ehOperador(char c){
	
	return(c=='+' || c=='-' || c=='*'|| c=='/');
}


int ehOperando(char c){
	return ('a' <= c && c <= 'z');
}



