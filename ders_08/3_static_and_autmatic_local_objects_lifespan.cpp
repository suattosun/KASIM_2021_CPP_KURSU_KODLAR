#include <iostream>

/*
static local variables/objects:
	to create them, the function they are in must be called
		for the first function call variable/object is created (by calling ctor)
		for later function calls, object remains and no new one is created
	once object is created it remains until the program ends

automatic local variables/objects:
	they are created each time the function is called, and destroyed when function ends
*/

class Myclass {
public:
	Myclass()
	{
		std::cout << "Myclass default ctor\n";
	}

	~Myclass()
	{
		std::cout << "Myclass dtor\n";
	}
};

void func() {
	static int count = 0;
	std::cout << "func() is called " << ++count <<" times\n";
	// try compiling first with static and then automatic one:
	static Myclass m;	// static local object
	// Myclass m;		// automatic local object
}
int main() {
	std::cout << "main starts\n";

	func();
	func();
	func();
	func();
	func();

	std::cout << "main ends\n";
}