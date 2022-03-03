#include <iostream>

using namespace std;

/*
templates:
	partial specialization:
		a partial specialization does not have to have the same number of parameters as primary template
			but it has to have same number of template arguments
		following is a good example:
*/

template <typename T>
struct Nec {
	Nec() {
		cout << "Nec primary template \n";
	}
};
template <typename T, typename U>
struct Nec<std::pair<T,U>> {
	Nec() {
		cout << "Nec partial specialization Nec<std::pair<T,U>> \n";
	}
};


template <typename T, typename U>
class Myclass {
public:
	Myclass() {
		cout << "Myclass primary template \n";
	}
};
template <typename T>
// class Myclass<T, int> { // and even there can be something like this, try this too
// class Myclass<T, T*> { // and even there can be something like this, try this and see result :D
class Myclass<T,T> {
public:
	Myclass() {
		cout << "Myclass partial specialization Myclass<T, T> \n";
	}
};

int main() {

	Nec<int> x;
	Nec<std::pair<int, double>> y;
	Nec<std::pair<char, float*>> z;

	Myclass<int, double> m1;
	Myclass<int, int> m2;
	Myclass<char, char> m3;
	Myclass<int*, int*> m4;
	Myclass<int, int*> m5;
	Myclass<int*, int**> m6;

}