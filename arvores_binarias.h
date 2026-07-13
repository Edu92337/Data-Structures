#ifndef aura
#define aura

typedef struct No No;
typedef struct ArvoreBin ArvoreBin;
No* cria_no(int y);
ArvoreBin* cria_arvore();
void insert(ArvoreBin* arv, int x);
void prt_rec(No* no);
void prt(ArvoreBin* arv);
void libera_rec(No* no);
void libera_arv(ArvoreBin* arv);
int pertence(ArvoreBin* arv,int x);
No* sucessor(No* no);
No* remover(No* raiz, int x);
No* acha_pai(ArvoreBin* arv, int x);


#endif
