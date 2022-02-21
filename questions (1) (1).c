/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define strcpy_s

 // Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy_s(questions[0].category, sizeof("programming"), "programming");
    strcpy_s(questions[0].question, sizeof("Referred to as Programming Documentation"), "Referred to as Programming Documentation");
    strcpy_s(questions[0].answer, sizeof("What is Commenting"), "What is Commenting");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy_s(questions[1].category, sizeof("programming"), "programming");
    strcpy_s(questions[1].question, sizeof("Type of variable that would be used to store the word Strong"), "Type of variable that would be used to store the word Strong");
    strcpy_s(questions[1].answer, sizeof("What is string"), "What is string");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy_s(questions[2].category, sizeof("programming"), "programming");
    strcpy_s(questions[2].question, sizeof("Math class function that rounds decimal values."), "Math class function that rounds decimal values.");
    strcpy_s(questions[2].answer, sizeof("What is round"), "What is round");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy_s(questions[3].category, sizeof("programming"), "programming");
    strcpy_s(questions[3].question, sizeof("The binary number 11111 in decimal."), "The binary number 11111 in decimal.");
    strcpy_s(questions[3].answer, sizeof("What is 31"), "What is 31");
    questions[3].value = 400;
    questions[3].answered = false;

    strcpy_s(questions[4].category, sizeof("algorithms"), "algorithms");
    strcpy_s(questions[4].question, sizeof("A sorter that divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves"), "A sorter that divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves");
    strcpy_s(questions[4].answer, sizeof("What is MergeSort"), "What is MergeSort");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy_s(questions[5].category, sizeof("algorithms"), "algorithms");
    strcpy_s(questions[5].question, sizeof("A well-defined computational procedure that take some value as input and generate some value as output. "), "A well-defined computational procedure that take some value as input and generate some value as output. ");
    strcpy_s(questions[5].answer, sizeof("What is algorithm"), "What is algorithm");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy_s(questions[6].category, sizeof("algorithms"), "algorithms");
    strcpy_s(questions[6].question, sizeof("The process in which a function calls itself directly or indirectly"), "The process in which a function calls itself directly or indirectly");
    strcpy_s(questions[6].answer, sizeof("What is recursion"), "What is recursion");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy_s(questions[7].category, sizeof("algorithms"), "algorithms");
    strcpy_s(questions[7].question, sizeof("Any function that can be used to map data of arbitrary size to fixed-size values"), "Any function that can be used to map data of arbitrary size to fixed-size values");
    strcpy_s(questions[7].answer, sizeof("What is hash"), "What is hash");
    questions[7].value = 400;
    questions[7].answered = false;

    strcpy_s(questions[8].category, sizeof("databases"), "databases");
    strcpy_s(questions[8].question, sizeof("A set of data elements (values) using a model of vertical columns (identifiable by name) and horizontal rows"), "A set of data elements (values) using a model of vertical columns (identifiable by name) and horizontal rows");
    strcpy_s(questions[8].answer, sizeof("What is table"), "What is table");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy_s(questions[9].category, sizeof("databases"), "databases");
    strcpy_s(questions[9].question, sizeof("Uniquely specifies a tuple within a table"), "Uniquely specifies a tuple within a table");
    strcpy_s(questions[9].answer, sizeof("What is primary key"), "What is primary key");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy_s(questions[10].category, sizeof("databases"), "databases");
    strcpy_s(questions[10].question, sizeof("A programming language designed for managing data in a relational database"), "A programming language designed for managing data in a relational database");
    strcpy_s(questions[10].answer, sizeof("What is SQL"), "What is SQL");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy_s(questions[11].category, sizeof("databases"), "databases");
    strcpy_s(questions[11].question, sizeof("A filtered set of data displayed to the end user in order to hide data complexity and streamline the user experience."), "A filtered set of data displayed to the end user in order to hide data complexity and streamline the user experience.");
    strcpy_s(questions[11].answer, sizeof("What is view"), "What is view");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array

    printf("Programming \n");
    for (int i = 0; i < 4; i++) {
        if (questions[i].answered == false) {
            printf("%d", questions[i].value);
            printf("\n");

        }
    }

    printf("Algorithms \n");
    for (int i = 4; i < 8; i++) {
        if (questions[i].answered == false) {
            printf("%d", questions[i].value);
            printf("\n");
        }
    }

    printf("Databases \n");
    for (int i = 8; i < 12; i++) {
        if (questions[i].answered == false) {
            printf("%d", questions[i].value);
            printf("\n");
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char category[], int value)
{
    for (int i = 0; i < 12; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Question: %s", questions[i].question);
            printf("Value: %d\n", questions[i].value);
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char category[], int value, char answer[])
{
    // Look into string comparison functions
    bool correct = false;

    for (int i = 0; i < 12; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                correct = true;
            }
        }
    }

    return correct;
}

// Returns true if the question has already been answered
bool already_answered(char category[], int value)
{
    // lookup the question and see if it's already been marked as answered
    bool isAnswered = false;
    for (int i = 0; i < 12; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (questions[i].answered == true) {
                isAnswered = true;
            }
        }
    }
    return isAnswered;
}


