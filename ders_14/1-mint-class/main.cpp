
#include "mint.h"
#include <iostream>
#include <fstream>

int main()
{
	using namespace std;
	//1
	Mint x{ 245 }, y{ 8673 }, z{}, t{ 85 };
	x = y * z + t;
	if (x > y)
		cout << x << " > " << y << "\n";

	++x;
	--y;

	//2	
	Mint m1{ 35 }, m2{ 25 };
	cout << m1 << " " << m2;
	operator<<(operator<<(operator<<(cout, m1)," "), m2); // yukaridakinin farkli gösterimi

	//3
	// right shift ve left shift operator overload
	Mint m3, m4;

	std::cout << "iki sayi giriniz: ";
	std::cin >> m3 >> m4;
	std::cout << m3 << " " << m4;

	//4
	//Dosyaya yazdirma ornegi
	std::ofstream ofs{ "deneme.txt" };
	for (int i = 0; i < 10; ++i)
	{
		ofs << Mint{ i } << " ";
	}

	//5
	std::cout << Mint{ 123 } *Mint{ 13 } + Mint{ 90 };

	//6
	auto x = Mint::random();
	

}
