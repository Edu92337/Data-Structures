#include"fila_vetor.h"
#include<stdio.h>
#include<stdlib.h>

#define MAX_ 100
struct fila{
    int v[MAX_];
    int inicio;
    int fim;
    int size;
};

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if(f){
        for(int i = 0;i<MAX_;i++)f->v[i]=-1;
        f->inicio = 0;
        f->fim = 0;
        f->size = 0;
    }
}

void insere(Fila* f,int x){
    f->v[f->fim] = x;
    f->fim ++;
    f->size ++;
    
}

void pop(Fila* f){
    if(f->inicio <MAX_){
        f->inicio++;
        f->size--;
    }
}


void prt(Fila* f){
    for(int i = f->inicio;i<f->fim;i++){
        printf("<====<");
    }printf("\n");
    for(int i = f->inicio;i<f->fim;i++){
        printf(" %d ",f->v[i]);
    }printf("\n");
    for(int i = f->inicio;i<f->fim;i++){
        printf("<====<");
    }printf("\n");

}
