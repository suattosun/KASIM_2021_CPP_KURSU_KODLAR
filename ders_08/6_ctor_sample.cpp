#include <iostream>

/*
a sample:
	write 1 to 100 to the screen but do not use any loops
*/

class Nec {
public:
	Nec()
	{
		static int x = 0;
		std::cout << ++x << " ";
	}
};

int main() {

	Nec mynec[100];
}