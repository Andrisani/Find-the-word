/*
 ============================================================================
 Name        : Find-the-word
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Find the word to win.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "global_s.h"
#include "prototips.h"

int main() {
	bool scelta;
	player giocatori;
	char*player_name;
	bool vittoria;
	multi multiplayer;

	printf("========================================\n");
	printf("||           TROVA-LA-PAROLA          ||\n");
	printf("========================================\n");

	printf("inserisci 1 per iniziare una nuova partita\n");
	printf("inserisci 0 per uscire\n");

	scanf("%d", &scelta);

	if (scelta == 1) {
		system("cls");
		printf("Premi:\n");
		printf("1 per effettuare una partita contro il computer\n");
		printf("2 per efettuare una partita contro un altro giocatore\n");
		scanf("%d", &giocatori);
		if (giocatori == 1) {
			system("cls");
			player_name = nome_giocatore();
			system("cls");
			vittoria = player_vs_CPU(player_name);
			system("cls");
			if (vittoria == 1) {
				printf("%s HA VINTO ^_^\n", player_name);
				free(player_name);
				system("pause");
				system("cls");
				main();
			} else {
				printf("il computer HA VINTO :'(\n");
				free(player_name);
				system("pause");
				system("cls");
				main();
			}
		} else {
			if (giocatori == 2) {
				system("cls");
				multiplayer = nome_giocatori();
				system("cls");
				vittoria = player1_vs_player2(multiplayer);
				system("cls");
				if (vittoria == 1) {
					printf("%s HA VINTO ^_^\n", multiplayer.player2);
					free(multiplayer.player1);
					free(multiplayer.player2);
					system("pause");
					system("cls");
					main();
				} else {
					printf("%s HA VINTO ^_^\n", multiplayer.player1);
					free(multiplayer.player1);
					free(multiplayer.player2);
					system("pause");
					system("cls");
					main();
				}
			}
		}
	} else {
		if (scelta == 0) {
			return 0;
		}
	}

	return EXIT_SUCCESS;
}
