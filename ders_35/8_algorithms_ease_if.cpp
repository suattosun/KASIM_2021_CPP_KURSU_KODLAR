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
	
	// remove even numbers:
	auto n = erase_if(ivec, [](int x) {return x % 2 == 0; });
	cout << "removed elements count = " << n << "\n";
	cout << "size = " << ivec.size() << "\n";
	print(ivec);

}