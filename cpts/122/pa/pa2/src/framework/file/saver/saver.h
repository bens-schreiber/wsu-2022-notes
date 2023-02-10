#pragma once
#include "src/framework/record/record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Queue **saveRecordsToFile(FILE *output, Queue **queue);