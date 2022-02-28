#include <iostream>
#include <string>
#include <vector>
#include <list>

/*
templates:
	function templates:
		range:
			STL algorithms are like following Print, they are holding two position parameters which we call iterators
			but how does this Print works?
				*, ++, and != operators are overloaded in vector's and list's iterator class
			so, like list and vector, if any container class have an iterator class member and overloads required operators
				then we can use them like this too
*/


template <typename Iter>
void Print(Iter beg, Iter end) {
	while (beg != end) {
		std::cout << *beg++ << ' ';
	}
	std::cout << "\n";
}

int main() {
	std::vector<int> ivec{ 10, 20, 30, 40, 50 };
	// now using same function template Print() for another object type:
	Print(ivec.begin(), ivec.end());

	std::list<int> ilist{ 10, 20, 30, 40, 50 };
	// now using same function template Print() for another object type:
	Print(ilist.begin(), ilist.end());

}