#include <iostream>

int x = 10;
class Base {
public:
	void foo(int, int);
	int x;

};

class Der : public Base {
public:
	void foo(double);
	int x = 10;
	void func()
	{
		int x = 10;

		std::cout << x; //local x
		std::cout << this->x; //Der::x
		std::cout << Der::x;//Der::x
		std::cout << Base::x; // Base::x
		std::cout << ::x; // x in namespace scope
	}
};

int main()
{
	Der myder;
	myder.Base::foo(1, 3); // Bu durumda Base'in foo'suna ulasmak icin :: kullanilabilir.
	myder.foo(1.2);
}