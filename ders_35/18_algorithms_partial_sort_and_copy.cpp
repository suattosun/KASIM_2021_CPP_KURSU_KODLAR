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

	partial_sort(begin, begin + n, end):
		sorts only n names according to a criterion, it does not sort them all only sorts selected ones, the rest is not sorted
			so it does not take as much time as sort() does
		for instance you have 50'000 fighters and want to select strongest 40 sort and fight etc?
	
	partial_sort_copy(begin, end, dest.begin(), dest.end()):
		copies a range to another range, does not sort in place

*/


int main() {
	vector<string> svec;
	rfill(svec, 2000, [] {return rname() + ' ' + rfname(); });
	ofstream ofs("list.txt");

	int n;
	cout << "How many names you want to order: ";
	cin >> n;
	// sort(svec.begin(), svec.end()); // this one sorts them all
	partial_sort(svec.begin(), svec.begin() + n, svec.end());
	print(svec, "\n", ofs);

	vector<string> best(20);
	partial_sort_copy(svec.begin(), svec.end(), best.begin(), best.end());
	print(best, "\n");

}

