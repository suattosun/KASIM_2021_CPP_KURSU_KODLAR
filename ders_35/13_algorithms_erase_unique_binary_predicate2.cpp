#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"

using namespace std;

/*
STL's removal algorithms:
	a question to remove white spaces and leave only one white space between words

*/

int main() {
	string str{ "kaan    ali    veli    saadet  hakan  irma   aysenur  selim    necati   " };
	
	cout << "|" << str << "|" << '\n';
	str.erase(unique(str.begin(), str.end(), [](const char c1, const char c2) {return isspace(c1) && isspace(c2); }), str.end());
	cout << "|" << str << "|" << '\n';

}