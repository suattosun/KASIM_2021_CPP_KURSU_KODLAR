#include <iostream>
/*
special member functions:
default ctor:
	if compiler cannot default init a special member function due any possible syntax errors,
		then compiler implicitly deletes it: Myclass() = delete;
*/

/*
here even if int parameter ctor is public, class A does not have a default ctor as you have defined a ctor, compiler does not
define the default ctor
*/
class A {
public:
	A(int);
};
class B {
	B bx;	// not a syntax error as compiler default deletes B's default ctor because A does not have a default ctor
};

int main() {
	B bx;		// this is syntax error because compiler tries to create an instance with B's default ctor which is deleted!!!
}

