# One Card

One Card is a rather simple game played by `n` persons over a pre-decided number of rounds `r` . A total of d decks of Poker cards, excluding Jokers, are shuffled and c cards are offered to each player. Before the game start each player is offered an extra card to determine the playing order. This game is then discarded. The game will be played counter-clockwise, starting with the player who received the extra card with lowest rank. Once the playing order has been decided all those initial n cards are directly put in the discard pile. Finally, the game starts with the first card of the stock pile being posed face-up, to initiate the rank and suit.

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

## Getting started

1. Clone the repository

2. Compile the project:

```
gcc onecard.c function_list.c -O2 -Werror -Wall -Wextra -Wpedantic -std=c11 -o onecard
```

3. Run the program

4. If you prefer to customize your game, you can run the program with some custom settings, where you can type in the format of `./onecard "command"` (for bash or powershell user) or `onecard.exe "command"` (for command prompt user),

## Additional information

For more information about the development of the project, please read the file named "Changelog.md". It contain all changes that happen for the project chronologically.
