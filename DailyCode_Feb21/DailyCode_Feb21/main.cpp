#include <iostream>
#include <string>

using namespace std;

int main() {

	char input;

	cout << "Hello! What cookie do you want? chocolate chip (c), macadamia/white chocolate (m), peanut butter (p), Cthulhu (C)" << endl;
	cin >> input;

	switch (input) {

	case 'c':
		cout << "Here is your chocolate chip cookie." << endl;
		break;
	case 'm':
		cout << "You have great taste. I will spare you." << endl;
		break;
	case 'p':
		cout << "Interesting choice." << endl;
		break;
	case 'C':
		cout << "Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn!" << endl;
		break;
	default:
		cout << "INVALID DATA" << endl;
	}
}