#include <iostream>

using namespace std;
/*
templates:
	class templates:
		member template:
			compiler will write function with any parameter for any of the Myclass<T> class parameter
			they will be written when they are used
*/

template<typename T>
class Myclass {
public:
	template<typename U>
	foo(Myclass<U> m);
};

int main() {

	Myclass<double> dm;
	Myclass<int> x;
	Myclass<double> y;
	Myclass<float> z;

	dm.foo(x);
	dm.foo(y);
	dm.foo(z);

	// here is another sample
	pair<double, double> dp{ 3.4, 5.6 };
	pair<int, int> ip{ 3, 8 };
	dp = ip;		// is not syntax error as pair's copy ctor is a member template like below:

}

template<typename T, typename U>
class Pair {
public:
	
	// pair's member copy ctor is a member template like this:
	template<typename X, typename W>
	Pair(const Pair<X, W> other) : first{ other.first }, second{ other.second }{
	}

private:
	T first;
	U second;
};