#include <iostream>
#include <fstream>

#include "Card.h"
#include "Account.h"
#include "split.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;

bool loginPrompt(Account&);
bool checkLogin(string, string);

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

bool checkLogin(string username, string password) {
	ifstream accountFile;
	string line;
	vector<string> lineElements;

	accountFile.open("accounts.txt");

	while (getline(accountFile, line)) {
		lineElements = split(line, ' ');

		if (lineElements[0] == username && lineElements[1] == password) {
			return true;
		}
	}

	return false;
}

int main(void) {
	Account acc;

	// loop until login information is correct
	while (!loginPrompt(acc)) {}

	return 0;
}