/*Integrante 1 - Nome: Caroline Nakazato RA: 17164260
 Integrante 2 - Nome: Stephanie Leong RA: 15003270
 Resultados obtidos: ____________________________________________________ 
 Projeto básico: 100 % concluído - Obs: ___________________________________
 ( ) Opcional 1 - Obs: ____________________________________________________
 ( ) Opcional 2 - Obs: ____________________________________________________
 ( ) Opcional 3 - Obs: ____________________________________________________
 ( ) Opcional 4 - Obs: ____________________________________________________
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"
void main(int argc, char *argv[])
{
	char opcao, letra, qtdPalavra[50], palavra[50];	
	int i = 2, j = 0, w = 0, qtd = 0;
	no *arvore;
	lista *head;
	opcao = argv[1][1];
	iniciaArvore(&arvore);
	iniciaLista(&head);
	
	if((opcao == 'n') && (argc == 2)){
		while(argv[1][i] != '\0'){
			qtdPalavra[j] = argv[1][i];
			i++;
			j++;
		}
		qtdPalavra[j] = '\0';
		qtd = atoi(qtdPalavra);
		scanf("%c", &letra);
		while(!feof(stdin)){
			if(((letra > 96) && (letra < 123))||((letra > 64) && (letra < 91))){
					palavra[w] = letra;
					w++;
			}else{
				palavra[w] = '\0';
				w = 0;
				if(strlen(palavra) > 0){
					alocaArvore(&arvore, palavra);
					alocaLista(&head, palavra);
				}
			}
			scanf("%c", &letra);
			if(letra == EOF){
				palavra[w] = '\0';
				w = 0;
			}
		}
		ordenaLista(&head);
		ordemAlfabetica(&head);
		imprimeLista(head, qtd);
	}
}
