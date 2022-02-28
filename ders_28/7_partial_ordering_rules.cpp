#include <iostream>
#include <string>

/*
templates:
	function templates and overloading:
		function overloading rules here are called partial ordering rules:
			always the more qualified one will be used, more specific one

*/

/*
try by commenting out all but oneand see that one left will be selected
but if there are more than one, then the more specific one will be choosen
*/
template <typename T>
void func(T)
{
	std::cout << "1\n";
}

template <typename T>
void func(T *)
{
	std::cout << "2\n";
}

template <typename T>
void func(T **)
{
	std::cout << "3\n";
}

int main() {

	int x = 10;
	func(&x);		// T * one will be selected

	int* p = &x;
	int** ptr = &p;
	func(ptr);		// T ** one will be selected

}

