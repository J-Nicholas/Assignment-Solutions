// Week 22 Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "time.h"
#include "card_functions.h"

void main()
{
	int i = 0;
	hand myHand, dealersHand;
	int seed = time(NULL);
	srand(seed);
	hand hands[10];

	myHand = dealHand(hands, 0);		// deal the first hand
	hands[0] = myHand;					// add this new hand to the set of dealt hands
	dealersHand = dealHand(hands, 1);	// deal another hand; let dealHand know what has already been dealt

	while (i<5)							// here you are just comparing each card one at a time in the two hands

	{
		printf("card#%d: %s (you) vs. %s (dealer). Winner: %s \n", i + 1,
			printCard(myHand.cards[i]), printCard(dealersHand.cards[i]),
			compareCards(myHand.cards[i], dealersHand.cards[i]));
		i++;
	}

	while (1)							// now try to deal 4 Aces !
	{
		myHand = dealHand(hands, 0);	// deal a new hand; assume new deck every time, so nothing dealt already
		if (fourAces(myHand)) break;	// does it contain 4 ACES?
		i++;							// keep track of number of hands dealt
	}
	printf("\n\n4 aces found after %d hands \n\n\n", i);	// print out how many hands it took to find 4 aces
	printMessage("This is the end of main.");
}