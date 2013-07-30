#include "Account.h"

using std::ofstream;
using std::vector;

/* Constructors */
Account::Account() {
	// blank card to fill decks
	Card c;

	// fill decks
	for (int rows = 0; rows < 3; rows++) {
		for (int cols = 0; cols < 12; cols++) {
			decks[rows][cols] = c;
		}
	}

	points = 0;
	rating = 0;
}

/* Non member functions */

// write account to file
ofstream& operator<<(ofstream& rhs, Account& lfs) {
	// general account info
	rhs << lfs.username << " " << lfs.password << " " << lfs.points << " " << lfs.rating;

	// write decks "Deck1Card1","Deck1Card1","Deck1Card3"... <space> "Deck2Card1","Deck2Card2","Deck2Card3"...
	for (int rows = 0; rows < 3; rows++) {
		// space between decks
		rhs << " ";
		for (int cols = 0; cols < 12; cols++) {
			rhs << "\"" << lfs.decks[rows][cols].name << "\"";

			if (cols != 11) {
				rhs << ",";
			}
		}
	}

	rhs << " ";

	// write collection "Card1","Card2","Card3"...
	for (vector<Card>::size_type i = 0; i < lfs.collection.size(); i++) {
		rhs << "\"" << lfs.collection[i].name << "\"";
		if (i != lfs.collection.size() - 1) {
			rhs << ",";
		}
	}

	rhs << "\n";

	return rhs;
}