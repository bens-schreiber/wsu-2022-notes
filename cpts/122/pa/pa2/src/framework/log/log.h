#pragma once
#include "consts.h"
#include <string.h>
#include <stdio.h>

int getIntInput(const char *prompt, int min, int max);

void getInput();

char *getStrInput(const char *prompt, char *str);

void clear();

int displayOption(const char *prompt);