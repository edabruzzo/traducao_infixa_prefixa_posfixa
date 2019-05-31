/*

REFERENCIA: 

https://sites.google.com/a/liesenberg.biz/cjogos/home/materiais-de-apoio/topicos-relativos-a-c/estruturas-encadeadas/converso-de-expresso-posfixa-para-prefixa


*/

#include <stdio.h>
#include <stdlib.h>
 
typedef enum {FALSE = 0, TRUE = 1} boolean;
typedef enum {FOLHA, NO} tipoNo;
typedef enum {INVALIDO, PILHA_VAZIA, OPERADOR, OPERANDO, FIM} tipoResultado;

struct elemento;

struct noArvore{
    tipoNo tipo;
    union
    {
        char valor;  // Folha
        struct noBinario
        {
            struct noArvore *esquerdo;
            char operador;
            struct noArvore *direito;
        } info;
   };
};
 
struct elemento
 {
     struct noArvore *no;
     struct elemento *prox;
 };
 
tipoResultado obterSimbolo(struct noArvore **ppRaiz){
   
    char valor;
    int i;
    //INSERE UM DELIMITADOR DO FIM DA EXPRESSÃO DE ENTRADA
    strcat(expressao, '#');
   
     if (expressao[i] >= 'a' && expressao[i] <= 'z'){
       
        *ppRaiz = (struct noArvore *)malloc(sizeof(struct noArvore));
        (*ppRaiz)->tipo = FOLHA;
        (*ppRaiz)->valor = expressao[i];
        return OPERANDO;
    }
    else
    {
        if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/')
        {
           *ppRaiz = (struct noArvore *)malloc(sizeof(struct noArvore));
            (*ppRaiz)->tipo = NO;
            (*ppRaiz)->info.esquerdo = NULL;
            (*ppRaiz)->info.operador = expressao[i];
            (*ppRaiz)->info.direito = NULL;
            return OPERADOR;
        }
        else
        {
            if (expressao[i] == '#') return FIM;
            else return INVALIDO;
        }
    }
 }
 
}
 
 boolean vazia(struct elemento *pPilha)
 {
    return pPilha == NULL;
}

void empilhar(struct elemento **ppPilha, struct noArvore *pRaiz)
{
    struct elemento *p;
    p = (struct elemento *)malloc(sizeof(struct elemento));
    p->no = pRaiz;
    p->prox = *ppPilha;
    *ppPilha = p;
}

boolean desempilhar(struct elemento **ppPilha, struct noArvore **ppRaiz)
 {
    struct elemento *p;
    if (vazia(*ppPilha))
    {
        *ppRaiz = NULL;
        return FALSE;
    }
    else
    {
        p = *ppPilha;
        *ppRaiz = (*ppPilha)->no;
        *ppPilha = (*ppPilha)->prox;
        free(p);
        return TRUE;
    }
}
 
void liberarArvore(struct noArvore *pRaiz)
 {
    if (pRaiz != NULL)
    {
        if (pRaiz->tipo == NO)
        {
            liberarArvore(pRaiz->info.esquerdo);
            liberarArvore(pRaiz->info.direito);
        }
        free(pRaiz);
    }
}

void liberarPilha(struct elemento **ppPilha)
{
    struct noArvore *pRaiz;
    struct elemento *p;
    while (*ppPilha != NULL)
    {
        pRaiz = (*ppPilha)->no;
        p = *ppPilha;
        *ppPilha = (*ppPilha)->prox;
        free(p);
        liberarArvore(pRaiz);
    }
 }

tipoResultado processarExpressaoPosfixa(struct elemento **ppPilha)
{
    struct noArvore *pRaiz = NULL;
    tipoResultado tipo = obterSimbolo(&pRaiz);
    while (tipo != INVALIDO && tipo != FIM && tipo != PILHA_VAZIA)
    {
        switch (pRaiz->tipo)
       {
       case NO:
            if (desempilhar(ppPilha, &(pRaiz->info.direito)))
                if (desempilhar(ppPilha, &(pRaiz->info.esquerdo)))
                    empilhar(ppPilha, pRaiz);
                else tipo = PILHA_VAZIA;
            else tipo = PILHA_VAZIA;
            break;
        case FOLHA:
            empilhar(ppPilha, pRaiz);
            break;
        }
        if (tipo == PILHA_VAZIA) liberarArvore(pRaiz);
        else tipo = obterSimbolo(&pRaiz);
    }
    return tipo;
 }
 
 void converterRecursivamenteInfixa(struct noArvore *pRaiz) {
    if (pRaiz != NULL)
     {
        if (pRaiz->tipo == FOLHA) printf("%c, pRaiz->valor);
        
		else
        {
            printf("(");
            converterRecursivamenteInfixa(pRaiz->info.esquerdo);
            printf(" %c ", pRaiz->info.operador);
            converterRecursivamenteInfixa(pRaiz->info.direito);
             printf(")");
        }
    }
}
