#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "item.h"
#include "ST.h"
void iniciaArvore(no **raiz){
	(*raiz) = NULL;
}

void alocaArvore(no **raiz, char p[]){
	if((*raiz)==NULL){
		(*raiz) = (no *)malloc(sizeof(no));
		(*raiz)->info = inserirItem(p);
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}else{
		switch(comparar((*raiz)->info, p)){
			case 0:
				soma(&(*raiz)->info);
				break;
			case 1:
				alocaArvore(&(*raiz)->esq, p);
				break;
			case -1:
				alocaArvore(&(*raiz)->dir, p);
				break;
		}
	}
}

void iniciaLista(lista **head){
	(*head) = NULL;
}

int existeLista(lista *head, char p[]){
	while(head!=NULL){ 
		if(comparar(head->info, p) == 0){
			soma(&head->info);
			return 1;
		}
		head = head->prox;	
	}
	return 0;
}

void alocaLista(lista **head, char p[]){
	if(existeLista((*head), p) == 0){
		lista (*novo) = (lista*)malloc(sizeof(lista));
		novo->info = inserirItem(p);
		novo->prox = (*head);
		(*head) = novo;
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
	
   tam = tamanhoLista(*head);
   k = tam;
   for ( i = 0; i < (tam - 1); i++, k-- ){
      atual = *head;
      oldHead = (*head)->prox;
		
      for ( j = 1; j < k; j++ ){   
         if ( atual->info->valor < oldHead->info->valor ){
            valor = atual->info->valor;
            atual->info->valor = oldHead->info->valor;
            oldHead->info->valor = valor;

            strcpy(chave, atual->info->chave);
            strcpy(atual->info->chave, oldHead->info->chave);
            strcpy(oldHead->info->chave, chave);
         } else{
         	if ( atual->info->valor == oldHead->info->valor ){
         		if(comparar(atual->info, oldHead->info->chave) == -1){		
         			strcpy(chave, atual->info->chave);
	         		strcpy(atual->info->chave, oldHead->info->chave);
	         		strcpy(oldHead->info->chave, chave);
	         	}
         	}
         }			
         atual = atual->prox;
         oldHead = oldHead->prox;
      }
   }   
}

void ordemAlfabetica(lista **head){
   int i, j, k, tam, valor;
   char chave[50];
   lista *atual, *oldHead;
	
   tam = tamanhoLista(*head);
   k = tam;
   for ( i = 0; i < (tam - 1); i++, k-- ){
      atual = *head;
      oldHead = (*head)->prox;
		
      for ( j = 1; j < k; j++ ){   
         	if ( atual->info->valor == oldHead->info->valor ){
         		if(comparar(atual->info, oldHead->info->chave) == -1){
         		          valor = atual->info->valor;
               		atual->info->valor = oldHead->info->valor;
            		oldHead->info->valor = valor;
            		
         			strcpy(chave, atual->info->chave);
	         		strcpy(atual->info->chave, oldHead->info->chave);
	         		strcpy(oldHead->info->chave, chave);
	         	}
         	}			
         atual = atual->prox;
         oldHead = oldHead->prox;
      }
   }   
}

void imprimeLista(lista *head, int n){
//printf("n = %d\n", n);
	int i, tamanho = tamanhoLista(head);
//	printf("tamanho = %d\n", tamanho);
	for(i = 0; ((i<n)&&(head!=NULL)); i++){
	imprime(head->info);
	head = head->prox;
	}
}

void arquivo(lista *l, char op){
  FILE *arquivo;
  item *Item;
  char c;
  
  if(op == 'w'){
    arquivo = fopen("stfile.txt","w");
    
    while(l != NULL){
        Item = l->info;
    fprintf(arquivo, "%d  %s\n", Item->valor,Item->chave);
    l = l->prox;

    }
    
    fclose(arquivo);
  }
  
  if(op == 'r'){
    arquivo = fopen("stfile.txt","r");
    
   while( ( c = fgetc(arquivo) ) != EOF ){
      printf("%c",c);
     
  }
   fclose(arquivo);
  }
}

int altura(no *t, no *node, int a){
  if(t == NULL){
    return 0;
  }
  if(t == node) return a;

  int level = altura(t->esq,node,a+1);

  if(level!=0) return level;

  return altura(t->dir,node,a+1);
}


no *busca_word(no *tre, char word[]){
  if(tre == NULL){
    return NULL;
  }
  if(strcmp(word,tre->info->chave) == 0){
    return tre;
  }
  if(strcmp(word,tre->info->chave) < 0){
    busca_word(tre->esq,word);    
  }
  else{
     busca_word(tre->dir,word);    
  }
}

void procuraPalavra(no *arv, char palavra[]){
   int alt=0;
    no *busca = NULL;
    clock_t start,end;
    
    start = clock();
   busca = busca_word(arv, palavra);
   end = clock();
   double demora = ((double) (end - start))/CLOCKS_PER_SEC;
    
    alt = altura(arv,busca,1);
    
    if(busca == NULL){
      printf("PALAVRA NAO ENCONTRADA!\n\n");
    }
    else{
      printf("Palavra Encontrada: %s   Frequencia: %d    Altura: %d    Tempo: %f \n\n",busca->info->chave,busca->info->valor, alt, demora);
    }
}


