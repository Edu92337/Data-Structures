#ifndef PILH4
#define PILH4
typedef struct pilha Pilha;
typedef struct no No;
Pilha* cria_pilha();
No* cria_no(int x);
void insert(Pilha* pilha,int x);
//char pop(Pilha* pilha);
void prt(Pilha* pilha);
//char topo(Pilha* pilha);
//int t(Pilha* pilha);
#endif 