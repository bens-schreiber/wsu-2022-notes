#include "framework/stack.h"
#include "consts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Stack **tower_initialize();

void tower_play(Stack **tower, int n, int from, int to, int other);