#include <iostream>
#include <string>

/*
templates:
	function templates and overloading:
		partial ordering rules:
			what does more specific means?
				lets say we have two templates like following, and send two different types as parameters to like int and char
					void func(T x)		// int
					void func(T *x)		// char
					if you call the second with int parameter, are there any syntax error? YES
					if you call the first with char parameter, are there any syntax error? NO
				that means first one is more general and the second one is more specific					
*/

// try by commenting out one and see that one left will be selected
template <typename T>
void func(T)
{
	std::cout << "1\n";
}

template <typename T>
void func(T (&)[10])
{
	std::cout << "2\n";
}

int main() {
	int a[10]{};
	func(a);
}

