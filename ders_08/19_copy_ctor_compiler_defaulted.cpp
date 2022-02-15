#include <iostream>
/*
special member functions:
	copy ctor:
		compiler defaulted cc:
			compiler will provide a non-static, public, inline cc
			implicitly declared and must be like Myclass(const Myclass &r), does memberwise copy (shallow copy)
			default cc will copy all elements in the order you have provided (value semantics),
				if that is what you want then do not write a cc
	note Myclass(const Myclass &other) can be called with both R and L value expression
		but Myclass(Myclass &other) can only be called by L value expression

	note that you will need to use cc very rarely, compiler defaulted cc will do what you need
*/
/*
class Myclass {
public:

	// cc will be called for tx, ux, and mx as well if they are other class types
	Myclass(const Myclass &other) : tx(other.tx), ux(other.ux), mx(other.mx)
	{
	}

private:
	T tx;
	U ux;
	M mx;
};
*/

class Date {
public:
	Date(int day, int mon, int year) : mday(day), mmon(mon), myear(year) {}

	void print()const
	{
		std::cout << "day: " << mday << " month: " << mmon << " year: " << myear << '\n';
	}
private:
	int mday, mmon, myear;
};
int main() {

	Date dx{ 12,5,1975 };
	dx.print();

	Date dy = dx;
	dy.print();
}