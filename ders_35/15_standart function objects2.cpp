#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"
#include <functional>

using namespace std;

/*
standart function objects:
	those are class templates which can do simple functions when you call with operator() function
	these are going to be used where the algorithm you use needs a predicate

*/


int main() {
	// lets pretend we would like to add elements from vector x and y and put result in z, we can use transform algorithm
	vector<int> x, y, z(10);
	rfill(x, 10, Irand{ 0, 1000 });
	rfill(y, 10, Irand{ 0, 1000 });
	print(x); print(y);

	// as transform requires a binary predicate we can use plus here
	transform(x.begin(), x.end(), y.begin(), z.begin(), plus{});
	// you can use these as well
	//transform(x.begin(), x.end(), y.begin(), z.begin(), minus{});
	//transform(x.begin(), x.end(), y.begin(), z.begin(), multiplies{});

	print(z);

	// and unique() uses equal_to by default, but you can give something else
	vector<int> ivec;
	rfill(ivec, 100, Irand(0, 1000));
	print(ivec);

	// ivec.erase(unique(ivec.begin(), ivec.end()), ivec.end());
	// but you can do something weird like this:
	ivec.erase(unique(ivec.begin(), ivec.end(), greater{}), ivec.end());
	print(ivec);

	// negate sample:
	vector<int> ivec2;
	rfill(ivec2, 100, Irand(-20, +20));
	print(ivec2);
	transform(ivec2.begin(), ivec2.end(), ivec2.begin(), negate{});
	print(ivec2);

	// that is why when we use set, it is using less{} by default
	set<int> myset{10, 20, 30 , 2, 5, 100, 25};
	// this is same with
	//set<int, less<int>> myset{10, 20, 30 , 2, 5, 100, 25};
	print(myset);
	// you can change it to anythig else:
	set<int, greater<int>> myset2{ 10, 20, 30 , 2, 5, 100, 25 };
	print(myset2);


}

