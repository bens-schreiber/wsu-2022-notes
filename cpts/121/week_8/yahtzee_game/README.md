# Yahtzee by benjamin schreiber
The game rules I went off of is in https://www.hasbro.com/common/instruct/yahtzee.**pdf**

To change how many rounds there are (default 13), use game/constants.h YAHTZEE_ROUNDS

The game was designed to have as many players as wanted (2 minumum). Change the definiton in game/constants.h to change the player count.

To rig the dice to check the scorecard, goto dice.c yahtzeeDiceRoll and uncomment.