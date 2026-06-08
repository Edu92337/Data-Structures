#ifndef l1st4_enc4de4d4
#define l1st4_enc4de4d4

typedef struct no No;
typedef struct lista_encadeada le;
No* cria(int info);
le* cria_lista();
void libera_lista(le* l);
void imprime_lista(le* l);
int insere_final(le* lista,int info);
int insere_inicio(le* lista,int info);
int insere_pos(le* lista, int info,int pos);
int remove_final(le* lista);
int remove_inicio(le* lista);
int remove_pos(le* lista, int pos);
#endif