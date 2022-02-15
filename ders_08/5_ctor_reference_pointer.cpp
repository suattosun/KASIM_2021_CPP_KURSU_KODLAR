#include <iostream>

class Nec {
public:
	Nec()
	{
		std::cout << "Nec default ctor this: " << this << "\n";;
	}
	void bar()
	{
		std::cout << "Nec::bar() this: " << this << "\n";;
	}
	~Nec()
	{
		std::cout << "Nec dtor this: " << this << "\n";;
	}
};

int main() {

	Nec mynec;		// ctor is called here
	
	/*
	in the following calls no ctor will be called as they are only to hold references or pointer to that object
	it is not object creation
	*/
	Nec& r1 = mynec;
	Nec& r2 = mynec;
	Nec* p1 = &mynec;
}