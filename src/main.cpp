#include <iostream>
#include <fstream>

#include "Card.h"
#include "Account.h"

using std::cout;

int main(void) {
	Account test;

	test = loadAccount("testname", "testpass");

	cout << test;
	
	return 0;
}