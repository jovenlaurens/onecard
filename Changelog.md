# Changelog

All notable changes to this project will be documented in this file

## 2020 - 10 - 28

### Added

- onecard.c
  - define player structure
  - define card structure
  - draft the function to add card
  - draft the function to play card
  - draft the main function to run the whole function

## 2020 - 11 - 05

### Added

- onecard.c
  - add a function to shuffle deck
  - add a function to display deck
  - add a function to sort deck
  - add a function for deck list
  - add an integer array to define the deck structure
  - add some specific requirement card for the draw and add card function

## 2020 - 11 - 16

### Added

- onecard.c
  - add a command line argument for the main function

## 2020 - 11 - 18

### Added

- onecard.c
  - add a cyclic linked list strucutre for the player
  - add a function to build the cyclic linked list
  - add a function to initialize the linked list

- onecard.c
  - player structure now consist of position, card hand, and structure pointing next

## 2020 - 11 - 19

### Added

- onecard.c
  - add a function to find the order of the player
  - add a function to deal cards to the player
  - add stockpile and discardpile array
  - add a function to display a single card
  - added srand(time(NULL)) to the shuffle deck in order to provide randomness for each test run
  - added the play game system using while (true) loop

### Changed

- onecard.c
  - player structure now consist of position, card hand, number of card hand, and structure pointing next
  - add a counter to count the number of stockpile and discard pile
  - all function that maintaining decks now use stockcard as its inputs to replace decks and numbers
  - stockpile and discardpile array are controlled using dynamic array

## 2020 - 11 - 20

### Added

- onecard.c
  - add a function to restore stockpile
  - add a function to compare card
  - add a function to get the winner
  - add a function to play the game
  - add a function to play and draw the card
  - add a function to initial every player score
  - add a function to compare attack cards
  - add a function to dump all print value to log file
  - add a counter called "demo" to differentiate demo and non-demo mode
  - add a counter called "order" to differentiate between clockwise and counter-clockwise movement
  - add a counter called "attack2" and "attack3" to count the stack of card 2 and 3
- function_list.c
  - add a function to show player stats
- function_list.h
  - added all the structure and macros to the header file
  - define all the functions
  

### Changed

- onecard.c
  - changed the condition for the line argument for the main function
  - condense all the commands into a several functions
  - removed unused functions
  - added data types of total point for the player stucture
  - the player structure now uses circular doubly linked list
  - now special card, such as 2,3,7,J,and Q can be used
  - line argument now support log and demo mode
  - adding card is based on the value of "attack2" and "attack3"
  - change some visual change for the card display
  - change the file into 3 parts, "onecard.c", "function_list.c", and "function_list.h"
  - onecard.c is left with main function only

