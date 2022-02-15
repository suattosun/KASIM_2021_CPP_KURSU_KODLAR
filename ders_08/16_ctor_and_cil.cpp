#include <iostream>
/*
special member functions:
samples:
*/

class Nec {
public:
	// in cil: mx(x), my(y) : mx and my are searched in class scoper first, but x and y are searched in parameters and class scope
	Nec(int x, int y): mx(x), my(y) {
	}
	void print()const
	{
		std::cout << "mx = " << mx << " my = " << my << '\n';
	}
private:
	int mx;
	int my;
};

class Myclass {
public:
	Myclass(int x, int y) : x(x), y(y) {	// will be the same as above but do not use it as it is confusing
	}

	Myclass() : x(x), y(y) {	// this time x is assigned to itself so is y
	}

	void print()const
	{
		std::cout << "x = " << x << " y = " << y << '\n';
	}
private:
	int x;
	int y;
};


int x = 10;
int main() {

	Nec mynec(10,20);
	mynec.print();

	Myclass m(10,20);
	m.print();
	Myclass m2;
	m2.print();

	/*
	int x = x; here the x on the right, first will be searched in the scope initially, and will be found on the left !
	so local x is assigned to it's own value UB (which is indetermined garbage value) not with global x
	*/
	int x = x;		// due to settings: error C4700: uninitialized local variable 'x' used
	// int x = ::x;	// this is fine
	std::cout << "main() x = " << x << '\n';
}

