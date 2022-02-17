#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <string>


// [] operatorune ait kullanim ornekleri

int main()
{
	// 1.
	int a[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", i[a]);
		//printf("%d\n", *(i + a)); // yukaridaki ile ayni anlama geliyor.
	}

	// 2.
	//std::array<int, 5> ar{ 1, 4, 5,7 }
	std::array ar{ 1, 4, 5,7 }; //C++17 ile birlikte boyle de tanimlayabiliyoruz.
	std::cout << ar[2] << "\n";
	std::cout << ar.operator[](2) << "\n"; // yukaridaki satir ile ayni anlama geliyor.
	++ar[3]; //--> ++ar.operator[](3);

	// 3.
	using namespace std;
	vector<string> namevec{ "Havva", "Necati", "Bilge", "Mesut" };

	for (size_t i{}; i < namevec.size(); ++i)
	{
		namevec[i] += "can"; // vectorde tutulan string nesnesini refreans semantigi ile donuyor.
	}
	for (size_t i{}; i < namevec.size(); ++i)
	{
		cout << namevec[i] << " ";
	}
	

	



}