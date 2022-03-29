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

int main() {

	vector<int> ivec;
	rfill(ivec, 50, Irand{ 0,2 });
	cout << "size = " << ivec.size() << "\n";
	print(ivec);

	// remove same contigous elements 
	ivec.erase(unique(ivec.begin(), ivec.end()), ivec.end());
	cout << "size = " << ivec.size() << "\n";
	print(ivec);

}