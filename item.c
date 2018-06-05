#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
item *inserirItem(char p[50]){
	item *novo = (item *)malloc(sizeof(item));
		strcpy(novo->chave, p);
		novo->valor=1;
		return novo;
}

void soma(item **Item){
	(*Item)->valor++; // = (*pItem)->valor + 1;
}

void imprime(item *Item){
	printf("%d %s\n", Item->valor, Item->chave);
}

int comparar(item *Item, char p[]){
	if(strcmp(Item->chave, p) == 0){
		return 0;
	}else{
		if(strcmp(Item->chave, p) < 0){
			return 1;
			
		}else{
			return -1;
			
		}
	}
}
