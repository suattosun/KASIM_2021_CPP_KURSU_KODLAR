#include <iostream>
#include <string>

/*
templates:
	function templates:
		range:
			an object created by two positions, locations
			[beg end)	: beg included, end is not
				for n>=0; there can be n many elements in a range
				when you start from beg and increase repeatedly you will reach end, so pointers pointing memory can define a range
*/

void func(int* pbeg, int* pend)
{
	while (pbeg != pend)
	{
		std::cout << *pbeg << ' ';
		++pbeg;
	}
}

// then why not use template?
template <typename Iter>
void Print(Iter beg, Iter end) {
	while (beg != end) {
		std::cout << *beg++ << ' ';
	}
	std::cout << "\n";
}

int main() {
	int a[5] = { 0, 1, 2, 3, 4 };
	// func(a, a + 5); // provide the range to function (starting, ending+1)
	
	// use function template Print()
	Print(a, a + 5);
	Print(a+2, a + 5);
	Print(a, a + 2);

	// Print is a generic function so you can use on any types:
	double da[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Print(da, da + 5);
}