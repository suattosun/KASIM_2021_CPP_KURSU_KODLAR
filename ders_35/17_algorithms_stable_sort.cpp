#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h"
#include <functional>
#include <fstream>
#include <format>

using namespace std;

/*
STL's algorithms related to sorting, ordering: functional header

	stable_sort():
		stable algorithm means sorting stably
		like if you are holding names and ages but the only sorting criterion is name
			like if some names are same with different ages, they will become one after another, 
				with stable sort the initial relative order of those names won't change
			so if you do normal sort by names, and then stable sort by age, you will have first age order and then name order
		note that normal sort() algorith is not stable

*/

struct Person {
public:
	Person() = default;
	Person(string name, int age) : m_name{ move(name) }, m_age{ age }{};
	friend ostream& operator<<(ostream& os, const Person& per) {
		return os << format("{:<14} {:<5}", per.m_name, per.m_age);
	}

	string name()const { return m_name; };
	int age()const { return m_age; };
private:
	string m_name;
	int m_age;
};

int main() {

	vector<Person> pvec;
	auto f = [] {return Person{ rname(), rand() % 50 + 10 }; };
	rfill(pvec, 10'000, f);
	// first normal sort by name, and then stable sort by age to keep relative order
	sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2) { return p1.name() < p2.name(); });
	stable_sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2) { return p1.age() < p2.age(); });

	ofstream ofs("list.txt");
	print(pvec, "\n", ofs);
	// check list.txt C:\Users\user_name\source\repos\CPP
}

