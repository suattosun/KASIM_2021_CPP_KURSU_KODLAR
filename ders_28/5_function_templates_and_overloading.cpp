#include <iostream>

/*
templates:
	function templates and overloading:
		function templates are included in function overload set together with other function templates and real functions
		if there is a real function with the same selectaability with function template, real function will be called
			no ambiguity in this situation, rule is clear

*/

template <typename T>
void func(T)
{
	std::cout << "function template type T is: " << typeid(T).name() << '\n';
}

void func(double) {
	std::cout << "func(double)\n";
}

// if there is a real int function, then real function is selected over function template
void func(int) {
	std::cout << "func(int)\n";
}

int main() {
	func(10);
	func('A'); // function template is called
}