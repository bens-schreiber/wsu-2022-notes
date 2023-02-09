#pragma once
#include "../consts.h"
#include <string.h>
#include <stdio.h>

int getIntInput();

void getInput();

void getStrInput(const char *prompt, char *str);

void clear();

int displayOption(const char *prompt);