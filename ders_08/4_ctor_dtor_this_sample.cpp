#include <iostream>

/*
	"this" pointer can be used in ctor and dtor just like any other member functions

	in following example, automatic object will be destoryed when its scope ends, meanly before main() ends
		and see how all this pointers show the same address which is same with mynec's address
*/

class Nec {
public:
	Nec()
	{
		std::cout << "Nec default ctor this: " << this << "\n";;
	}
	void bar()
	{
		std::cout << "Nec::bar() this: " << this << "\n";;
	}
	~Nec()
	{
		std::cout << "Nec dtor this: " << this << "\n";;
	}
};

int main() {
	std::cout << "main starts\n";
	{
		Nec mynec;		// automatic lifetime object
		std::cout << "&mynec: " << &mynec << "\n";
		mynec.bar();
	
	}
	std::cout << "main ends\n";
}