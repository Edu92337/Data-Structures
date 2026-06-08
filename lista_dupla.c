#include<stdio.h>
#include<stdlib.h>
#include "lista_dupla.h"


/*

// NUNCA faça free em um ponteiro que aponta para um nó que ainda está na lista
    No* aux = lista->inicio;  // aux aponta para um nó da lista
    while(aux->proximo != NULL) aux = aux->proximo;  // navegação
    aux->proximo = novo;  // conecta novo nó
    // free(aux);  //  NUNCA! aux ainda está na lista!

*/



struct No{
    int info;
    No* anterior;
    No* proximo;
};

struct Lista_dupla{
    int size;
    No* inicio;  
};

No* cria_no(int info){
    No* node = (No*)malloc(sizeof(No));
    if(!node) return NULL;
    node -> info = info;
    node -> anterior = NULL;
    node -> proximo = NULL;
    return node;
}

Lista_dupla* cria_lista(){
    Lista_dupla* lista = (Lista_dupla*)malloc(sizeof(Lista_dupla));
    if(!lista) return NULL;
    lista ->inicio = NULL;
    lista -> size = 0;
    return lista;
}

void insere_inicio(Lista_dupla* lista, int info){
    No* novo = cria_no(info);
    if(lista -> size == 0){
        lista -> inicio  = novo;
    }else{
        novo -> proximo = lista -> inicio;
        lista -> inicio ->anterior = novo;
        lista -> inicio = novo;
    }
    lista -> size += 1;
}

void insere_final(Lista_dupla* lista,int info){
    No* novo = cria_no(info);
    if(lista -> size == 0){
        lista -> inicio  = novo;
    }else{
        No* aux = lista -> inicio;
        while(aux->proximo != NULL) aux = aux->proximo;
        aux -> proximo = novo;
        novo -> anterior = aux;
        aux = NULL;
        free(aux);
    }
    lista -> size += 1;
    
}

void insere_pos(Lista_dupla* lista,int pos,int info){
    int n = lista -> size;
    if(pos == 0) {
        insere_inicio(lista,info);
        return;
    }
    if(pos >= n) {
        insere_final(lista,info);
        return;
    }
    No* novo = cria_no(info);
    No* aux = lista -> inicio;
    for(int i = 0;i<pos;i++) aux = aux-> proximo;
    novo -> proximo = aux;
    novo -> anterior = aux->anterior;
    aux ->anterior->proximo = novo;
    aux->anterior = novo;
    lista ->size +=1;
    aux = NULL;
    free(aux);
}

void remove_inicio(Lista_dupla* lista){
    if(lista->size != 0){
        No* aux = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        aux -> proximo = NULL;
        free(aux);
        lista->size -=1;
    }
}

void remove_fim(Lista_dupla* lista){
    if(lista->size == 0) return ;
    if(lista->size == 1){
        free(lista->inicio);
        lista->inicio = NULL;
        lista->size -= 1;
        return;
    }
    No* aux = lista -> inicio;
    while(aux->proximo != NULL) aux = aux->proximo;
    aux->anterior->proximo = NULL;
    free(aux);    
    lista->size -= 1;
}
void remove_pos(Lista_dupla* lista, int pos){
    if(lista->size == 0) return;
    if(lista->size == 1){
        free(lista->inicio);
        lista->inicio = NULL;
        lista-> size = 0;
        return;
    }
    if(pos == lista->size -1 ){
        remove_fim(lista);
        return;
    }
    if(pos == 0){
        remove_inicio(lista);
        return;
    }
    No* aux = lista -> inicio;
    for(int i =0;i<pos;i++) aux = aux->proximo;
    aux->anterior->proximo = aux->proximo;
    aux->proximo -> anterior = aux ->anterior;
    free(aux);
    lista->size -= 1;
}




void prt(Lista_dupla* lista){
    printf("[");
    No* aux = lista -> inicio;
    int n = lista->size;
    for(int i = 0;i<n;i++){
        if(i!=n-1)printf("%d , ",aux->info);
        else printf("%d ",aux->info);
        aux = aux->proximo;
    }printf("]\n");
}