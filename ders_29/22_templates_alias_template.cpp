#include <iostream>

using namespace std;

/*
templates:
	alias template: cpp11
		using is not added to only increase readabilty, it is added becasue c's typedef won't be used for templates
			using can be used for template which is called alias template

*/

// some identical examples for typedef and using
typedef int Word;
using Word = int;

typedef int* iptr;
using iptr = int*;

typedef int(*fptr)(int);	// fptr is int(*)(int)
using fptr = int(*)(int);

typedef int inta[10];	// inta is int[10]
using inta = int[10];

// alias templates:
template <typename T>
using ptr = T*;

template <typename T>
using ptr1 = const T*;

template <typename T, int size>
using Array = T[size];

template <typename T>
using array5 = T[5];

int main() {
	
	inta x[20]; // int x[20][10]

	ptr<int> p1{ nullptr };		// p1's type is int*
	ptr<double> p2{ nullptr };	// p2's type is double*
	ptr<double*> p3{ nullptr };	// p3's type is double**

	ptr1<int> p4{ nullptr };	// p4's type is const int*
	int y = 20;
	ptr1<int> p5{ &y };
	*p5 = 45;		// syntax error as p5 is const

	Array<int, 5> ar1{};
	Array<double, 20> ar2{};

	array5<long> ar3;
}



