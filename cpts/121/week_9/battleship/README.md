# BattleShip by Benjamin Schreiber

## About
Created to be a player vs computer battleship game. Instead of typing in coordinates like a loser I implemented WASD keys for moving ships and the cursor. I didn't want to open up the raw input, so you'll have to press enter after any WASD key. Supports multiple keys in one enter though, such as 'www' moving up 3 times. The maximum size of the game board is 16 x 16, but the board gets shifted slightly when over 10.

## Modifiable values
Certain constants are modifiable in utils.h and game/ship/battleship_struct.h.

## Running
Created in a mac environment. I would advise downloading the docker image to run instead of running on a windows machine. Linux is fine.

https://hub.docker.com/repository/docker/benjaminschreiberwsu/battleship run `./a.out`