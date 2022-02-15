#include <iostream>
/*
special member functions:
	copy ctor: cc
		if an object is created by obtaining another object's value (which is an instance of the same class),
			in that case, copy ctor is called
		cc call scenarios:
			if a class object is created by another one:
			call by value function calls:
				if call by value class type function calls
				if return value is class type
*/

class Myclass {

};

void func(Myclass x) {}
Myclass foo();		// cc is called for foo's return statement

int main() {

	Myclass m1;
	// cc call scenarios: if a class object is created by another one:
	Myclass m2 = m1;	// cc is called for m2
	Myclass m3(m1);		// cc is called for m3
	Myclass m4{ m1 };	// cc is called for m4
	auto m5 = m1;		// cc is called for m5
	auto m6(m1);		// cc is called for m6
	auto m7{ m1 };		// cc is called for m7

	// cc call scenarios: call by value function calls:
	func(m1);			// cc is called for parameter x

}