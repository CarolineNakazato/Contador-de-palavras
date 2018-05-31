#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"
void iniciaArvore(no **raiz){
	(*raiz) = NULL;
}

void alocaArvore(no **raiz, char p[]){
	if(*raiz){
		(*raiz) = (no *)malloc(sizeof(no));
		if(!novo){
			printf("Sem memoria disponivel!\n");
			break;
		}else{
			(*raiz)->info = inserirItem(p);
			(*raiz)->esq = NULL;
			(*raiz)->dir = NULL;
		}else{
			switch(comparar((*raiz)->info, p){
				case 0:
					soma(&(*raiz)->info);
					break;
				case 1:
					alocaArvore(&(*raiz)->esq, p);
					break;
				case 2:
					alocaArvore(&(*raiz)->dir, p);
					break;
			}
		}
	}
}

void iniciaLista(lista **head){
	(*head) = NULL;
}

void alocaLista(lista **head, char p[]){
	int count = 0;
	lista *oldHead = (*head);
	lista (*novo) = (lista*)malloc(sizeof(lista));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		break;
	}else{
		novo->info = inserirItem(p);
		novo->prox = NULL;
		if((*head) == NULL){
			(*head) = novo;
		}else{
			while(oldHead->prox){
				if(comparar(novo->info, p) == 0){
					soma(oldHead->info);//.valor = oldHead->info.valor + 1;
					count = 1;
					break;
				}
				oldHead = oldHead->prox;
			}
			if(count == 0){
				(*head)->prox = novo;
			}
		}
	}
}

int tamanhoLista(lista *head){
   int tamanho = 0;
   lista *atual;
	
   for(atual = head; atual != NULL; atual = atual->prox) {
      tamanho++;
   }
	
   return tamanho;
}

void ordenaLista(lista **head){
   int i, j, k, tam, valor;
   char chave[50];
   lista *atual, *oldHead;
	
   tam = tamanhoLista();
   k = tam;
	
   for ( i = 0; i < (tam - 1); i++, k-- ){
      atual = *head;
      oldHead = (*head)->prox;
		
      for ( j = 1; j < k; j++ ){   

         if ( atual->info.valor > oldHead->info.valor ){
            valor = atual->info.valor;
            atual->info.valor = oldHead->info.valor;
            oldHead->info.valor = valor;

            strcpy(chave, atual->info.chave);
            strcpy(atual->info.chave, oldHead->info.chave);
            strcpy(oldHead->info.chave, chave);
         }			
         atual = atual->prox;
         oldHead = oldHead->prox;
      }
   }   
}

void imprimeLista(lista *head, int n){
	int i;
	for(i = n; ((i>=0)&&(head)); i--){
		printf("%d %s\n", head->info.valor, head->info.chave);
		head = head->prox;
	}
}