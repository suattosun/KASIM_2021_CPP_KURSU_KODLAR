#include <iostream>

/*
runtime polymorphism: virtual dispatch mechanism: if a base virtual function is called with
base class's POINTER or REFERENCE, the function of the object (held by the pointer or
reference at that point) will be called
with virtual dispatch mechanism which function call will be done is specified during runtime
*/

using namespace std;
class Car {
public:
	virtual void run() {
		cout << "Car is running \n";
	}
};

class Skoda : public Car {
	virtual void run()override {	// using virtual keyword when overriding does change NOTHING, it is already virtual
		cout << "Skoda is running \n";
	}
};

class Bmw : public Car {
	virtual void run()override {
		cout << "Bmw is running \n";
	}
};

int main() {

	cout << "---------call by pointer-----------\n";
	Car* ptr;
	ptr = new Skoda;
	ptr->run();

	ptr = new Bmw;
	ptr->run();
	cout << "-----call by reference is same-----\n";
	Bmw mybmw;
	Car& r = mybmw;
	r.run();

	// note that virtual dispatch mechanism does not work with object slicing
	// (object loses added functionalities)
	cout << "---------- object slicing---------\n";
	Bmw bmw;
	Car mycar;
	mycar = bmw;	// object slicing: derived class's object is assigned to base class's object!!! DO NOT DO THIS
	mycar.run();	// here Car's run() will be called 
}
