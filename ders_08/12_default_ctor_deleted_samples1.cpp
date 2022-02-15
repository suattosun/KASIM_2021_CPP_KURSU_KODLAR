#include <iostream>
/*
special member functions:
default ctor:
	if you do not provide a default ctor, compiler will default it as non-static (ctors cannot be static), public, inline ctor
		compiler's default ctor dafault inits all data members, primitive types to indetermined garbage value,
			others to their defaults, or default ctor will be called for class objects etc
	if compiler cannot default init a special member function due any possible syntax errors, 
		then compiler implicitly deletes it: Myclass() = delete;

default dtor:
	if you do not need to do something special on object destruction, it is perfectly fine if compiler writes it
	if you do not provide a dfault dtor, compiler will default it as non-static, public, inline dtor
		and this dtor does nothing

*/


class A {
	A();		// ctor is private
};

class B {
	A ax;
	/*
	instantiating A is not a syntax error as compiler deletes B's implicitly created default ctor
		why deletes? because B needs to call A's default ctor which is private
	but calling B's deleted default ctor it is syntax error
	*/
};


// Myclass has an implicitly declared and deleted default ctor
class Myclass {
public:

private:
	const int x;
	int& r;
};

int main() {

	A ax;		// syntax error due to access control as A's ctor is private

	B bx;		// syntax error because compiler tries to create an instance with B's default ctor which is deleted!!!

	Myclass mx;	// syntax error as compiler tries to use default ctor but default ctor is deleted by compiler because
				// compiler encounters syntax error while defaulting default ctor (x and r cannot be default inited)
}

