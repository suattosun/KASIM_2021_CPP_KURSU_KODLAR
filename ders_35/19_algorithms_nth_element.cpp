#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"
#include <functional>
#include <fstream>
#include <format>
#include <iterator>

using namespace std;

/*
STL's algorithms related to sorting, ordering: functional header

	nth_element(begin, begin+10, end):
		finds the order of the element at the nth index and divides range in two ranges
			like previous ones are smaller, later ones are larger, but not ordered
			but nth element is in the correct order if you order them :D
		so you can find the median value easily by giving size/2 as index
			median is the value in the middle after you order
	
	note that all comparing algorithms used so far have another overload which is for comparing criterion and default less{}
		you can change it if you need to
*/


int main() {
	vector<int> ivec;
	rfill(ivec, 10000, Irand{0, 10000});
	int n;
	cout << "Index: ";
	cin >> n;
	nth_element(ivec.begin(), ivec.begin() + n, ivec.end());
	ofstream ofs("list.txt");
	print(ivec, "\n", ofs);

	// find median:
	nth_element(ivec.begin(), ivec.begin() + ivec.size() / 2, ivec.end());
	cout << "median = " << ivec[ivec.size() / 2] << '\n';
}

