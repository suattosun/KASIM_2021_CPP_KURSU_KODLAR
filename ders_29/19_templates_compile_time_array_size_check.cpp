#include <iostream>
#include <cstddef>

using namespace std;

/*
templates:
	lets say, in cpp, we need an array lenght during compile time, and we do not want to use macros
	how can we do that?
*/

// 
template <typename T, std::size_t size>
constexpr std::size_t asize(T(&)[size])
{
	return size;
}



int main() {

	int a[] = { 2, 4, 5, 6, 7 };
	// in c, check array lenght during compile time:
	constexpr auto x = sizeof(a)/sizeof(*a);		// or  sizeof(a)/sizeof(a[0])
	// in c, generally we do it a macro:
	// #define asize(x) sizeof(x)/sizeof(*x)


	int b[20]{};		// T is int and size is 20
	constexpr auto x = asize(b);		// hover about x and see size

}