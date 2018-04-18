#ifndef CARD_FUNCTIONS_H
#define CARD_FUNCTIONS_H
#include "card_structs.h"
void printMessage(const char *s) {			// This is just a dummy function to test out source control
	printf("%s\n", s);
}

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard)
{
	char * sptr;
	sptr = (char *)malloc(10 * sizeof(char));

	// your code goes here
	int yourVal = yourCard.face;
	int dealerVal = dealersCard.face;

	if (yourVal < dealerVal) {
		strcpy(sptr, "Dealer");
	}
	else if (yourVal > dealerVal) {
		strcpy(sptr, "You");
	}
	else strcpy(sptr, "Draw.");

	return sptr;
}

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard)
{
	char * sptr = 0;
	// your code goes here
	char *stringArray;
	stringArray = (char*)calloc(30, sizeof(char));

	strcat(stringArray, faces[aCard.face]);
	strcat(stringArray, " of ");
	strcat(stringArray, suits[aCard.suit]);
	strcat(stringArray, "\0");
	sptr = stringArray;

	return sptr;
}

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHands)
{
	int i, n;
	int found = 0;
	hand newHand;
	int ncards = 0;

	SUIT newSuit;
	FACE newFace;

	// your code goes here

	for (i = 0; i < 5; i++)
	{
		newSuit = (SUIT)(rand() % 4);
		newFace = (FACE)(rand() % 13);
		if (i == 0) {
			newHand.cards[i].suit = newSuit;
			newHand.cards[i].face = newFace;
		}

		for (n = 0; n < ncards; n++) {
			//first if is checking for currenthand
			if (newSuit == newHand.cards[n].suit &&\
				newFace == newHand.cards[n].face) {
				/*
				// ----------DEBUG-----------
				printf("Drew %s of %s which has been seen before.\n",
				faces[newFace], suits[newSuit]);
				printf("Had same card %d times Redrawing.\n", found);
				// --------------------------
				*/
				newSuit = (SUIT)(rand() % 4);
				newFace = (FACE)(rand() % 13);
			}
			if (numHands > 0) {
				//checks if current hand has been seen in previous hands
				for (int j = 0; j < numHands; j++) {
					if (handsDealt[j].cards[n].suit == newSuit && \
						handsDealt[j].cards[n].face == newFace) {
						/*
						//----------DEBUG-----------
						puts("Got to line 167.");
						printf("\n\nDrew %s of %s which has been seen before.\n\n",
						faces[newFace], suits[newSuit]);
						-----------------------------
						*/
						newSuit = (SUIT)(rand() % 4);
						newFace = (FACE)(rand() % 13);
					}
				}
			}
		}
		newHand.cards[i].face = newFace;
		newHand.cards[i].suit = newSuit;
		ncards++;
	}



	return newHand;
}

// returns true if the hand contains four ACES
bool fourAces(hand aHand)
{
	int i;
	int numAces = 0;
	bool fourAces = false;

	// your code goes here
	for (int i = 0; i < 5; i++) {
		if (strcmp(faces[aHand.cards[i].face], faces[ACE]) == 0) {
			numAces++;
		}
	}
	if (numAces == 4) {
		puts("\nThe final hand of 4 aces:");
		for (int i = 0; i < 5; i++) {
			printf("Card %d:\t%s of %s\n", i + 1, faces[aHand.cards[i].face], suits[aHand.cards[i].suit]);
		}
		fourAces = true;
	}
	return fourAces;

}


#endif // !CARD_FUNCTIONS.H
