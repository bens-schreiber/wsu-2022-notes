#pragma once
#include "../messages/messages.h"
#include "../game/game.h"
#include <stdio.h>
// Displays the starting menu. Returns -1 to exit the menu.
int displayMenu();

// Waits for menu option input
// 1 - print rules
// 2 - start game
// 3 - exit
int _awaitMenuInput();