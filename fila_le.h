#ifndef aura
#define aura

typedef struct No No;
typedef struct fila Fila;
Fila* cria_fila();
void insere(Fila* f,int x);
void pop(Fila* f);
void prt(Fila* f);

#endif