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

	partition(begin, end, predicate): O(n) complexity
		divides a container by a predicate which uses condition
		returns partition point which is the one does not conform our condition, so from that point on are the ones we do not want
		this one does not keep relative location
		for instance you want to get all fighters with guns in the front of the vector etc...
			or according to gender, odd even etc, February or not in Date etc
	stable_partition(begin, end, predicate): O(n) complexity
		this one keeps relative location

*/


int main() {
	vector<string> svec;
	rfill(svec, 100, rname);
	print(svec);

	char c;
	cout << "Provide a char to make partition: ";
	cin >> c;

	// auto iter = partition(svec.begin(), svec.end(), [c](const string& s) {return s.find(c) != string::npos; });
	auto iter = stable_partition(svec.begin(), svec.end(), [c](const string& s) {return s.find(c) != string::npos; });

	cout << "\n partition has been completed, partition index: " << distance(svec.begin(), iter) << "\n";

	if (iter != svec.end())
		cout << *iter << "\n";
	print(svec);

}

