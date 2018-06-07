#ifndef ST_H_
#define ST_H_
#include "item.h"
typedef struct tNo no;
typedef struct tLista lista;

struct tNo{
	item *info;
	no *esq, *dir;
};

struct tLista{
	item *info;
	lista *prox;
};

void iniciaArvore(no **raiz);
void alocaArvore(no **raiz, char p[]);

void iniciaLista(lista **head);
int existeLista(lista *head, char p[]);
void alocaLista(lista **head, char p[]);
int tamanhoLista(lista *head);
void ordenaLista(lista **head);
void ordemAlfabetica(lista **head);
void imprimeLista(lista *head, int n);
void arquivo(lista *l, char op);

void procuraPalavra(no *arv, char palavra[]);
no *busca_word(no *tre, char word[]);
int altura(no *t, no *node, int a);
#endif
