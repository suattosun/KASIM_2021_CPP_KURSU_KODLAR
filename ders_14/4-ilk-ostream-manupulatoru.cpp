
#include <iostream>

using namespace std;

std::ostream& sline(std::ostream& os)
{
	return os << "\n**********************************************\n";
}


int main()
{
	int x = 4;
	double d = 5.6;
	long lval = 86532L;

	cout << x << sline << d << sline<<lval<<sline;

	/////
	cout << x << sline;
	cout.operator<<(x).operator<<(sline);

}
