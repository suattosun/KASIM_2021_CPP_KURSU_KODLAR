#include <iostream>
/*
special member functions:
	copy ctor:
		in following sample compile and see dtor is called twice, why?
		once foo function is called, as it is called by object x, foo's parameter m will be constructed by x using a special 
			constructor called copy constructor
		as we did notprovide any copy ctor, compiler wrote it, and as m's life ends once foo ends, dtor is called for m
*/

class Myclass {
public:
	Myclass()
	{
		std::cout << "Myclass default ctor: " << this << '\n';
	}

	~Myclass()
	{
		std::cout << "Myclass dtor: " << this << '\n';
	}

};

void foo(Myclass m)
{
	std::cout << "foo() is called &m: " << &m << '\n';
}

int main() {
	Myclass x;
	std::cout << "main() &x: " << &x << '\n';
	foo(x);
	(void)getchar();
}