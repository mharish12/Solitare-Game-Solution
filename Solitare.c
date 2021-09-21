#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <ctime>

#include <windows.h>

using namespace std;

struct Card {

	char *face;	char *pix;

	char *suit;

	};

typedef struct Card card;

void fillDeck(card *, char *[], char *[], char *[]);

void shuffle(card *, int);

void deal(card *);

void WaitKey();

int main()

{

	int shuffled = 1250;

	card deck[52];

	char *face[] = {"Ace","Duece","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

	char *pix[] = {"\x03","\x05","\x04","\x06"}; // - Added to original program

	char *suit[] = {"Hearts","Clubs","Diamonds","Spades"};

	time_t t;

    srand((unsigned) time(&t)); // Randomize using time

	cout << "\n\t\t*** A deck of cards after " << shuffled << " shuffles ***\n\n";

	fillDeck(deck, face, suit, pix);

	shuffle(deck, shuffled);

	deal(deck);

	printf("\n\n\t");

	WaitKey();

	return 0;

}

void fillDeck(card *wDeck, char *wFace[], char *wSuit[], char *wPix[])

{

	int i;

	for (i = 0; i < 52; i++)

	{

		wDeck[i].face = wFace[i % 13];

		wDeck[i].pix  = wPix[i / 13]; // Added

		wDeck[i].suit = wSuit[i / 13];

	}

}

void shuffle(card *wDeck, int shuffled)

{

	int i, j, x;

	Card temp;

	for (x = 0; x < shuffled ; x++) // A big shuffle

	{

		for (i = 0; i < 52; i++)

		{

			j=rand() % 52;

			temp = wDeck[i];

			wDeck[i] = wDeck[j];

			wDeck[j] = temp;

		}

	}

}

 

void deal(card *wDeck)

{

	int i;

		for (i = 0; i < 51; i++)

		{

			if ( wDeck[i].pix == "\x03"||wDeck[i].pix== "\x04" )

				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);

			else

				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 8);

			printf("    %5s of %-8s (%s) %c", wDeck[i].face, wDeck[i].suit, wDeck[i].pix, (i + 1) % 3 ? '\b' : '\n');

		}

		if ( wDeck[51].pix == "\x03"||wDeck[51].pix== "\x04" )

				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);

			else

				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 8);

	printf("\t\t\t     %5s of %-8s (%s) \n", wDeck[51].face, wDeck[51].suit, wDeck[51].pix);

}

void WaitKey()

{

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 8);

cout << "\t\t   Press ENTER to continue...\n\t\t";

while (_kbhit()) _getch(); // Empty the input buffer

_getch(); // Wait for a key

while (_kbhit()) _getch(); // Empty the input buffer (some keys sends two messages)

}
