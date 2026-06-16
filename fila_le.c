#include<stdlib.h>
#include<stdio.h>
#include"fila_le.h"

struct No{
    int info;
    No* proximo;
};

struct fila{
    No* inicio;
    No* fim;
    int size;
};

No* cria_no(int x){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo) return NULL;
    novo->proximo = NULL;
    novo->info = x;
    return novo;
}

Fila* cria_fila(){
    Fila* f  = (Fila*)malloc(sizeof(Fila));
    if(!f) return NULL;
    f->inicio = NULL;
    f->fim = NULL;
    f->size = 0;
}

void insere(Fila*f,int x){
    No* novo = cria_no(x);
    if(f->inicio == NULL)f->inicio = novo;
    novo ->proximo = f->fim;
    f->fim = novo;
    f->size++;
}
void pop(Fila* f){
    if(f->size>0){
        No* atual = f->fim;
        while(atual->proximo->proximo)atual = atual->proximo;
        f->inicio = NULL;
        free(f->inicio);
        f->inicio = atual;
        f->size--;
    }
}

void prt(Fila* f){
    for(int i = 0;i<f->size;i++){
        printf(">====>");
    }printf("\n");
    No* atual = f->fim;
    for(int i = 0;i<f->size;i++){
        printf(" %d ",atual->info);
        atual = atual->proximo;
    }printf("\n");
    for(int i = 0;i<f->size;i++){
        printf(">====>");
    }printf("\n");

}

