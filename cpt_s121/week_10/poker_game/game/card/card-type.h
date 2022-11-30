#pragma once
typedef enum
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} CardValue;

typedef enum
{
    HEART,
    DIAMOND,
    CLUB,
    SPADE
} CardFace;

typedef struct
{
    CardValue value;
    CardFace face;
} Card;