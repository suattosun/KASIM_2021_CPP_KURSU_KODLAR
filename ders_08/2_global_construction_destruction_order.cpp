#include <iostream>

/*

global variables/objects (static lifetime) defined in the same cpp file, are created in order they are defined
	but if you have different global objects in different cpp files creation order is not guaranteed
		this situation is called static initialization problem
	object creation is not related to compile order, so you can compile cpp files in an order but still this does
		not determines object creation order !!!

*/
class Nec {
public:
	Nec()
	{
		std::cout << "Nec default ctor\n";
	}

	~Nec()
	{
		std::cout << "Nec dtor\n";
	}
};

class Data {
public:
	Data()
	{
		std::cout << "Data default ctor\n";
	}

	~Data()
	{
		std::cout << "Data dtor\n";
	}
};

/*
globals have static lifespan and created before main() runs and deleted after main() is finished
	and here gnec will be created before gdata (this is guaranteed)
	object destroying order (dtor calling order) is opposite to the creation order (ctor calling order)
		whichever is created first will be destroyed last
*/
Nec gnec;
Data gdata;

int main() {
	std::cout << "main starts\n";

	std::cout << "main ends\n";
}