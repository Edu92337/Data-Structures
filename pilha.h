#ifndef PILH4
#define PILH4
typedef struct pilha Pilha;
Pilha* cria_pilha();
void insert(Pilha* pilha,char x);
char pop(Pilha* pilha);
void prt(Pilha* pilha);
char topo(Pilha* pilha);
int t(Pilha* pilha);
#endif 