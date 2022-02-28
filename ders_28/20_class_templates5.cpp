#include <iostream>
#include<string>

using namespace std;
/*
templates:
	class templates:
*/


/*
here each Myclass specialization will have its own func() function
	like Myclass<int> has a different func(int t) function than Myclass<double> which is func(double t)
so even if class templates' functions are not templates, they are different in each specialization
*/
template<typename T>
class Myclass {
public:
	void func(T t);

	// same is valid for static data members as well
	inline static int x{};
};

int main() {


	// so all of the following x'es are different, each class template spicialization has its own x
	Myclass<int>::x;
	Myclass<long>::x;
	Myclass<double>::x;

}