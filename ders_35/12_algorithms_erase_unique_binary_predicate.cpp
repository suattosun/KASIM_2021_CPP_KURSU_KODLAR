#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"

using namespace std;

/*
STL's removal algorithms:
	unique(begin, end):
		removes same contigous elements, and it does logically
		only contigous ones are removed
		you can first sort and then use unique and then erase to have only unique elements
		you can create a set with container range, as set sorts and will have only one of each key, and then assign back those
			to container wala!
		does like *beg == *nex(beg) which is equal(), less() and they have an overload that you can send a predicate too
	unique(begin, end, predicate):

*/

// lets remove following even and odd numbers and leave only one, so it will be like: even odd even odd even odd etc
int main() {

	vector<int> ivec;
	rfill(ivec, 100, Irand{ 0, 1000 });
	print(ivec);

	// use unique's binary predicate overload
	ivec.erase(unique(ivec.begin(), ivec.end(), [](int a, int b) {return a % 2 == b % 2; }), ivec.end());
	print(ivec);


}