#include <iostream>

/*
templates:
	function templates and overloading:
		how can you have a real function and it can only be called by exact parameter?
			create a function template to be selected in all other calls, and delete it

*/

template <typename T>
void func(T x) = delete;

// you can shorten it in cpp20:
// void func(auto x) = delete;

void func(int)
{
	std::cout << "func(int) is called \n";
}

int main() {

	func(10);
	func(1.2);
	func('A');

}