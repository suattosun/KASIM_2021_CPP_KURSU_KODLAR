#include <iostream>

// Multilevel inheritance Constructor ve Destructor'larýn cagrilma sirasi ile ilgili ornek
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
class Nec: public Der{
public:
	Nec()
	{
		std::cout << "Nec ctor\n";
	}

	~Nec()
	{
		std::cout << "Nec dtor\n";
	}

};

int main()
{
	Nec mynec;
}
