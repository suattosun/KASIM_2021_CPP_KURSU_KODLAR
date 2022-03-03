#include <iostream>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
		meta programming sample using compile time recursivity

		this sample is about how this compile time recursivity was done before cpp11, modern cpp
			using class templates like following

*/

template <int n>
struct Factorial {
	static const int value = n > 1 ? n * Factorial<n - 1>::value : 1;

};

// class's explicit specialization is same with functions
template <>
struct Factorial<0>
{
	static const int value = 1;
};

int main()
{
	int a[Factorial<7>::value] = {0};	// see a is an array of 5040 lenght

}