#include <iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;
/*
templates:
	class templates:
		a class template's specialization is a type, you can use it as type argument
		you can use a class template's specialization wherever you can use a class name
*/

template<typename T>
class Myclass {

};

template<typename T>
class Nec {

};

// to make it easy readable we will use typedef names:
using namevec = vector<string>;		// namevec is a dynamic array which holds string

int main() {
	// Myclass<int> m;

	Nec<Myclass<int>> mynec;		// note with modern cpp >> does not cause any confusion with left shift operator

	Myclass<Nec<Myclass<int>>> m2;


	Myclass<int> x1;
	Myclass<Myclass<int>> x2;
	Myclass<Myclass<Myclass<int>>> x3;

	cout << "x1: " << typeid(x1).name() << "\nx2: " << typeid(x2).name() << "\nx3: " << typeid(x3).name();


	vector<int> myvec;				// dynamic array of integers
	vector<vector<int>> myvec2;		// dynamic array which has int vectors

	list<vector<int>> mylist;		// linked list which has dynamic array members
	list<list<double>> mylist2;		// linked list which has double list members

	vector<namevec>	myvec3;			// a vector with string vector members
}