#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>
/*
-> 
    Lista encadeada é interessante quando o algoritmo precisa
    de muitas inserções ou remoções, não precisa deslocar todos os 
    elementos que nem acontece com vetores
*/

struct no{
    int info;
    No* prox;
};

struct lista_encadeada{
    No* phead;
    int l;
};

No* cria(int info){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo) return NULL;
    novo->prox = NULL;
    novo->info = info;
    return novo;
};

le* cria_lista(){
    le* nl = (le*)malloc(sizeof(le));
    if(!nl)return NULL;
    nl->phead = NULL;
    nl->l = 0;
    return nl;
}

int insere_inicio(le* lista,int info){
    No* novo = cria(info);
    if(!novo) return 0;
    if(lista->phead == NULL){
        lista->l+=1;
        lista->phead = novo;
        return 1;
    }
    novo->prox = lista->phead;
    lista->phead = novo;
    lista->l += 1;
    return 1;
}

int insere_final(le* lista, int info){
    No* novo = cria(info);
    if(!novo) return 0;
    if(lista->phead == NULL){
        lista->l += 1;
        lista->phead = novo;
        return 1;
    }
    No* atual = lista->phead;
    lista->l += 1;
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
    return 1;
}

int insere_pos(le* lista, int info,int pos){
    if(!lista) return 0;
    if(pos < 0 || pos >= lista->l) return 0;
    No* aux = lista->phead;
    for(int i = 0;i<pos-1;i++) aux = aux->prox;
    No* atual = cria(info);
    atual->prox = aux->prox;
    aux->prox = atual;
    lista->l += 1;
    return 1;
}

int remove_inicio(le* lista){
    if(lista->phead == NULL) return 1;
    lista->l -= 1;
    No* aux = lista->phead;
    lista->phead = lista->phead->prox;
    free(aux);
    return 1;
}
int remove_final(le* lista){
    if(lista->phead == NULL) return 1;
    No* aux = lista->phead;
    lista->l -= 1;
    while(aux->prox->prox != NULL) aux = aux->prox;
    free(aux->prox);
    aux->prox = NULL;
    return 1;
}
int remove_pos(le* lista,int pos){
    if(lista->phead == NULL) return 0;
    if(pos<0 || pos>=lista->l) return 0;
    No* atual = lista->phead;
    for(int i = 0;i<pos-1;i++) atual =atual->prox;
    No* aux = atual->prox;
    atual->prox = aux->prox;
    free(aux);
    lista->l -= 1;
    return 1;
}

void libera_lista(le* l){
    No* aux = l->phead;
    while(aux != NULL){
        l->phead = aux->prox;
        free(aux);
        aux = l->phead;
    }
}

void imprime_lista(le* lista){
    No* aux = lista->phead;
    int c = 0;
    printf("A lista tem %d elementos\n",lista->l);
    printf("[");
    while(aux != NULL){
        if(aux->prox!=NULL) printf("%d, ",aux->info);
        else printf("%d] \n",aux->info);
        aux = aux->prox;
    }
    //printf("\n");
}