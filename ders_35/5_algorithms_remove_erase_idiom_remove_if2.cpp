#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
STL's removal algorithms:
	remove-erase idiom
*/

int main() {

	vector<string> svec;
	rfill(svec, 100, rname);
	print(svec);
	char c;
	cout << "which letter containing names shall be removed? : ";
	cin >> c;

	// we can name lambda and make it more readable
	// svec.erase(remove_if(svec.begin(), svec.end(), [c](const string& s) {return s.find(c) != string::npos; }), svec.end());
	auto f = [c](const string& s) {return s.find(c) != string::npos; };
	svec.erase(remove_if(svec.begin(), svec.end(), f), svec.end());
	print(svec);

}