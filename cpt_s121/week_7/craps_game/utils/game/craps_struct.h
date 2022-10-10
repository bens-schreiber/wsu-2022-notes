#pragma once

// A struct to keep track of all the values in the game.
// [diceSum] the value of two dice
// [wager] the value of a wager the player has placed on a round
// [houseBalance] how much money the house has
// [playerBalance] how much money the player has
// [crapsPoint] the point to roll to win
// [round] how many iterations the game has been through
typedef struct {
    int diceSum;
    int wager;
    int houseBalance;
    int playerBalance;
    int crapsPoint;
    int round;
} CrapsGame;