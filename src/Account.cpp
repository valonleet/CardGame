#include <iostream>

#include "Account.h"
#include "split.h"

using std::ofstream;
using std::vector;
using std::string;
using std::ifstream;
using std::ostream;
using std::endl;

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

	for (vector<string>::size_type i = 0; i < lfs.auctions.size(); i++) {
		rhs << lfs.auctions[i];	// ids don't have spaces so no ""

		if (i != lfs.auctions.size() - 1) {
			rhs << ",";
		}
	}

	rhs << "\n";

	return rhs;
}

ostream& operator<<(ostream& os, Account& acc) {
	os << "Username: " << acc.username << endl << "Points: " << acc.points << endl << "Rating: " << acc.rating << endl << endl;

	for (int i = 0; i < 3; i++) {
		os << "Deck #" << i << endl;
		for (int j = 0; j < 12; j++) {
			os << acc.decks[i][j].name << endl;
		}
		os << endl;
	}

	os << "Collection: " << endl;

	for (vector<Card>::const_iterator iter = acc.collection.begin(); iter != acc.collection.end(); iter++) {
		os << iter->name << endl;
	}

	return os;
}

Account loadAccount(string username) {
	std::ifstream accountFile;
	string line;
	vector<string> lineElements;
	vector<string> cards;
	vector<string> auctionIds;
	Account acc;

	accountFile.open("Accounts.txt");

	while (getline(accountFile, line)) {
		lineElements = split(line, ' ');

		// check if username / password combination exists
		if (lineElements[0] == username) {
			acc.username = lineElements[0];
			acc.points = atoi(lineElements[2].c_str());
			acc.rating = atoi(lineElements[3].c_str());

			// get cards
			split(lineElements[4], ',', cards);		// deck #1
			split(lineElements[5], ',', cards);		// deck #2
			split(lineElements[6], ',', cards);		// deck #3
			split(lineElements[7], ',', cards);		// collection

			// get auctions
			split(lineElements[8], ',', acc.auctions);

			// populate decks
			for (int i = 0; i < 12; i++) {
				acc.decks[0][i] = loadCard(cards[i]);
				acc.decks[1][i] = loadCard(cards[i+12]);
				acc.decks[2][i] = loadCard(cards[i+24]);
			}

			// populate collection
			if (cards.size() >= 36) {
				for (vector<string>::size_type i = 36; i < cards.size(); i++) {
					acc.collection.push_back(loadCard(cards[i]));
				}
			}

			break;

		}
		
	}

	return acc;
}