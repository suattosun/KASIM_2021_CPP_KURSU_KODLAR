#include <iostream>
/*
cil:
	by constructor initializer list, variables initialized on creation
		but in Nec class, object's nx and ny data members are default inited to indetermined value, and then assigned to 0

	1. if possible init all data members by cil
	2. init data members in cil according to declaration order

	a class's non-static data members are created in order of their declaration order
		init data members in cil according to creation order which is declaration order here
		even if you do not follow creation order in cil it still inits according to creation order

	the most dangerous thing is to forget to init a data member with cil:
		if it is a primitive type, it will have indetermined (garbage) value
		if it is class type it will be default constructed

	note if data members cannot be default inited and if we do not init with cil, it will be syntax error

*/

int g{ 2 };
class Myclass2 {
public:
	// Myclass2() {}			// syntax errror as x, r cannot be default inited
	// Myclass2() : x(10), r(g) {}	// this is ok
private:
	const int x;
	int& r;
};

class Nec {
public:
	Nec() {
		// this is default init + assignment
		nx = 0;
		ny = 0;
	}
private:
	int nx, ny;
};

class Myclass {
public:
	Myclass() : mx(10), my(20) {}
	// Myclass() : mx(0){}				// with this one my will have garbage value
	// Myclass() : my(10), mx(my+2) {}	// this is ub undefined behavior because mx will be inited first
	void print()const {
		std::cout << "mx = " << mx << " my = " << my << "\n";
	}
private:
	int mx, my;
};

int main() {
	Myclass m;
	m.print();

}