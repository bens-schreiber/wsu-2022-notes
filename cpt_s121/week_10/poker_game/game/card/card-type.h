typedef enum
{
    ACE,
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
    KING
} CardValue;

typedef enum {
    HEART,
    DIAMOND,
    CLUB,
    SPADE
} CardFace;

typedef struct {
    CardValue value;
    CardFace face;
} Card;