#include <iostream>


class Base {
public:
	Base(int)
	{
		std::cout << "Base(int) ctor\n";
	}
	~Base()
	{
		std::cout << "Base destructor\n";
	}
};

class Der :public Base {

};

int main()
{
	Der myder; // Sentaks hatasi cunku Der'in default ctor'u delete edildi.

}
