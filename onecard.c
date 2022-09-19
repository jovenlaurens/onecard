#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "function_list.h"

// main function
int main(int argc, char *argv[]) {
    int rounds = 1, decks = 2, players = 4, cards = 5, demo = 0;
    char filename[0x100];
    char *logname = "onecard";
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            puts(
                "-h|--help               print this help message\n"
                "--log filename          write the logs in filename (default: onecard.log)\n"
                "-n n|--player-number= n n players, n must be larger than 2 (default: 4)\n"
                "-c c|--initial-cards= c deal c cards per player, c must be at least 2 (default: 5)\n"
                "-d d|--decks= d         use d decks 52 cards eaposition, d must be at least 2 (default: 2)\n"
                "-r r|--rounds= r        play r rounds, r must be at least 1 (default: 1)\n"
                "-a|--auto               run in demo mode\n"
                "\n");
            return 0;
        }
        if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--player-number=") == 0) {
            players = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--initial-cards=") == 0) {
            cards = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--decks=") == 0) {
            decks = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--rounds=") == 0) {
            rounds = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "--log") == 0) {
            logname = argv[i + 1];
        }
        if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--auto") == 0) {
            demo = 1;
        }
    }
    snprintf(filename, sizeof(filename), "%s.log", logname);
    FILE *fd1;
    fd1 = fopen(filename, "w");
    int number = 52;
    int stockcards = decks * number;
    int discardcards = 0;
    int *stockpile = malloc((long long unsigned int)stockcards * sizeof(int));
    int *discardpile = malloc((long long unsigned int)stockcards * sizeof(int));
    welcome(rounds, decks, cards);
    welcome_log(fd1, rounds, decks, cards);
    node_t *player_list = Initialize(1);
    initialize_player(players, &player_list);
    initialpoints(players, player_list);
    playgame(fd1, rounds, number, decks, players, cards, stockcards, discardcards, stockpile, discardpile, player_list, demo);
    getwinner(fd1, players, player_list);
    free(stockpile);
    stockpile = NULL;
    free(discardpile);
    discardpile = NULL;
    for (int i = 0; i < players - 1; i++) {
        node_t *temp = player_list;
        player_list = player_list->next;
        free(temp);
        temp = NULL;
    }
    free(player_list);
    player_list = NULL;
    fclose(fd1);
    return 0;
}
