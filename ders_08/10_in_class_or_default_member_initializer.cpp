#include <iostream>
/*
in-class initializer: default member initializer (comes with modern cpp)
	it means if data member is not inited anywhere in any ctors (user declared or compiler declared)
		then it will be inited with default initializer
			note that defaulted ctors will init to this value too
	if ctor inits data member, it will be ctor's value
	it is very useful when several ctors which inits to same value, use in-class initialization
	still any ctor can init it as well

*/

class Myclass {
public:
	// Myclass()
	// Myclass(): mx(99)
	// Myclass() : mz(5)
	Myclass() : mx(1), my(2), mz(3)
	{
	}
	void print() const
	{
		std::cout << "mx = " << mx << " my = "<< my << " mz = " << mz << '\n';
	}
private:
	// in-class initializer (default member initializer)
	int mx = 10;
	int my{ 20 }, mz;
	// int mz(10);		// syntax error
};

int main() {
	Myclass m;
	m.print();

}