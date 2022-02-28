#include <iostream>

/*
templates:
	function templates:
		decltype(auto):

	a function template's return can be:
		1. a template parameter type
		2. traling return type
		3. auto
		4. decltype(auto)
					
*/

template <typename T>
auto func(T& x)
{
	return x;
}


template <typename T>
decltype(auto) foo(T& x)
{
	return x;
}


template <typename T>
decltype(auto) foo2(T x)
{
	// return x;		// int
	return (x);		// int& to an automatic object, UB
}

int main() {
	int ival{};
	int r = func(ival);		// x is int& but with auto & drops
	int& r = foo(ival);		// decltype & does not drop

	int& r2= foo2(ival);
}