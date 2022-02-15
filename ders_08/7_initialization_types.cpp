#include <iostream>

/*
the structure that creates object is called object initializing

initialization types:
	default init:
		int x; automatic primitive types will have indetermined value (garbage value)
		static int y; static objects are zero inited first
			which means: aritmetic types to 0, pointer types to NULL, and boolean types false inited
		Myclass m; default init, default ctor will be called
		top level const variables cannot be default inited
		references cannot be default inited
	value init:
		Nec n1{}; value init, default ctor will be called
		Nec n2(); is not dafault init it is a function call
			// warning C4930: 'Nec m(void)': prototyped function not called (was a variable definition intended?)
	ctor Nec(int x){}; can be called three different ways:
		direct initialization: Nec n3(10);
		copy initialization: Nec n4 = 7;
		direct list initialization or uniform initialization: Nec n5{5};
			narrowing conversion is syntax error, so calling with like 7.6 is syntax error
	note:
		uniform initialization or brace initialization: initing by using {}
*/

class Nec {
public:
	Nec() {
		std::cout << "Nec default ctor\n";
	}
	Nec(int x) {
		std::cout << "Nec(int) ctor x = " << x << "\n";
	}
};

int main() {

// default init:

	// followings are default inited to
	int x;			// default init, indetermined value
	static int y;	// default init, zero inited
	Nec mynec;		// default init, default ctor will be called

	// syntax errors:(uncomment out see errors)
	//int& r;			// references cannot be default inited
	//const int cx;	// top level const variables cannot be default inited
	//int* const p;	// top level const variables cannot be default inited

// value init:
	Nec n1{};	// value init, default ctor will be called
	Nec n2();		// no ctor is called bc this is a function call
					// rule: if an instantiation means two things function call is selected, compiler gives waring.
	Nec n22(int a);	// this is a function call too

// ctor Nec(int x){} can be called in threee different ways:
	Nec n3(10);		// direct initialization: Nec(int) will be called
					// note this is not a function call as there is a value in ()
	Nec n6(3.2);	// direct initialization with data loss: Nec(int) will be called
	Nec n4 = 7;		// copy initialization
	Nec n4 = 7.6;	// copy initialization, data loss
	Nec n5{ 5 };	// direct list initialization or uniform initialization
	Nec n5{ 5,6 };	// direct list initialization, narrowing conversion is syntax error syntax error

}