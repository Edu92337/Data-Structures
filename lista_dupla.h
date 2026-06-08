#ifndef AURA
#define AURA

typedef struct Lista_dupla  Lista_dupla;
typedef struct No No;
No* cria_no(int info);
Lista_dupla* cria_lista();
void insere_inicio(Lista_dupla* lista, int info);
void insere_final(Lista_dupla* lista,int info);
void prt(Lista_dupla* lista);
void insere_pos(Lista_dupla* lista,int pos,int info);

void remove_inicio(Lista_dupla* lista);
void remove_fim(Lista_dupla* lista);
void remove_pos(Lista_dupla* lista, int pos);
#endif 