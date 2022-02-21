/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 *  <Group 4[A]>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "jeopardy.h"
#include "questions.h"
#include "players.h"

 // Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char* input, char** tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player* players);


int main(int argc, char* argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction, prompt the player names
    // initialize each of the players in the array
    printf("Welcome to Jeopardy! Please Enter your Name:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%s", players[i].name);
    }
    printf("Thank you, let's start playing!\n");

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Calling the functions from questions and players source files

        char token[4][BUFFER_LEN] = { {0} };


        initialize_game();
        run_game(token, players);
        return 0;

    }


}
void show_results(player* players) {
    for (int i = 0; i <= 4; i++) {
        printf("Name: %s\tScore is:%d\n", players[i].name, players[i].score);
    }
}

void tokenize(char* input, char** tokens) {

    char* token1 = strtok(input, " ");
    token1 = strtok(input, " ");

    for (int i = 0; token1 != NULL; i++) {
        strcpy(tokens[i], token1);
        token1 = strtok(NULL, " ");
    }
}

void run_game(char** token, player* players) {
    // Execute the game until all questions are answered
    int questions_remaining = sizeof(questions);
    bool correct;
    char* category;
    int value;
    char answer[BUFFER_LEN] = { 0 };

    category = (char*)calloc(BUFFER_LEN, sizeof(char));

    //token = (char *) calloc(256, sizeof(char));


    while (questions_remaining > 0) {
        for (int i = 0; i < sizeof(players); i++) {
            printf("%s's Turn\nPlease choose a question\nenter the category and value for that question ):\n\n", players[i].name);

            display_categories();

            printf("\n\n");
            scanf("%s", category);
            scanf("%d", value);
            printf("\n");

            if (already_answered(category, value)) {
                printf("Choose another question, this question has been answered");
                i--;
            }
            else {
                display_question(category, value);
                scanf("%s", answer);                                  //Recieves answer from player

                tokenize(answer, token);                               //Checks whether ans is correct or not 
                correct = valid_answer(category, value, token[2]);
                if (correct) {
                    printf("Your absoulty Correct! Choose another question.\n\n");
                    players[i].score += value;
                    i--;
                }
                else {
                    printf("Your answer is incorrect  \"Try another question\".\n\n");
                }
                question_answered(category, value);
                questions_remaining--;
                if (questions_remaining <= 0) {
                    break;
                }
            }
        }
        free(category);
    }

    // final results for each player 
    show_results(players);

}