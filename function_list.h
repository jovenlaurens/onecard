#ifndef LIST_H
#define LIST_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// defining macros
#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11

// defining structure
// card structure
typedef struct _card {
    int suit;
    int rank;
} card;

// player structure
typedef struct node {
    int card_hand[100];
    int position;
    int stockcards;
    int points;
    struct node *next;
    struct node *prev;
} node_t;

// functions
// function to get a node
node_t *Initialize(int position);
// function to build the linked list
node_t *initialize_player(int player, node_t **ptr);
// function deck list
void decklist(int rank, int suit);
// function deck list log
void decklist_log(FILE *file, int rank, int suit);
// function to display deck
void dispdeck(FILE *file, int *list, int stockcards, int demo);
// function to display card
void dispcard(int cards);
// function to display card in log file
void dispcard_log(FILE *file, int cards);
// function to sort deck
void initialize_deck(int *list, int number, int deck);
// function to shuffle deck
void shuffle(FILE *file, int *list, int stockcards, int demo);
// function to give cards
void assigncards(FILE *file, int players, int cards, int *stockcard, int *stockpile, node_t *player, int demo);
// function to find winner
void getwinner(FILE *file, int players, node_t *player_list);
// function to find order of player
int playerorder(FILE *file, int players, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t *player_list);
// function to compare card
int comparecard(int play_card, int last_card);
// function to restore stockpile
void restore_stockpile(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, int demo);
// function to draw cards
void draw(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t *current_player, int *attack2, int *attack3, int demo);
// function to compare attack card
int compareattack(int play_card);
// function to show players stat
void stat(FILE *file, int players, node_t *player_list);
// function to play cards
int play(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t **player_list, int *attack2, int *attack3, int *order, int *skip, int demo);
// function to play cards automatic
int play_demo(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t **player_list, int *attack2, int *attack3, int *order, int *skip, int demo);
// function to initial points for each player
void initialpoints(int players, node_t *player);
// function to play the game
void playgame(FILE *file, int rounds, int number, int decks, int players, int cards, int stockcards, int discardcards, int *stockpile, int *discardpile, node_t *player_list, int demo);
// function to print welcome sign
void welcome(int rounds, int decks, int cards);
// function to print welcome sign to log file
void welcome_log(FILE *file, int rounds, int decks, int cards);

#endif
