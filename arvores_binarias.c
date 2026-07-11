#include<stdio.h>
#include<stdlib.h>
#include"arvores_binarias.h"


struct No{
    int info;
    No* esq;
    No* dir;
};

struct ArvoreBin{
    No* raiz;
};

No* cria_no(int y){
    No* novo = (No*)malloc(sizeof(No));
    if(novo){
        novo -> esq = NULL;
        novo -> dir = NULL;
        novo -> info = y;
        return novo;
    }reuturn NULL;
}

ArvoreBin* cria_arvore(){
    ArvoreBin* arv = (ArvoreBin*)malloc(sizeof(ArvoreBin));
    No* r = NULL;
    if(arv && r){
        arv->raiz = r;
        return arv;
    }return NULL;
}

void insert(ArvoreBin* arv, int x){
    No* aux = arv->raiz;
    No* pai = NULL;
    No* novo = cria_no(x);
    if(arv->raiz == NULL){
        arv ->raiz = novo;
        return;
    }
    while(aux!=NULL){
        pai = aux;
        if(x > aux->info)aux = aux->dir;
        else aux = aux->esq;
    }
    if(x > pai->info)pai->dir = novo;
    else pai->esq = novo;

}

void prt_rec(No* no){
    if(no == NULL) return;
    printf(" %d ",no->info);
    prt_rec(no->esq);
    prt_rec(no->dir);
}

void prt(ArvoreBin* arv){
    prt_rec(arv->raiz);
}

void libera_rec(No* no){
    if(no!=NULL){
        libera_rec(no->esq);
        libera_rec(no->dir);
        free(no);
    }
}

void libera_arv(ArvoreBin* arv){
    libera_rec(arv->raiz);
    free(arv);
}

int pertence(ArvoreBin* arv,int x){
    No* aux = arv->raiz;
    if(!aux) return 0;
    while(aux){
        if(aux->info == x) return 1;
        if(x > aux->info) aux = aux->dir;
        else aux = aux->esq;
    }
    return 0;
}
