#include <iostream>

// inheritance'ta copy ctor ile ilgili ornek
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

};

class Der :public Base {
public:
	Der()
	{
		std::cout << "Der default ctor\n";
	}

	Der(const Der& other) : Base(other)
	{
		std::cout << "Der copy ctor\n";
	}
};


int main()
{
	Der x;
	Der y = x;
}
