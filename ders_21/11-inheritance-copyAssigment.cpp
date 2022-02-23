#include <iostream>

// inheritance'ta copy assigment ctor ile ilgili ornek
class Base {
public:
	Base& operator=(const Base& other)
	{
		std::cout << "base copy assigment\n";
		return *this;
	}
	
};

class Der :public Base {
public:
	Der& operator=(const Der& other)
	{
		std::cout << "der copy assigment\n";
		//operator=(other);//yanlis
		//*this = other; // yanlis ve yukaridaki ile ayni
		Base::operator=(other); 
		//static_cast<Base&> (*this) = other; // Boyle de olur
		//static_cast<Base*>(this)->operator=(other);
		return *this;
	}
	
};


int main()
{
	Der d1, d2;
	d1 = d2;
}