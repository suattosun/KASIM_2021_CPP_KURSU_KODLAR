#include <iostream>
#include<utility>

/*
templates:
	class templates:
		pair: cpp17
			we can use pair template since cpp17
*/
using namespace std;
int main() {

	pair p1{ 12, 4.5 };		// std::pair<int,double>	cpp17
	pair<int, double> p2{ 12, 4.5 };
	auto p3 = make_pair(12, 4.5);

}