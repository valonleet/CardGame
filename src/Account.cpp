#include "Account.h"
#include "split.h"
#include <iostream>

using std::ofstream;
using std::vector;
using std::string;
using std::ifstream;

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

Account loadAccount(string username, string password) {
	std::ifstream accountFile;
	string line;
	vector<string> lineElements;
	vector<string> cards;
	Account acc;

	accountFile.open("Accounts.txt");

	while (getline(accountFile, line)) {
		lineElements = split(line, ' ');
		for (vector<string>::size_type i = 0; i != lineElements.size(); i++) {
			std::cout << lineElements[i] << std::endl;
		}
		// check if username / password combination exists
		if (lineElements[0] == username && lineElements[1] == password) {
			acc.username = lineElements[0];
			acc.points = atoi(lineElements[2].c_str());
			acc.rating = atoi(lineElements[3].c_str());

			// get cards
			split(lineElements[4], ',', cards);
			split(lineElements[5], ',', cards);
			split(lineElements[6], ',', cards);
			split(lineElements[7], ',', cards);

			// populate decks
			for (int i = 0; i < 12; i++) {
				acc.decks[0][i] = loadCard(cards[i].substr(1, cards[i].size() - 1));
				acc.decks[1][i] = loadCard(cards[i+12].substr(1, cards[i+12].size() - 1));
				acc.decks[2][i] = loadCard(cards[i+24].substr(1, cards[i+24].size() - 1));
			}

			// populate collection
			if (cards.size() >= 36) {
				for (vector<string>::size_type i = 36; i < cards.size(); i++) {
					acc.collection.push_back(loadCard(cards[i].substr(1, cards[i].size() - 1)));
				}
			}

		}
		
	}

	return acc;
}