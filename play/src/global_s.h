/*
 * global_s.h
 *
 *  Created on: 05 dic 2018
 *      Author: Andrisani
 */

#ifndef GLOBAL_S_H_
#define GLOBAL_S_H_

typedef struct Data_base {
	char*parola;
	struct Data_base*next;
} Data;

typedef struct multiplayer {
	char*player1;
	char*player2;
} multi;

typedef int bool;
typedef int player;

#endif /* GLOBAL_S_H_ */
