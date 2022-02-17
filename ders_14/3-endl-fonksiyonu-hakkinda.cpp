

#include <iostream>


using namespace std;

int main()
{
	cout << "\n"; // String literali. Iki elemanli bir dizi.
	cout << '\n'; // Karakter sabiti
	cout << endl; // Bir fonksiyon. Yeni satira gecmenin yaninda buffer'i flush ediyor.
	//Maliyeti new line karekterine gore kat kat daha fazla.
	
	////////////////////////////
	const char* p1 = "\n";
	const char* p2 = "\n";

	if (p1 == p2)
		cout << "evet esit";
	else
		cout << "hayir esit degil";
	// Burasi implementation specify, yani derleyiciye bagli derleyici dokumante etmek zorunda degil. 
	// Sonuc derleyiciye bagli olarak degisebilir.

	//Sonuc: newline olusturmak icin karakter sabiti kullanmak daha avantajli. 
}
