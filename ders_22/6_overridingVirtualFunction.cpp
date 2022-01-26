#include <iostream>

// overriding a virtual function: (override is both a noun and a verb)

using namespace std;

class Base {
public:
	virtual void func(int, int) {		// note that virtual keyword can only be used in declaration
		cout << "Base func(int, int)\n";
	}
	virtual void foo(int) {
		cout << "Base foo(int)\n";
	}
};

class Der : public Base {
public:
	void func(int, int) { //  override of the Base's virtual function : signature and return type must be identical
		cout << "Der func(int, int)";
	}
	int func(int);		// valid but this is completely a different function
	int foo(int, int);	// syntax error as you cannot define a function has the same signature ...
						// but different return type than base class's virtual function
};