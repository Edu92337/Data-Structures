#include<stdio.h>
#include<stdlib.h>
#include"pilha_le.h"


struct no{
    int x;
    No* anterior;
    No* proximo;
};

struct pilha { 
    No* top;
    int size;
};

No* cria_no(int x){
    No* novo = (No*)malloc(sizeof(No));
    if(novo){
        novo -> anterior = NULL;   
        novo -> proximo = NULL; 
        novo -> x = x;
    }
    return novo;
}

Pilha* cria_pilha(){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if(novo){
        novo -> top = NULL;   
        novo -> size = 0;
    }
    return novo;
}

void insert(Pilha* pilha,int x){
    No* novo = cria_no(x);
    if(pilha->size == 0){
        pilha -> top = novo;
    }else{
        novo -> proximo = pilha -> top ;
        pilha -> top -> anterior = novo;
        pilha -> top = novo;
    }
    pilha->size ++;
}
void prt(Pilha* pilha){
    No* aux = pilha -> top;
    for(int i=0;i<pilha->size;i++ ){
        printf("| %d |\n",aux->x);
        aux = aux->proximo;
    }
}
