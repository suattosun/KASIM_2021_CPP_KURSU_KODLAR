#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
STL's removal algorithms:
	an algorithm cannot add/remove from/to containers, to do this we need containers themselves
		even if you send vector's range to an alghoritm, it's size won't be changed
		you need to call container's member functions to do that, but alghoritms, which are global functions, can't do that
			(but this is not the case that algorithm is called by back_inserter predicate...)
	so how we can have removal alghoritms?
		remove()
		remove_if()
		unique(): removes contigous same elements
	removal alghoritms are doing logical remove: does not remove physically
		removal means it is swapping elements and putting required ones at the beginning and give you the location of logical end,
			but size is still same
			the elements between logic end and end() does not have to be the ones logically removed
		and it returns logic end location, so if you use it with container's begin() you will have a range of iterator
		if you send logical end location with container's end() to erase() function you can remove them physically as well

*/

int main() {

	vector<int> ivec;
	rfill(ivec, 20, Irand{ 0,5 });
	print(ivec);
	int ival;
	cout << "enter value to be erased: ";
	cin >> ival;
	
	auto logic_end = remove(ivec.begin(), ivec.end(), ival); // remove does logical remove by swapping elements
	cout << "size = " << ivec.size() << "\n";
	// print(ivec);
	cout << "number of elements removed logically: " << distance(logic_end, ivec.end()) << '\n';
	cout << "number of elements not removed logically: " << distance(ivec.begin(), logic_end) << '\n';
	print(ivec.begin(), logic_end);


	// now physical erase:
	print(ivec);
	ivec.erase(logic_end, ivec.end());
	print(ivec);
	cout << "size = " << ivec.size() << "\n";


}