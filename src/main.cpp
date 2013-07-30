#include <iostream>
#include <fstream>

#include "Card.h"
#include "Account.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool loginPrompt(Account&);

bool loginPrompt(Account& a) {
	Account acc;
	string username;
	string password;

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	if (checkLogin(username, password)) {
		a = loadAccount(username);
		cout << "You have logged in" << endl << endl;
		cout << "Welcome " << username << "!" << endl << endl;
		return true;
	}
	else {
		cout << "invalid username or password" << endl << endl;
		return false;
	}
}

int main(void) {
	Account acc;

	// loop until login information is correct
	while (!loginPrompt(acc)) {}

	return 0;
}