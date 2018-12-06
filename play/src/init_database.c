/*
 * init_database.c
 *
 *  Created on: 05 dic 2018
 *      Author: Andrisani
 */
#include <stdio.h>
#include <stdlib.h>
#include "global_s.h"

Data*initialize_database(void) {
	FILE*fp;
	Data*start;
	Data*aux;

	fp = fopen("words.italian.dat", "r");
	if (fp == NULL) {
		printf("EMPITY FILE!!!\a\n");
		system("pause");
		exit(-1);
	} else {
		start = (Data*) malloc(sizeof(Data));
		if (start == NULL) {
			printf("impossibile_memorizzare i dati!!!\a\n");
			system("pause");
			exit(-1);
		} else {
			start->parola = (char*) malloc(20 * sizeof(char));
			fscanf(fp, "%s", start->parola);
			start->next = NULL;
			aux = start;
			while (!feof(fp)) {
				aux->next = (Data*) malloc(sizeof(Data));
				aux = aux->next;
				aux->parola = (char*) malloc(20 * sizeof(char));
				fscanf(fp, "%s", aux->parola);
				aux->next = NULL;
			}
		}
		fclose(fp);
	}
	return start;
}

