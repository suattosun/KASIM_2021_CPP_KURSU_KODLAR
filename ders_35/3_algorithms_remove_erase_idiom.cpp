#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
STL's removal algorithms:
	remove-erase idiom: remove those elements physically
*/

int main() {

	vector<int> ivec;
	rfill(ivec, 20, Irand{ 0,5 });
	print(ivec);
	cout << "size = " << ivec.size() << "\n";
	int ival;
	cout << "enter value to be erased: ";
	cin >> ival;

	// if we aim to physically remove, here is an easy one line way.
	// remove-erase idiom:
	ivec.erase(remove(ivec.begin(), ivec.end(), ival), ivec.end());
	print(ivec);
	cout << "size = " << ivec.size() << "\n";

}