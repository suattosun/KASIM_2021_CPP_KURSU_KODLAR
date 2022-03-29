#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
STL's removal algorithms:
	remove-erase idiom has been used widely till cpp20 but then:
	remove_if() gets a predicate to remove and returns a logical_end
*/

int main() {

	vector<int> ivec;
	rfill(ivec, 100, Irand{ 0, 1000 });
	print(ivec);
	cout << "size = " << ivec.size() << "\n";
	int ival;
	cout << "which number dividers shall be removed? : ";
	cin >> ival;

	ivec.erase(remove_if(ivec.begin(), ivec.end(), [ival](int x) {return x % ival == 0; }), ivec.end());
	print(ivec);
	cout << "size = " << ivec.size() << "\n";

}