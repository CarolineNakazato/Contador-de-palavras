#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
item *inserirItem(char p[50]){
	item *novo = (item *)malloc(sizeof(item));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		break;
	}else{
		strcpy(novo->chave, p);
		novo->valor=1;
		return novo;
	}	
}

void soma(item **Item){
	(*Item)->valor++; // = (*pItem)->valor + 1;
}

int comparar(item *Item, char p[]){
	if(strcmp(Item->chave, p)==0) return 0;
	if(strcmp(Item->chave, p)<0) return 1;
	return 2;
}
