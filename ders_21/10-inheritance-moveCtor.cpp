#include <iostream>

// inheritance'ta move ctor ile ilgili ornek
class Base {
public:
	Base()
	{
		std::cout << "Base default ctor\n";
	}

	Base(const Base&)
	{
		std::cout << "Base copy ctor\n";
	}
	Base(const Base&&)
	{
		std::cout << "Base move ctor\n";
	}
};

class Der :public Base {
public:
	Der() = default;
	Der(Der&& other): Base(std::move(other))
	{

	}
};


int main()
{
	Der x;
	Der y = std::move(x);
}