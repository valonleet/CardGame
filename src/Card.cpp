#include "Card.h"

using std::string;
using std::ofstream;

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
