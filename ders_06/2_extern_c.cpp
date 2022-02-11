/****************	extern "C"  ****************/

/*
	- C de func. overloading yok C++ ta var. Bundan dolayi;

	Ornegin bir func(1, 3, 5); fonksiyonumuz olsun 

	- C de compiler foksyonu soyle tarif edebilir "@func"
	- C++ ta bunun icin belki su sekilde bir dekore gerekecek. "_func@i@i@i"
	  C ve C++ arasindaki bu uyumsuzluk(Object module yazilan external referans olan ismin dekore edilmesindeki farklilik) 
	  C++ icinde C de derlenmis bir fonksyon cagrildiginda derleyici eger onun C de yazilmis oldugunu bilmez ise 
	  C++ tipi dekore edince hata alacaktir.

	- Durumu test etmek icin ".c" uzantili bir dosya olusturursak.
*/

#include "necati.h"
#include <iostream>

int main()
{
	int x = foo(12, 45);
	
	std::cout << "x = " << x << "\n";
}

/*
  - Yukaridaki kodda compile hatasi yok. link hatasi var(unresolved)
  
  - Bu eklenti C++ compiler a bu foknksiyonu C tarzinda dekore etmesi gerektigini soyler.
    extern "C" int foo(int, int); 
    
- 2 farkli sekilde extern "C" tanimlamasi yapilabilir:
    1-)
		extern "C" int f1(int, int);
		extern "C" int f2(int, int);
		extern "C" int f3(int, int);
		extern "C" int f4(int, int);
		extern "C" int f5(int, int);
    2-) Öyle bir yazim tarzina ihtiyacim var ki; hem C de hem C++ ta ayni dosyayi kullandigimda iki tarafta da hata almayayim.
    Bunun icin on tanimli
		
		#ifndef __cplusplus
		extern "C" {
		#endif
		int f1(int, int);
		int f2(int, int);
		int f3(int, int);
		int f4(int, int);
		int f5(int, int);
		#ifndef __cplusplus
		}
		#endif#
*/