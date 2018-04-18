#ifndef CARD_STRUCTS_H
#define CARD_STRUCTS_H

typedef enum suits
{
	CLUBS, DIAMONDS, HEARTS, SPADES
} SUIT;

char suits[][10] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };

typedef enum faces
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} FACE;
char faces[][10] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };

typedef struct card
{
	SUIT suit;
	FACE face;
} card;

typedef struct hand
{
	card cards[5];
} hand;


#endif // !CARD_STRUCTS_H
