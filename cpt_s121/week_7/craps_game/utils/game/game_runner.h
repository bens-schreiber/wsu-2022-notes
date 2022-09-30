enum Status
{
    EXIT,
    CONTINUE
};

// Runs a function (game) until it returns 0
void play_game(int *game(void))
{
    while ((*game)());
}