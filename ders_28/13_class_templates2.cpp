#include <iostream>

/*
templates:
	class templates:
		you can use class template name in the class, you do not need to write parameter type name T
		but when you are defining a function out of class you need to use parameter type name
		you can use specialization classes just like your normal classes
	note that you can't use same template head for more than one function or class

*/

template <typename T>
class Nec {
public:
	Nec foo() {			// compiler handles Nex as Nec<T>, you do not have to write Nec<T>
		///
		return *this;
	}
	
	Nec func(Nec);		// it is same with: Nec<T> func(Nec<T>); 

	Nec bar();
};

// you need to write parameter type name here when defining function out of class:
template <typename U>
Nec<U> Nec<U>::bar()
{
	Nec x;
	return x;
}
