#include <iostream>
/*
	 in c, there is no actual boolean type but _Bool
	 and in stdbool.h bool is defined as _Bool, and true is defined as 1 , false is defined as 0
		 comparing and logical operators results in integer value of 1 or 0 in c
	 in cpp bool is a logical type has the value of either true or false
		 comparing and logical operators results in boolean value of true or false in cpp
 */
using namespace std;
int main() {

	cout << "typeid(10 > 5).name(): " << typeid(10 > 5).name() << "\n";
	cout << "typeid('A').name();: " << typeid('A').name() << "\n";
	cout << "typeid(4).name();: " << typeid(4).name() << "\n";
	cout << "typeid(4.).name();: " << typeid(4.).name() << "\n";
	cout << "typeid(4.f).name();: " << typeid(4.f).name() << "\n";

	// in cpp there is automatic conversion from integer types to bool and and vice versa
	int x = 5, y = -5, z = 0;
	bool b = x;		// it will be false only when inited with z
	cout << "boolalpha b:" << boolalpha << b << "\n";
	int t = b;	// t is 1 if b is true, t is 0 if b is false
	cout << "t:" << t << "\n";

	// in cpp:
		// warning!!! there is automatic conversion from address types to boolean
		int* p = &x;
		bool b2 = p;	// nullptr will be false others will be true
		cout << "boolalpha b2:" << boolalpha << b2 << "\n";

		++b2;	// is syntax error
}
