# P2 Project (One Card)

P2 is a c project where it simulate one card games scenario. Users will face another player in a card game scenario, where the player task need to empty their card hands before other player does.

## Overview

One Card is a rather simple game played by n persons over a pre-decided number of rounds r . A total of d decks of Poker cards, excluding Jokers, are shuffled and c cards are offered to each player. Before the game start each player is offered an extra card to determine the playing order. This game is then discarded. The game will be played counter-clockwise, starting with the player who received the extra card with lowest rank. Once the playing order has been decided all those initial n cards are directly put in the discard pile. Finally, the game starts with the first card of the stock pile being posed face-up, to initiate the rank and suit.

As the game starts each player, following the defined order, plays exactly one card either following the rank or the suit defined by the previous card. Any played card directly goes into the discard pile, and anyone who is unable to play should draw a card from the top of the stock pile. If the stock pile is exhausted, the discard pile is shuffled and used as stock pile.

As soon as a player has discarded all his cards the rounds stops. All other players receive a penalty equal to the number of cards left in their hands. The player who won the round initiates the following one, all the other rules remain unchanged. At the end of the r rounds the final score of each player is determined by summing up of all his penalties. The person with highest score wins. In case of equality more than one player can be declared winner.

## One Card Rules

### Cards split into four main categories

- **Attack**:
  - Cards with rank 2: the next player draws two cards from the stock pile
  - Cards with rank 3: the next player draws three cards from the stock pile
- **Defense**:
  - Cards with rank 7: cancel an attack, i.e. do not draw any card if a 2 or a 3 was played before
- **Action**:
  - Queen cards: reverse the playing order from counter-clockwise to clockwise or clockwise to counterclockwise
  - Jack cards: skip the next player;
- **Regular**:
  - any other card has no special effect and is only used to match the previous card’s rank or suit

### Notes on cards and attacks

- The effect of the attack cards is cumulative.
- A Queen or a Jack, of same suit as the previous card, can be played to redirect an attack on the previous player, or the player after the next one, respectively
- When under an attack, a player not playing any special card (2, 3, 7, Q, J) must draw cards from the stock pile, and this ends his turn;

## How to setup

1. Compiling the program using this command "gcc onecard.c function_list.c -O2 -Werror -Wall -Wextra -Wpedantic -std=c11 -o onecard"
2. Before running the code, make sure you have run ".\onecard -h" or ".\onecard --help" and read the description
3. After reading the description, you can run the program with some custom settings, where you can type in the format of "onecard.exe "the command""
4. If you preferred to use the default setting, you can simply run the program by using ".\onecard"
5. DO NOT INPUT A CHARACTER OF WORD DURING THE GAME AND INPUT 1 INPUT NUMBER ONLY
   1. This is because my program only accept number only, where if you add a character of word, it will cause my program to run into an infinite loop. If you encounter an infinite loop due to mis-input, then press "Ctrl + C" to stop it. Since my program read 1 input, adding 2 input will cause my program to run 1 step ahead where you already play 2 players immediately.
6. DO NOT CLOSE THE .EXE FILE WHEN IT IS STILL RUNNING
   1. This will cause the log file to stuck in a loop where it will keep writing while it never ends. To solve this kinds of issue, you need to restart your computer as deleting it won't works due to the file keep running.

## Remainder

Right now the current project is still under development, this file will undergo many changes. If there is any issue or bugs, it will be really appreciated if you can give any feedback or advice by making an issues at gitea. Thank you very much.

## Additional information

For more information about the development of the project, please read the file named "Changelog.md". It contain all changes that happen for the project chronologically.




