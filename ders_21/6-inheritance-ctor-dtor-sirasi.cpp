#include <iostream>

// Constructor ve Destructor'larýn cagrilma sirasi ile ilgili ornek
// Base ctor -> Der ctor -> Der dtor -> Base Dtor
// First in last out
class Base {
public:
	Base()
	{
		std::cout << "Base ctor\n";
	}
	
	~Base()
	{
		std::cout << "Base dtor\n";
	}

};

class Der :public Base {
public:
	Der()
	{
		std::cout << "Der ctor\n";
	}

	~Der()
	{
		std::cout << "Der dtor\n";
	}
};

int main()
{
	Der myder;
}