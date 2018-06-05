#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"
#include <sys/time.h>

int main(int argc, char *argv[])
{
	int nPalavra = 0, tamN = 0, i = 2, j = 0, k = 0, nivel = 1, numero = 0, aux = 0;
	struct timeval  inicio;
	
	char num[50], palavra[50], ch, op, narquivo[50],tipo , tipo2;	
	lista *head;
	no *ArvItem;
	FILE *Arquivo;
	
	op = argv[1][1];//pega a operacao requesitada pelo usuario
	iniciaArvore(&ArvItem);
	iniciaLista(&head);

	if(op == 'n' && argc == 2)//printa as n palavras mais frequentes
	{
		while(argv[1][i] != '\0')//pega o numero de palavra que irao se repetir
		{
			num[j] = argv[1][i];
			i++;
			j++;
		}
		num[j] = '\0';
		tamN = atoi(num);

		scanf("%c", &ch);
		while(!feof(stdin))//vai retirando os charcters do buffer e formando as palavras
		{
			if((ch > 64 && ch <91) || (ch >96 && ch < 123))
			{
					palavra[k] = ch;
					k++;
			}
			else
			{
				palavra[k] = '\0';
				k = 0;
				if(strlen(palavra) > 0)// evita de entrar \0 na arvore e na lista
				{
					alocaArvore(&ArvItem, palavra);//insere a palvra na arvore
					alocaLista(&head, palavra);//insere a palavra na lista
				}
			}
			scanf("%c", &ch);
			if(ch == EOF)//pega a ultima palavra do buffer
			{
				palavra[k] = '\0';
				k = 0;
			}
		}
		ordenaLista(&head);//ordena a lista 
		imprimeLista(head, tamN);//printa as n palavras mais frequentes
	}
	return 0;
}
