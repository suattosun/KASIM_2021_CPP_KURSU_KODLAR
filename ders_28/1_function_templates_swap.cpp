#include <iostream>

/*
templates:
	function templates:
		we are not writing functions but providing function templates to the compiler so that the compiler can create any
		functions because functions are generally implementing algorithms and those algorithms are type independent
		To clone the same function code for different types, we provide a template to compiler, and compiler does cloning
		Algorithms are global function templates and they are STL's part
			and in cpp we have function templates in algorithm header, those templates are to do some opeations on data
			structures abstractly
	swap:
		swap is a typical sample
		swap is done by moving not copying, and it is done abstractly
*/

template <typename T>
void Swap(T& x, T& y)
{
	// swap was implemented like folling
	/*
	T temp{x};		// copy semantics is used
	x = y;			// copy assignment will work, x will delete its own resource and copy y's resource
	y = temp;		// same like above
	*/

	// now it is like, now not copying only moving
	// so bug resource copy, or allocation deallocation won't happen
	T temp{ std::move(x) };		// move only change value category of the expression, actual work is done by move ctor
	x = std::move(y);			// move assignment
	y = std::move(temp);

}

int main() {
	int a{ 3 }, b{ 7 };
	Swap(a, b);
	std::cout << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';

	double d1{ 2.12312 }, d2{ 4.3123 };
	Swap(d1, d2);
	std::cout << "d1 = " << d1 << '\n';
	std::cout << "d2 = " << d2 << '\n';

	std::string s1{"muzaffer"}, s2{"ferhunde"};
	Swap(s1, s2);
	std::cout << "s1 = " << s1 << '\n';
	std::cout << "s2 = " << s2 << '\n';

}