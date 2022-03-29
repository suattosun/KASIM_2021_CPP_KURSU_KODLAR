#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"
#include <functional>

using namespace std;

/*
STL's algorithms related to sorting, ordering: functional header

	sort(): nlog(n) complexity, uses less{} by default, has two overloads
		can be used for vector, deque, string, array, c arrays
*/


int main() {

	vector<string> svec;
	rfill(svec, 100, rname);
	// sort(svec.begin(), svec.end());	// uses less{} by default
	// sort(svec.rbegin(), svec.rend());	// when you use reverse iterators, then it will sort reversely
	// sort(svec.begin(), svec.end(), greater{});	// you can use other overload and give transparent function object greater{} to do reversely
	// sort(svec.rbegin(), svec.rend(), greater{});	// this is funny :D
	// or you can have your own criterion: sort alphabetically
	auto fvec = [](const string& s1, const string& s2) { return s1.length() < s2.length() || s1.length() == s2.length() && s1 < s2;};
	sort(svec.begin(), svec.end(), fvec);
	print(svec);

	// it can be a c array or string:
	int a[] = {23, 4, 5, 6, 19, 20};
	print(begin(a), end(a));
	sort(begin(a), end(a));
	// sort(rbegin(a), rend(a));
	// sort(begin(a), end(a), greater{});
	// sort(rbegin(a), rend(a), greater{});
	print(begin(a), end(a));
	
	string str{"necati ergin gurhan sancar irma dibra aysenur bolat"};
	cout << "|" << str << "|\n";
	// sort(begin(str), end(str));
	sort(begin(str), end(str), greater{});
	cout << "|" << str << "|\n";

	// note that sort() uses operator< to sort, so in your custom class operator< must be overloaded if you want to use sort()
	// here in Date, operator< is overloaded:
	vector<Date> dvec;
	rfill(dvec, 20, Date::random);
	print(dvec, "\n");
	// sort(dvec.begin(), dvec.end());
	// sort(dvec.begin(), dvec.end(), greater{});
	// or you can make your own creterion like below:
	const auto fcomp = [](const Date& d1, const Date& d2) {return d1.month() < d2.month(); };
	sort(dvec.begin(), dvec.end(), fcomp);
	print(dvec, "\n");
}

