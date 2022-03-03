#include <iostream>

using namespace std;

/*
templates:
	explicit specialization:
		another way to print 0..100 without using any loops
*/


// as parent class will be created first, till all the parents are created no ctor will run,
// it will create specialization starting from 100 to 0 but ctors will be called in reverse order
template <int n>
struct Nec : Nec<n - 1>{	// public inheritance
	Nec() {
		cout << n << ' ';
	}

};

template <>
struct Nec<-1> {

};

int main() {

	Nec<10> mynec;

}