#ifndef GUARD_ACCOUNT_H
#define GUARD_ACCOUNT_H

#include <string>
#include <vector>
#include <fstream>
#include "Card.h"

struct Account {
	Account();

	std::string username;				// username
	std::string password;				// password
	unsigned int points;				// points for buying stuff
	int rating;							// elo type rating thingy
	Card decks[3][12];					// 3 decks for playing
	std::vector<Card> collection;		// card collection
	std::vector<std::string> auctions;	// active auctions by id
};

// write Account to file
std::ofstream& operator<<(std::ofstream&, Account&);

// print account to ostream
std::ostream& operator<<(std::ostream&, Account&);

// load an account
Account loadAccount(std::string);

#endif