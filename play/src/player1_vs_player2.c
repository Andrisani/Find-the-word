/*
 * player1_vs_player2.c
 *
 *  Created on: 05 dic 2018
 *      Author: Andrisani
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "global_s.h"
#include "prototips.h"

player player1_vs_player2(multi multiplayer) {
	player giocatore;
	char*parola;
	char*indovina;
	char*vita;
	int v;
	int ind;
	int ncar;
	int par;
	int trovata;
	char car;
	char car2;
	char*aus;
	int iaus;

	parola = (char*) malloc(20 * sizeof(char));
	printf("%s inserisci la parola che stai pensando:\n", multiplayer.player1);
	fflush(stdin);
	gets(parola);
	fflush(stdin);
	system("cls");
	printf("E il turno di %s\n", multiplayer.player2);

	ncar = strlen(parola);
	indovina = (char*) malloc((ncar + 1) * sizeof(char));
	for (ind = 0; ind < ncar; ind = ind + 1) {
		indovina[ind] = '_';
	}
	indovina[ind] = '\0';
	vita = (char*) malloc(4 * sizeof(char));
	for (v = 0; v < 3; v = v + 1) {
		vita[v] = 'X';
	}
	vita[v] = '\0';
	v = 2;
	giocatore = 0;
	while ((strcmp(parola, indovina) != 0) && (strcmp(vita, "000") != 0)) {
		printf("vita:%s\n", vita);
		for(ind = 0; ind < ncar; ind = ind + 1){
			printf("%c ", indovina[ind]);
		}
		printf("\n");
		printf("inserisci il carattere da indovinare:\n");
		scanf("%1s", &car);
		trovata = 0;
		for (par = 0; par < ncar; par = par + 1) {
			if((isupper(parola[par]) != 0) && (islower(car) != 0)){
				car = toupper(car);
			}else if((islower(parola[par]) != 0) && (isupper(car) != 0)){
				car = tolower(car);
			}
			if (parola[par] == car) {
				trovata = 1;
				ind = par;
				indovina[ind] = car;
			}
		}
		if (trovata == 1) {
			printf("lettera indovinata:\n");
			printf("vuoi provare ad inserire la parola intera?\a\n");
			printf("inserisci [s] o [n]\n");
			scanf("%1s", &car2);
			if (car2 == 's') {
				aus = (char*) malloc(20 * sizeof(char));
				printf("inseriscila:\n");
				scanf("%s", aus);
				iaus = 0;
				for(par = 0; par < ncar; par = par + 1){
					if(isupper(parola[par]) != 0){
						aus[iaus] = toupper(aus[iaus]);
					}else{
						aus[iaus] = tolower(aus[iaus]);
					}
					iaus = iaus + 1;
				}
				if (strcmp(aus, parola) == 0) {
					giocatore = 1;
					printf("la parola e:%s\n", parola);
					system("pause");
					return giocatore;
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
	if (strcmp(indovina, parola) == 0) {
		giocatore = 1;
	}
	printf("la parola era:%s\n", parola);
	system("pause");
	return giocatore;
}

