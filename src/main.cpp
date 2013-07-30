#include <iostream>
#include <fstream>

#include "Card.h"
#include "Account.h"

int main(void) {
	Card d;
	d.name = "testColl";
	Account a;

	a.username = "testname";
	a.password = "testpass";
	a.collection.push_back(d);
	a.points = 10000;
	a.rating = 10;

	std::ofstream os;

	os.open("accounts.txt");

	os << a;

	os.close();

	loadAccount("testname", "testpass");

	char c;

	std::cin >> c;
	
	return 0;
}