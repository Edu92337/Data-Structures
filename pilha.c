#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"
#define MAX_ 100

struct pilha{
    int topo;
    int size;
    char p[MAX_];
    char top;
};

Pilha* cria_pilha(){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha){
        for(int i = 0;i<MAX_;i++) pilha->p[i] = 0;
        pilha->size = 0;
        pilha->topo = MAX_ - 1;
        pilha->top = '0';
        return pilha;
    }
    return pilha;
}

void insert(Pilha* pilha,char x){
    if(pilha->topo > 0){
        pilha->p[pilha->topo -1] = x;
        pilha->topo -=1;
        pilha->size +=1;
        pilha->top = x;
    }
}

char pop(Pilha* pilha){
    if(pilha->topo != MAX_ -1 && pilha->size > 0){
        int x = pilha->p[pilha->topo];
        pilha->topo ++;
        pilha->size --;
        pilha->top = pilha->p[pilha->topo];
        return x;
    }return '0';
}

void prt(Pilha* pilha){
    for(int i = MAX_ -1 - pilha->size;i<MAX_;i++){
        if(pilha->p[i]==0) continue;
        else printf("| %d |\n",pilha->p[i]);
    }
}

char topo(Pilha* pilha){
    return pilha->top;
}
int t(Pilha* pilha){
    return pilha->size;
}