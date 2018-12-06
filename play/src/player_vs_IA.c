/*
 * player_vs_IA.c
 *
 *  Created on: 05 dic 2018
 *      Author: Andrisani
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "global_s.h"
#include "prototips.h"

bool player_vs_CPU(char*player_name) {
	Data*start;
	Data*aux;
	Data*aux2;
	FILE*fp;
	int contpar;
	char car;
	int sort;
	int sort2;
	int ncar;
	char*indovina;
	char*vita;
	char*aus;
	int v;
	int ind;
	int par;
	int trovata;
	char car2;
	bool vittoria;
	int iaus;
	srand(time(NULL));

	fp = fopen("words.italian.dat", "r");
	if (fp == NULL) {
		printf("EMPITY FILE!!!\a\n");
		system("pause");
		return -1;
	} else {
		contpar = 0;
		while (!feof(fp)) {
			car = fgetc(fp);
			if (car == '\n') {
				contpar = contpar + 1;
			}
		}
		fclose(fp);
	}

	start = initialize_database();

	sort = rand() % contpar;
	aux = start;
	sort2 = 0;
	while ((sort2 <= contpar) && (aux != NULL)) {
		if (sort2 == sort) {
			ncar = strlen(aux->parola);
			indovina = (char*) malloc(20 * sizeof(char));
			for (ind = 0; ind < ncar; ind = ind + 1) {
				indovina[ind] = '_';
			}
			vita = (char*) malloc(4 * sizeof(char));
			for (v = 0; v < 3; v = v + 1) {
				vita[v] = 'X';
			}
			vita[v] = '\0';
			printf("e il turno di %s\n", player_name);
			v = 2;
			vittoria = 0;
			while ((strcmp(aux->parola, indovina) != 0)
					&& (strcmp(vita, "000") != 0)) {
				printf("vita:%s\n", vita);
				for (ind = 0; ind < ncar; ind = ind + 1) {
					printf("%c ", indovina[ind]);
				}
				printf("\n");
				printf("inserisci il carattere da indovinare:\n");
				scanf("%1s", &car);


				trovata = 0;
				for (par = 0; par < ncar; par = par + 1) {
					if((isupper(aux->parola[par]) !=0 ) && (islower(car) != 0)){
						car = toupper(car);
					}else if((islower(aux->parola[par]) != 0) && (isupper(car) != 0)){
						car = tolower(car);
					}
					if (aux->parola[par] == car) {
						trovata = 1;
						ind = par;
						indovina[ind] = car;
					}
				}
				if (trovata == 1) {
					printf("lettera indovinata\n");
					printf("vuoi provare ad inserire la parola intera?\a\n");
					printf("inserisci [s] o [n]\n");
					scanf("%1s", &car2);
					if (car2 == 's') {
						aus = (char*) malloc(20 * sizeof(char));
						printf("inseriscila:\n");
						scanf("%s", aus);
						iaus = 0;
						for(par = 0; par < ncar; par = par + 1){
							if(isupper(aux->parola[par]) != 0){
								aus[iaus] = toupper(aus[iaus]);
							}else{
								aus[iaus] = tolower(aus[iaus]);
							}
							iaus = iaus + 1;
						}
						if (strcmp(aus, aux->parola) == 0) {
							vittoria = 1;
							printf("la parola e:%s\n", aux->parola);
							aux = start;
							free(aux);
							system("pause");
							return vittoria;
						} else {
							vita[v] = '0';
							v = v - 1;
						}
						free(aus);
					}
				} else {
					vita[v] = '0';
					v = v - 1;
				}

				system("cls");
			}
			if (strcmp(indovina, aux->parola) == 0) {
				vittoria = 1;
			}
			printf("la parola era:%s\n", aux->parola);
		}
		sort2 = sort2 + 1;
		aux = aux->next;
	}

	aux = start;
	while(aux != NULL){
		aux2 = aux;
		aux=aux->next;
		free(aux2);
	}

	free(aux);

	system("pause");
	return vittoria;
}

