#include <iostream>

/*

constructor and destructor:
	are class's special member function
	must be non-static and non-const
	name must be same with class name, dtor has a leading ~
	no return value consept
	can be public, private, protected
	can be defined inline or in a cpp file

constructor:
	it is used to create an object from a class
	can be overloaded, a class can have multiple constructors
	cannot be called by it's name
	default ctor:
		is a ctor which does not have any parameters or all parameters are default initialized
	does not have to be public, but when private client codes cannot instantiate object due to access control
	RAII resource acquisition is initialization idiom is completely related to constructors

destructor:
	it is used to destruct an object
	cannot be overloaded, must be with no-parameters
	unlike ctor, can be called with it's name, but do not use it, will be used for some very specific case

*/

class Myclass {
public:
	Myclass();		// default ctor
	~Myclass();		// dtor
};


class Nec {
public:
	Nec()
	{
		std::cout << "Nec default ctor\n";
	}

	~Nec()
	{
		std::cout << "Nec dtor\n";
	}
};


int main() {
	std::cout << "main starts\n";

	Nec mynec;

	std::cout << "main ends\n";
}