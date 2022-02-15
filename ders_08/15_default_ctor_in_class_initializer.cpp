#include <iostream>
/*
special member functions:
default ctor:
	in-clas initializer is important here:
		when you create an object, compiler's created default ctor inits to those cil values on creation.
			if you do not init them specifically, it will be init to cil values for user provided ctors too
*/

class Nec {
public:
	void print() const
	{
		std::cout << "mx = " << mx << " my = " << my << '\n';
	}
private:
	// in-class initializer (default member initializer)
	int mx = 10;
	int my = 20;
	// if you do not provide a ctor, compiler writes this default ctor: Nec() :  mx(10), my(20){}
};

int main() {
	Nec mynec;
	mynec.print();
}