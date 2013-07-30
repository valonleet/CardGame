#ifndef GUARD_CARD_H
#define GUARD_CARD_H

#include <string>
#include <fstream>

/* rarity of the card */
enum rarity {
	common,
	rare,
	slam
};

struct Card {
	Card();
	Card(std::string, std::string, std::string, unsigned short, rarity);

	std::string name;		// name
	std::string type;		// building, person, etc
	std::string set;		// ppg, sj, whatever
	unsigned short value;	// point value
	rarity rarityValue;		// how rare the card is
};

// write Card
std::ofstream& operator<<(std::ofstream&, Card&);

// load card
Card loadCard(std::string);

#endif