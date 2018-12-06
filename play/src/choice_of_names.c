/*
 * choice_of_names.c
 *
 *  Created on: 05 dic 2018
 *      Author: Andrisani
 */
#include <stdio.h>
#include <stdlib.h>
#include "global_s.h"

char*nome_giocatore(void){
	char*player_name;

	player_name=(char*)malloc(20*sizeof(char));
	printf("inserisci il tuo nome\n");
	scanf("%s",player_name);

	return player_name;
}

multi nome_giocatori(void){
	multi multiplayer;

	printf("inserisci il nome del primo giocatore\n");
	multiplayer.player1=(char*)malloc(20*sizeof(char));
	scanf("%s",multiplayer.player1);
	fflush(stdin);
	printf("inserisci il nome del secondo giocatore\n");
	multiplayer.player2=(char*)malloc(20*sizeof(char));
	scanf("%s",multiplayer.player2);
	fflush(stdin);

	return multiplayer;
}


