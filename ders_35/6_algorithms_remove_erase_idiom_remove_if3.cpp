#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"

using namespace std;

/*
STL's removal algorithms:
	remove-erase idiom
*/

int main() {

	vector<Date> dvec;
	rfill(dvec, 100, Date::random);
	print(dvec, "\n");
	int idx;
	cout << "which days of the week shall be removed? : ";
	cin >> idx;	// 1 monday, 2 tuesday etc...

	dvec.erase(remove_if(dvec.begin(), dvec.end(), [idx](const Date& d) {return d.week_day() == idx; }), dvec.end());
	print(dvec, "\n");

}