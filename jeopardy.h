/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */

#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players);

void run_game(char **token, player *players);

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);


#endif /* JEOPARDY_H_ */