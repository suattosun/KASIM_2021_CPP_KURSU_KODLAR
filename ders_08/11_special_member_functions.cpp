#include <iostream>
/*
special member functions:
	implicitly declared:
		if user does not declare those functions, they are implicitly declared/created by compiler (defaulted)
		those are: default ctor, copy ctor, move ctor, dtor, copy assignment, move assignment (move ones since cpp11)
			so: class Myclass{}; has 6 special member function already even if you don't define any
		if you define any ctors, compiler does not provide you a default ctor
	user declared types:
		1. Myclass(){}		// user declared defined
		2. default functions (cpp11): order compiler to default that default ctor. it means compiler will write its code
			Myclass() = default;	ordering compiler to write it (default can only be used for special member functions)
		3. delete functions: void func(int) = delete;
			(delete is overloaded: do not mix it with deleting a dynamic object "delete p;" which is created by new)
			Myclass() = delete;		it can be used for any functions, and means function exist but calling it is syntax error
			a global function, class member function or special member function can be deleted
			they are used in function overloading

*/

void func(int) = delete;

class Myclass {
public:
	Myclass() = default;
	Myclass(int) = delete;		// you cannot create objects with this ctor
	Myclass(int, int);
};

int main() {
	func();				// syntax error as deleted
	Myclass m1;
	Myclass m2(12);		// syntax error as deleted
	Myclass m3(12, 13);
}