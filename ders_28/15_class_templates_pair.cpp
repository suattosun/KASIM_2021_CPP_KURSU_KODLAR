#include <iostream>
#include<utility>

/*
templates:
	class templates:
		pair:
			pair is a class template, uses a struct to hold two objects from different types
			generally used when a function needs to return two values
*/

// pair is like this:
template <typename T, typename U>
struct Pair {
	// simplified ctor:
	Pair() : first{}, second{}{}		// both are value inited, so if they are primitive types init to 0
										// but if they are class types, value init meants calling default ctor
	
	Pair(const T& t, const U& u) : first(t), second(u) {}		// anothe ctor
	T first;
	U second;
};

/*
this is a utility function which are called factory functions used to create pairs
previously there was not template argument deduction, so function template like following were used to do the same
*/
template<typename T, typename U>
Pair<T, U> MakePair(const T& t, const U& u)
{
	return Pair<T, U>{t, u};
}

/*
how to compare two pair objects : if first is big, it is big, else check second
	note in cpp20 we have spaceshift operator to do this
following is a good example for using both class and function templates together
amd with this function code, we can compare infinite numbers of Pair objects
*/
template<typename T, typename U>
bool operator<(const Pair<T, U>& lhs, const Pair<T, U>& rhs)
{
	// notice here only < is used specifically, = is not used
	return lhs.first < rhs.first || !(rhs.first < lhs.first) && lhs.second < rhs.second;
}

int main() {
	using namespace std;
	pair<int, double> px;
	pair<int, double> idp{ 12, 3.4 };

	Pair<int, double> px2;


	auto x = MakePair( 12, 4.5 );
}