#include <iostream>
/*
special member functions:
default ctor:
	if compiler cannot default init a special member function due any possible syntax errors,
		then compiler implicitly deletes it: Myclass() = delete;

	another sample:
*/


class A {
public:
	A(int);
};
class B {
public:
	B() = default;	// order compiler to write default ctor, compiler tries to default default ctor but deletes as
					// A does not have a default ctor
private:
	A ax;
};

int main() {
	B bx;		// syntax error as B does not have a default ctor
}

