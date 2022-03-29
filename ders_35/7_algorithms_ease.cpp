#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"

using namespace std;

/*
STL's removal algorithms:
	as we keep writing the same code to use remove-erase idiom, they have added algorithms in cpp20 to do this easier:
	erase(container, ival): in cpp20 this one does remove-erase idiom
		returns the number of elements removed
	erase_if(container, lambda): in cpp20 this one does remove-erase idiom with a predicate
*/

int main() {

	vector<int> ivec;
	rfill(ivec, 20, Irand{ 0,5 });
	print(ivec);
	cout << "size = " << ivec.size() << "\n";
	int ival;
	cout << "enter value to be erased: ";
	cin >> ival;
	
	// same sample in 3_algorithms_remove_erase_idiom
	// if we aim to physically remove, here is an easy one line way.
	// remove-erase idiom:
	// ivec.erase(remove(ivec.begin(), ivec.end(), ival), ivec.end());
	// now we have easiest way in cpp20:
	auto n = erase(ivec, ival);
	cout << "removed elements count = " << n << "\n";
	cout << "size = " << ivec.size() << "\n";
	print(ivec);

}