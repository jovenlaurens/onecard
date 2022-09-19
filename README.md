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

## QnA (Implementation Choice)

### Why did i immediately focus heavily on linked list instead of making array first?
When I build code, I really need to have a strong foundation for the code as I have difficulty connecting player to the system of the game. That is why my project progress is qute slow compared to the others. However, the moment I manage to perfect the player linked list, I already know all the steps that must be done to complete the project as having a strong base can lead to more easier building process. 

### Why did i make the initialize stockpile to be a sequence of i = i + 1?
The reason is because i also want to compare to determine which one is higher, where it is needed during the process finding the first player. That is why, I make the initialize stockpile to be 1 - 52 in order to make it more easier to compare.

### Why did i use a counter to calculate the ammount of stockpile and discardpile?
One of the greatest challenge with this project is managing the memory and avoid memory leak or overflow. I choose the "counter" method in order to avoid those kind of memory accident. Instead of reallocating the memory, I have the counter that calculate how many card is left in the stockpile or in the discard pile without needing to reallocate. If the counter for the stockpile reach 0, it indicates I already used all of the cards in the stock pile.

### Why did i keep building the project on a single file first before dividing into several files?
Since I am building this project alone and having multiple files can make my work more harder as I need to compile more than 1 file. However, by keeping the file into 1 and divide it during the final time, it can make my work more efficient.

### Why did i add a counter of "attack2" and "attack3" for the attack card?
As I notice the game let you to stack all the attack card, I need to have a variable that counts the number of attack card has been used. That is why I decided to make a counter to account the ammount of "attack2" or "attack3" are being used. If the player already draw the card due to the attack card, then it will reset to 0. This also make the game fun as you can stack all the attack card making a combo with it and target to a specific player.


