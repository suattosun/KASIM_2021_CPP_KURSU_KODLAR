#include <iostream>

// inheritance'ta move assigment ctor ile ilgili ornek
class Base {
public:

	Base& operator=(Base&& other)
	{
		std::cout << "base move assigment\n";
		return *this;
	}

	Base& operator=(const Base& other)
	{
		std::cout << "base copy assigment\n";
		return *this;
	}

};

class Der :public Base {
public:
	Der& operator=(Der&& other)
	{
		Base::operator=(std::move(other));
		return *this;
	}
	
};


int main()
{
	Der d1, d2;
	//d1 = d2;
	d1 = std::move(d2);
}