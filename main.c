/*Integrante 1 - Nome: Caroline Nakazato RA: 17164260
 Integrante 2 - Nome: Stephanie Leong RA: 15003270
 Resultados obtidos: ____________________________________________________ 
 Projeto básico: 100 % concluído - Obs: ___________________________________
 (X) Opcional 1 - Obs: ____________________________________________________
 ( ) Opcional 2 - Obs: ____________________________________________________
 ( ) Opcional 3 - Obs: ____________________________________________________
 ( ) Opcional 4 - Obs: ____________________________________________________
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "item.h"
#include "ST.h"
void main(int argc, char *argv[])
{
	char opcao, opcao2,  letra, qtdPalavra[50], palavra[50], word[50];	
	int i = 2, j = 0,k=2,m=0, w = 0, qtd = 0;
	no *arvore;
	lista *head;
	opcao = argv[1][1];
        if(argc>2){
            opcao2 = argv[2][1]; 
        } 
        while(argv[2][k] != '\0'){
			word[m] = argv[2][k];
			k++;
                        m++;
                    
		}
        printf("\n opcao = %c  e  opcao2 = %c  a  WORD_palavra = %s \n", opcao, opcao2, word);
	iniciaArvore(&arvore);
	iniciaLista(&head);

	if(opcao2 == 'r'){
            arquivo(head, opcao2);
            exit(0);
            
        }

	if(opcao == 'n'){
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
		//ordemAlfabetica(&head);
                if(opcao2 == 'w'){
                    imprimeLista(head, qtd);
                }
	}

	if(opcao2 == 'w'){
            arquivo(head, opcao2);
        }
        if(opcao2 == 's'){

            procuraPalavra(arvore, word);

        }
        
}
