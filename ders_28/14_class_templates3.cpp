#include <iostream>

/*
templates:
	class templates:
		you can use specialization classes just like your normal classes
		you can use function templates together with class templates
*/

template <typename T>
class Myclass {
public:
};

// function overloading with class parameters
void gfunc1(Myclass<double>);
void gfunc1(Myclass<int>);
void gfunc1(Myclass<long>);

// before cpp17 ctad, how class template deduction was done?
// by a function template like following:
template <typename T>
Myclass<T> func(T) {

	return Myclass<T>{};
}

int main() {
	Myclass<int> x;
	Myclass<int>* ptr(&x);
	Myclass<int>& r{ x };


	// instead of Myclass<int> x; following was used
	// auto is Myclass<int> here
	auto x = func(12);		// x's type is Myclass<int>
}