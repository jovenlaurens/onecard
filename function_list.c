#include "function_list.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// functions
// function to get a node
node_t *Initialize(int position) {
    node_t *head;
    head = (node_t *)calloc(1, sizeof(node_t));
    if (head == NULL) {
        fprintf(stderr, "Failed to assign memory!\n");
        exit(-1);
    }
    head->next = NULL;
    head->position = position;
    return head;
}

// function to build the linked list
node_t *initialize_player(int player, node_t **ptr) {
    node_t *head = *ptr;
    node_t *current = head;
    for (int i = 2; i <= player; i++) {
        node_t *node = Initialize(i);
        current->next = node;
        node->prev = current;
        current = current->next;
    }
    current->next = head;
    head->prev = current;
    return head;
}

// function deck list
void decklist(int rank, int suit) {
    switch (suit) {
        case 0:
            printf("[Spades ");
            break;
        case 1:
            printf("[Hearts ");
            break;
        case 2:
            printf("[Diamonds ");
            break;
        case 3:
            printf("[Clubs ");
            break;
        default:
            printf("[Invalid Input ");
            break;
    }
    switch (rank) {
        case ACE:
            printf("A] ");
            break;
        case KING:
            printf("K] ");
            break;
        case QUEEN:
            printf("Q] ");
            break;
        case JACK:
            printf("J] ");
            break;
        default:
            printf("%d] ", rank);
            break;
    }
}

// function deck list log
void decklist_log(FILE *file, int rank, int suit) {
    switch (suit) {
        case 0:
            fprintf(file, "[Spades ");
            break;
        case 1:
            fprintf(file, "[Hearts ");
            break;
        case 2:
            fprintf(file, "[Diamonds ");
            break;
        case 3:
            fprintf(file, "[Clubs ");
            break;
        default:
            fprintf(file, "[Invalid Input ");
            break;
    }
    switch (rank) {
        case ACE:
            fprintf(file, "A] ");
            break;
        case KING:
            fprintf(file, "K] ");
            break;
        case QUEEN:
            fprintf(file, "Q] ");
            break;
        case JACK:
            fprintf(file, "J] ");
            break;
        default:
            fprintf(file, "%d] ", rank);
            break;
    }
}

// function to display deck
void dispdeck(FILE *file, int *list, int stockcards, int demo) {
    card deck;
    for (int i = 0; i < stockcards; i++) {
        deck.rank = list[i] % 13 + 2;
        deck.suit = (int)floor(list[i] / 13);
        if (demo == 1) {
            decklist(deck.rank, deck.suit);
        }
        decklist_log(file, deck.rank, deck.suit);
    }
}

// function to display card
void dispcard(int cards) {
    card deck;
    deck.rank = cards % 13 + 2;
    deck.suit = (int)floor(cards / 13);
    decklist(deck.rank, deck.suit);
}

void dispcard_log(FILE *file, int cards) {
    card deck;
    deck.rank = cards % 13 + 2;
    deck.suit = (int)floor(cards / 13);
    decklist_log(file, deck.rank, deck.suit);
}

// function to sort deck
void initialize_deck(int *list, int number, int deck) {
    for (int i = 0; i < deck * number; i++) {
        list[i] = i % number;
    }
}

// function to shuffle deck
void shuffle(FILE *file, int *list, int stockcards, int demo) {
    srand((unsigned int)time(NULL));
    printf("shuffling cards...\n");
    fprintf(file, "shuffling cards...\n");
    // shuffling deck 1000 cycle
    for (int i = 0; i < 100; i++) {
        int from = rand() % stockcards;
        int to = rand() % stockcards;
        int card = list[from];
        list[from] = list[to];
        list[to] = card;
    }
    fprintf(file, "Shuffle result:\n");
    if (demo == 1) {
        printf("Shuffle result:\n");
    }
    dispdeck(file, list, stockcards, demo);
}

// function to give cards
void assigncards(FILE *file, int players, int cards, int *stockcard, int *stockpile, node_t *player, int demo) {
    for (int i = 0; i < players; i++) {
        for (int j = 0; j < cards; j++) {
            player->card_hand[j] = stockpile[*stockcard - 1];
            *stockcard = *stockcard - 1;
        }
        player->stockcards = cards;
        player = player->next;
    }
    printf("Dealing cards...\n");
    fprintf(file, "Dealing cards...\n");
    for (int i = 0; i < players; i++) {
        if (demo == 1) {
            printf("Player %d: ", player->position);
        }
        fprintf(file, "Player %d: ", player->position);
        for (int j = 0; j < cards; j++) {
            if (demo == 1) {
                dispcard(player->card_hand[j]);
            }
            dispcard_log(file, player->card_hand[j]);
        }
        player = player->next;
        if (demo == 1) {
            printf("\n");
        }
        fprintf(file, "\n");
    }
}

// function to find winner
void getwinner(FILE *file, int players, node_t *player_list) {
    int winner[20];
    winner[0] = -1000;
    for (int i = 1; i <= players; i++) {
        winner[i] = player_list->points;
        player_list = player_list->next;
    }
    for (int i = 1; i <= players; i++) {
        if (winner[0] < winner[i]) {
            winner[0] = winner[i];
        }
    }
    for (int i = 1; i <= players; i++) {
        if (winner[0] == winner[i]) {
            printf("Player %d wins the game!\n", i);
            fprintf(file, "Player %d wins the game!\n", i);
        }
    }
}

// function to find order of player
int playerorder(FILE *file, int players, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t *player_list) {
    printf("\nDetermining the playing order...\n");
    fprintf(file, "\nDetermining the playing order...\n");
    int order[20];
    order[0] = 0;
    for (int i = 0; i < players; i++) {
        printf("Player %d: ", player_list->position);
        fprintf(file, "Player %d: ", player_list->position);
        dispcard(stockpile[*stockcards - 1]);
        dispcard_log(file, stockpile[*stockcards - 1]);
        order[i + 1] = stockpile[*stockcards - 1];
        discardpile[*discardcards] = stockpile[*stockcards - 1];
        *stockcards = *stockcards - 1;
        *discardcards = *discardcards + 1;
        player_list = player_list->next;
        printf("\n");
        fprintf(file, "\n");
    }
    order[0] = 0;
    int first = 0;
    for (int i = 1; i <= players; i++) {
        if (order[0] < order[i]) {
            order[0] = order[i];
            first = i;
        }
    }
    printf("The game will start with player %d", first);
    fprintf(file, "The game will start with player %d", first);
    return first;
}

// function to compare card
int comparecard(int play_card, int last_card) {
    card last;
    card play;
    last.rank = last_card % 13;
    last.suit = (int)floor(last_card / 13);
    play.rank = play_card % 13;
    play.suit = (int)floor(play_card / 13);
    if (last.rank == play.rank || last.suit == play.suit) {
        return 1;
    } else {
        return 0;
    }
}

// function to restore stockpile
void restore_stockpile(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, int demo) {
    printf("Stock pile exhausted. Shuffling the discard pile and restore the stock pile\n");
    fprintf(file, "Stock pile exhausted. Shuffling the discard pile and restore the stock pile\n");
    for (int i = 0; i < *discardcards - 1; i++) {
        stockpile[i] = discardpile[i];
    }
    *stockcards = *discardcards - 1;
    discardpile[0] = discardpile[*discardcards];
    *discardcards = 1;
    shuffle(file, stockpile, *stockcards, demo);
    printf("\n");
}

// function to draw cards
void draw(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t *current_player, int *attack2, int *attack3, int demo) {
    if (*attack2 > 0 || *attack3 > 0) {
        if (*attack2 > 0) {
            for (int k = 0; k < *attack2; k++) {
                for (int i = 0; i < 2; i++) {
                    current_player->card_hand[current_player->stockcards] = stockpile[*stockcards - 1];
                    *stockcards = *stockcards - 1;
                    current_player->stockcards = current_player->stockcards + 1;
                    if (*stockcards == 0) {
                        restore_stockpile(file, stockcards, discardcards, stockpile, discardpile, demo);
                    }
                }
            }
            *attack2 = 0;
        }
        if (*attack3 > 0) {
            for (int k = 0; k < *attack3; k++) {
                for (int i = 0; i < 3; i++) {
                    current_player->card_hand[current_player->stockcards] = stockpile[*stockcards - 1];
                    *stockcards = *stockcards - 1;
                    current_player->stockcards = current_player->stockcards + 1;
                    if (*stockcards == 0) {
                        restore_stockpile(file, stockcards, discardcards, stockpile, discardpile, demo);
                    }
                }
            }
            *attack3 = 0;
        }
    } else {
        current_player->card_hand[current_player->stockcards] = stockpile[*stockcards - 1];
        *stockcards = *stockcards - 1;
        current_player->stockcards = current_player->stockcards + 1;
        if (*stockcards == 0) {
            restore_stockpile(file, stockcards, discardcards, stockpile, discardpile, demo);
        }
    }
}

// function to compare attack card
int compareattack(int play_card) {
    switch (play_card % 13) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 5:
            return 1;
        default:
            return 0;
    }
}
// function to show players stat
void stat(FILE *file, int players, node_t *player_list) {
    while (player_list->position != 1) {
        player_list = player_list->next;
    }
    for (int i = 0; i < players; i++) {
        printf("Player %d has %d card(s)\n", player_list->position, player_list->stockcards);
        fprintf(file, "Player %d has %d card(s)\n", player_list->position, player_list->stockcards);
        player_list = player_list->next;
    }
}
// function to play cards
int play(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t **player_list, int *attack2, int *attack3, int *order, int *skip, int demo) {
    int position;
    node_t *current_player = *player_list;
    if (scanf("%d", &position) == 1) {
        if (position > 0) {
            if (*attack2 == 0 && *attack3 == 0) {
                if (comparecard(current_player->card_hand[position - 1], discardpile[*discardcards]) == 1) {
                    printf("Player %d plays: ", current_player->position);
                    fprintf(file, "Player %d plays: ", current_player->position);
                    dispcard(current_player->card_hand[position - 1]);
                    dispcard_log(file, current_player->card_hand[position - 1]);
                    if (current_player->card_hand[position - 1] % 13 == 0) {
                        *attack2 = 1;
                    }
                    if (current_player->card_hand[position - 1] % 13 == 1) {
                        *attack3 = 1;
                    }
                    if (current_player->card_hand[position - 1] % 13 == 5) {
                        *attack2 = 0;
                        *attack3 = 0;
                    }
                    if (current_player->card_hand[position - 1] % 13 == 10) {
                        *order = *order * (-1);
                    }
                    if (current_player->card_hand[position - 1] % 13 == 9) {
                        *skip = 1;
                    }
                    discardpile[*discardcards + 1] = current_player->card_hand[position - 1];
                    *discardcards = *discardcards + 1;
                    current_player->stockcards = current_player->stockcards - 1;
                    if (current_player->stockcards == 0) {
                        printf("\nPlayer %d wins!", current_player->position);
                        fprintf(file, "\nPlayer %d wins!", current_player->position);
                        return 1;
                    }
                    for (int i = position - 1; i < current_player->stockcards; i++) {
                        current_player->card_hand[i] = current_player->card_hand[i + 1];
                    }
                    printf("\n");
                    fprintf(file, "\n");
                } else {
                    printf("Invalid input! Try again!\n");
                    fprintf(file, "Invalid input! Try again!\n");
                    play(file, stockcards, discardcards, stockpile, discardpile, &current_player, attack2, attack3, order, skip, demo);
                }
            } else if (*attack2 > 0 || *attack3 > 0) {
                if (compareattack(current_player->card_hand[position - 1]) == 1) {
                    printf("Player %d plays: ", current_player->position);
                    fprintf(file, "Player %d plays: ", current_player->position);
                    dispcard(current_player->card_hand[position - 1]);
                    dispcard_log(file, current_player->card_hand[position - 1]);
                    if (current_player->card_hand[position - 1] % 13 == 0) {
                        *attack2 = *attack2 + 1;
                    }
                    if (current_player->card_hand[position - 1] % 13 == 1) {
                        *attack3 = *attack3 + 1;
                    }
                    if (current_player->card_hand[position - 1] % 13 == 5) {
                        *attack2 = 0;
                        *attack3 = 0;
                    }
                    discardpile[*discardcards + 1] = current_player->card_hand[position - 1];
                    *discardcards = *discardcards + 1;
                    current_player->stockcards = current_player->stockcards - 1;
                    if (current_player->stockcards == 0) {
                        printf("\nPlayer %d wins!", current_player->position);
                        fprintf(file, "\nPlayer %d wins!", current_player->position);
                        return 1;
                    }
                    for (int i = position - 1; i < current_player->stockcards; i++) {
                        current_player->card_hand[i] = current_player->card_hand[i + 1];
                    }
                    printf("\n");
                    fprintf(file, "\n");
                } else {
                    printf("Invalid input! Try again!\n");
                    fprintf(file, "Invalid input! Try again!\n");
                    play(file, stockcards, discardcards, stockpile, discardpile, &current_player, attack2, attack3, order, skip, demo);
                }
            }
        } else if (position == 0) {
            draw(file, stockcards, discardcards, stockpile, discardpile, current_player, attack2, attack3, demo);
        }
    }
    return 0;
}

// function to play cards automatic
int play_demo(FILE *file, int *stockcards, int *discardcards, int *stockpile, int *discardpile, node_t **player_list, int *attack2, int *attack3, int *order, int *skip, int demo) {
    int position;
    node_t *current_player = *player_list;
    position = rand() % (current_player->stockcards + 1);
    if (position > 0) {
        if (*attack2 == 0 && *attack3 == 0) {
            if (comparecard(current_player->card_hand[position - 1], discardpile[*discardcards]) == 1) {
                printf("Player %d plays: ", current_player->position);
                fprintf(file, "Player %d plays: ", current_player->position);
                dispcard(current_player->card_hand[position - 1]);
                dispcard_log(file, current_player->card_hand[position - 1]);
                if (current_player->card_hand[position - 1] % 13 == 0) {
                    *attack2 = 1;
                }
                if (current_player->card_hand[position - 1] % 13 == 1) {
                    *attack3 = 1;
                }
                if (current_player->card_hand[position - 1] % 13 == 5) {
                    *attack2 = 0;
                    *attack3 = 0;
                }
                if (current_player->card_hand[position - 1] % 13 == 10) {
                    *order = *order * (-1);
                }
                if (current_player->card_hand[position - 1] % 13 == 9) {
                    *skip = 1;
                }
                discardpile[*discardcards + 1] = current_player->card_hand[position - 1];
                *discardcards = *discardcards + 1;
                current_player->stockcards = current_player->stockcards - 1;
                if (current_player->stockcards == 0) {
                    printf("\nPlayer %d wins!", current_player->position);
                    fprintf(file, "\nPlayer %d wins!", current_player->position);
                    return 1;
                }
                for (int i = position - 1; i < current_player->stockcards; i++) {
                    current_player->card_hand[i] = current_player->card_hand[i + 1];
                }
                printf("\n");
                fprintf(file, "\n");
            } else {
                play_demo(file, stockcards, discardcards, stockpile, discardpile, &current_player, attack2, attack3, order, skip, demo);
            }
        } else if (*attack2 > 0 || *attack3 > 0) {
            if (compareattack(current_player->card_hand[position - 1]) == 1) {
                printf("Player %d plays: ", current_player->position);
                fprintf(file, "Player %d plays: ", current_player->position);
                dispcard(current_player->card_hand[position - 1]);
                dispcard_log(file, current_player->card_hand[position - 1]);
                if (current_player->card_hand[position - 1] % 13 == 0) {
                    *attack2 = *attack2 + 1;
                }
                if (current_player->card_hand[position - 1] % 13 == 1) {
                    *attack3 = *attack3 + 1;
                }
                if (current_player->card_hand[position - 1] % 13 == 5) {
                    *attack2 = 0;
                    *attack3 = 0;
                }
                discardpile[*discardcards + 1] = current_player->card_hand[position - 1];
                *discardcards = *discardcards + 1;
                current_player->stockcards = current_player->stockcards - 1;
                if (current_player->stockcards == 0) {
                    printf("\nPlayer %d wins!", current_player->position);
                    fprintf(file, "\nPlayer %d wins!", current_player->position);
                    return 1;
                }
                for (int i = position - 1; i < current_player->stockcards; i++) {
                    current_player->card_hand[i] = current_player->card_hand[i + 1];
                }
                printf("\n");
                fprintf(file, "\n");
            } else {
                play_demo(file, stockcards, discardcards, stockpile, discardpile, &current_player, attack2, attack3, order, skip, demo);
            }
        }
    } else if (position == 0) {
        draw(file, stockcards, discardcards, stockpile, discardpile, current_player, attack2, attack3, demo);
    }
    return 0;
}

// function to initial points for each player
void initialpoints(int players, node_t *player) {
    for (int i = 0; i < players; i++) {
        player->points = 0;
        player = player->next;
    }
}

// function to play the game
void playgame(FILE *file, int rounds, int number, int decks, int players, int cards, int stockcards, int discardcards, int *stockpile, int *discardpile, node_t *player_list, int demo) {
    int result = 0;
    int match = 0;
    int order = 1;
    int skip = 0;
    for (int i = 1; i <= rounds; i++) {
        initialize_deck(stockpile, number, decks);
        shuffle(file, stockpile, stockcards, demo);
        if (demo == 1) {
            printf("\n");
        }
        printf("\n");
        fprintf(file, "\n");
        fprintf(file, "\n");
        assigncards(file, players, cards, &stockcards, stockpile, player_list, demo);
        int firstplayer = playerorder(file, players, &stockcards, &discardcards, stockpile, discardpile, player_list);
        printf("\n");
        fprintf(file, "\n");
        printf("\n---- Game start ----\n");
        fprintf(file, "\n---- Game start ----\n");
        int attack2 = 0;
        int attack3 = 0;
        while (player_list->position != firstplayer) {
            player_list = player_list->next;
        }
        printf("---- Player %d's Round ----\n", player_list->position);
        fprintf(file, "---- Player %d's Round ----\n", player_list->position);
        stat(file, players, player_list);
        printf("\n");
        printf("First card: ");
        fprintf(file, "First card: ");
        dispcard(stockpile[stockcards - 1]);
        dispcard_log(file, stockpile[stockcards - 1]);
        discardpile[discardcards + 1] = stockpile[stockcards - 1];
        stockcards = stockcards - 1;
        discardcards = discardcards + 1;
        printf("\n");
        fprintf(file, "\n");
        while (1) {
            printf("Player %d cards: ", player_list->position);
            fprintf(file, "Player %d cards: ", player_list->position);
            for (int j = 0; j < player_list->stockcards; j++) {
                dispcard(player_list->card_hand[j]);
                dispcard_log(file, player_list->card_hand[j]);
            }
            if (attack2 == 0 && attack3 == 0) {
                for (int i = 0; i < player_list->stockcards; i++) {
                    match = comparecard(player_list->card_hand[i], discardpile[discardcards]);
                    if (match == 1) {
                        break;
                    }
                }
                if (match == 1) {
                    printf("\nInput 1 ~ %d to play a card or 0 to pass the turn\n", player_list->stockcards);
                    fprintf(file, "\nInput 1 ~ %d to play a card or 0 to pass the turn\n", player_list->stockcards);
                } else if (match == 0) {
                    printf("\nNo valid move! Input 0 to pass the turn.\n");
                    fprintf(file, "\nNo valid move! Input 0 to pass the turn.\n");
                }
            } else if (attack2 > 0 || attack3 > 0) {
                for (int i = 0; i < player_list->stockcards; i++) {
                    match = compareattack(player_list->card_hand[i]);
                    if (match == 1) {
                        break;
                    }
                }
                if (match == 1) {
                    printf("\nInput 1 ~ %d to play a card or 0 to pass the turn\n", player_list->stockcards);
                    fprintf(file, "\nInput 1 ~ %d to play a card or 0 to pass the turn\n", player_list->stockcards);
                } else if (match == 0) {
                    printf("\nNo valid move! Input 0 to pass the turn.\n");
                    fprintf(file, "\nNo valid move! Input 0 to pass the turn.\n");
                }
            }
            if (demo == 0) {
                result = play(file, &stockcards, &discardcards, stockpile, discardpile, &player_list, &attack2, &attack3, &order, &skip, demo);
            } else if (demo == 1) {
                result = play_demo(file, &stockcards, &discardcards, stockpile, discardpile, &player_list, &attack2, &attack3, &order, &skip, demo);
            }
            if (result == 1) {
                break;
            }
            if (order == 1) {
                if (skip == 0) {
                    player_list = player_list->next;
                } else if (skip == 1) {
                    player_list = player_list->next;
                    player_list = player_list->next;
                    skip = 0;
                }
            } else if (order == -1) {
                if (skip == 0) {
                    player_list = player_list->prev;
                } else if (skip == 1) {
                    player_list = player_list->prev;
                    player_list = player_list->prev;
                    skip = 0;
                }
            }
            printf("\n");
            fprintf(file, "\n");
            printf("---- Player %d's Round ----\n", player_list->position);
            fprintf(file, "---- Player %d's Round ----\n", player_list->position);
            stat(file, players, player_list);
            printf("\n");
            fprintf(file, "\n");
            printf("Last card: ");
            fprintf(file, "Last card: ");
            dispcard(discardpile[discardcards]);
            dispcard_log(file, discardpile[discardcards]);
            printf("\n");
            fprintf(file, "\n");
        }
        printf("\n");
        fprintf(file, "\n");
        printf("\n--- Stats ---\n");
        fprintf(file, "\n--- Stats ---\n");
        printf("Round %d result:\n", i);
        fprintf(file, "Round %d result:\n", i);
        while (player_list->position != 1) {
            player_list = player_list->next;
        }
        for (int j = 0; j < players; j++) {
            player_list->points = player_list->points - player_list->stockcards;
            printf("Player %d: %d, total: %d\n", player_list->position, player_list->stockcards * (-1), player_list->points);
            fprintf(file, "Player %d: %d, total: %d\n", player_list->position, player_list->stockcards * (-1), player_list->points);
            player_list = player_list->next;
        }
        printf("Round %d ends.\n", i);
        fprintf(file, "Round %d ends.\n", i);
        printf("\n");
        fprintf(file, "\n");
    }
}

// function to print welcome sign
void welcome(int rounds, int decks, int cards) {
    puts(
        "########################\n"
        "#                      #\n"
        "# Welcome to One Card! #\n"
        "#                      #\n"
        "########################\n"
        "\n");
    printf("---- Initial setup ----\n");
    printf("Number of rounds: %d\n", rounds);
    printf("Number of decks: %d\n", decks);
    printf("Number of cards: %d\n", cards);
    printf("\n");
}
// function to print welcome sign to log file
void welcome_log(FILE *file, int rounds, int decks, int cards) {
    fprintf(file, "########################\n");
    fprintf(file, "#                      #\n");
    fprintf(file, "# Welcome to One Card! #\n");
    fprintf(file, "#                      #\n");
    fprintf(file, "########################\n");
    fprintf(file, "\n");
    fprintf(file, "---- Initial setup ----\n");
    fprintf(file, "Number of rounds: %d\n", rounds);
    fprintf(file, "Number of decks: %d\n", decks);
    fprintf(file, "Number of cards: %d\n", cards);
    fprintf(file, "\n");
}
