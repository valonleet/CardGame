#include <algorithm>

#include "Card.h"
#include "split.h"

using std::string;
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;

/* Constructors */
Card::Card() {
	name = "Blank";
	value = 0;
	rarityValue = common;
}

Card::Card(string name, string type, string set, unsigned short value, rarity rarityValue) {
	this->name = name;
	this->type = type;
	this->set = set;
	this->value = value;
	this->rarityValue = rarityValue;
}

/* non member functions */

// writes a card to text file in the format: "name" "type" "set" value rarityValue
ofstream& operator<<(ofstream& rhs, Card& lfs) {
	rhs << "\"" << lfs.name << "\"" << " " << "\"" << lfs.type << "\"" << " " << "\"" << lfs.set << "\"" << " " << lfs.value << " " << lfs.rarityValue << "\n";
	return rhs;
}

// load a card and return it
Card loadCard(string name) {
	ifstream cardFile;
	string line;
	vector<string> cardElements;
	Card card;

	cardFile.open("cards.txt");

	while (getline(cardFile, line)) {
		cardElements = split(line, ' ');

		if (cardElements[0] == name) {
			card.name = cardElements[0].substr(1, cardElements[0].size() - 1);
			card.type = cardElements[1].substr(1, cardElements[1].size() - 1);
			card.set = cardElements[2].substr(1, cardElements[2].size() - 1);
			card.value = atoi(cardElements[3].c_str());
			card.rarityValue = (rarity) atoi(cardElements[4].c_str());
		}
	}

	return card;
}