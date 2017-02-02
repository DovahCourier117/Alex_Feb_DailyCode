#include<iostream>

using namespace std;

int main() {

	char input;

	cout << "Do you want to hear some song lyrics? Y or N." << endl;
	cin >> input;

	if (input == 'y') {
		cout << "NEVER GONNA GIVE YOU UP, NEVER GONNA LET YOU DOWN..." << endl;
	}

	else if (input == 'n') {
		cout << "WHO CARES ABOUT WHAT YOU WANT?!" << endl;
		cout << "NEVER GONNA GIVE YOU UP, NEVER GONNA LET YOU DOWN..." << endl;
	}

	else {
		cout << "IT WAS A SIMPLE EFFING QUESTION! WHAT IS WRONG WITH YOU?!" << endl;
	}

}