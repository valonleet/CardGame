#ifndef GUARD_AUCTIONHOUSE_H
#define GUARD_AUCTIONHOUSE_H

#include <string>

struct Auction {
	std::string id;
	std::string cardName;	
	std::string actioneer;
	unsigned int bid;
	unsigned int buyout;
	// need to add some sort of time
};

// add writing/reading auctions

#endif