#ifndef ITEM_H_
#define ITEM_H_

typedef struct tItem item;

struct tItem{
	char chave[50];
	int valor;
};

item *inserirItem(char p[]);
void soma(item **Item);
void imprime(item *Item);
int comparar(item *Item, char p[]);
#endif
