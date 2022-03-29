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
	less():
		less(12,13);
	plus():
		plus(30,45);
	these are useful when used as predicates in algorithms like sort() which uses less{} by default
		you do not need to use lambdas for such things
			greater<int>{}
			greater{}		// transparent function object, type deduction is done in modern cpp
		unique() uses equal_to{} by default
*/

// if we do not have standart function objects we would do them like this:
template <typename T>
struct Less {
	bool operator()(const T& x, const T& y) {
		return x < y;
	}
};

int main() {

	Less<int> fless;
	fless(4, 6);			// we can have a call like this and compiler, if it can see Less's type above turn this to 4 < 6

	int x{ 40 }, y{ 46 };
	Less<int>{}(x, y);		// creating a temporary object of Less and calling its operator() function with x, y values

	// so in functional header file, there are similar function objects:
	cout << plus<int>{}(124, 56) << '\n';

	vector<int> ivec;
	rfill(ivec, 100, Irand{ 1, 1000 });

	/*uncomment following one by one and see results*/
	// sort algorithm uses less by default:
	// sort(ivec.begin(), ivec.end());
	// but you can change it:
	// sort(ivec.begin(), ivec.end(), greater<int>{});
	// and you do not even need to specify type, it is done by type deduction:
	sort(ivec.begin(), ivec.end(), greater{});		// transparent function object
	// if we do not have this greater we would do it by a lambda like this:
	// sort(ivec.begin(), ivec.end(), [](int a, int b) {return b < a; });

	print(ivec);

}