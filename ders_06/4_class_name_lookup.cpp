/****************	CLASS & NAME LOOKUP  ****************/

/****************	Soru: Hata var mi?  ****************/
int x();

int main()
{
	x(); // hata yok!
}

/****************	Soru: Hata var mi?  ****************/
int x();

int main()
{
	//Isim arama kurallarina göre bu degisken x olarak bulunur.
	int x = 10;
	
	// sonrasinda x degiskeninin aslinda function olmadigi anlasilir 
	// ve syntax hatasi alinir.
	x(); //Dikkat! x'in aslinda bir degisken oldugu anlasildiktan sonra tekrardan isim arama yapilmaz!
}

/*
	Isim aramanin altin kurallari:
	1. isim arama (dil tarafindan belirlenen) bir siraya gore yapilir. 
	Once lokal scope icinde arama, 
	daha sonra global isim alaninda aramaya devam etme gibi... 
	Burada detay anlatilmayacak.
	2. Isim arama aranan ismin bulunmasiyla biter ve bir daha baslamaz 
	ve context kontrolu baslar(C yada C++ ogrenenlerin en cok yanlis modellenen konulardan biri)
	Onceki ornegimizde isim aramasi lokal degisken olan x ismini bulur. 
	Sonra context controlu yapar 
	ve x in fonksyon olmadigi icin syntax hatasi ile bitmesine neden olur.
*/
