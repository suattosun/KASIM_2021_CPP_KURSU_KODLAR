/****************	Scope & Name lookup iliskisi  ****************/

/*
  Ayni kavramin iki farkli gozle gorulmesi:
- Scope: Programci gozuyle, biz bu ismi nerelerde kullanabiliriz.
- Name lookup: Derleyici gozuyle, bu isim bir yerde kullanilmis, 
  bu ismi bulmam gerekiyor.
*/

/*
Class scope taki kodlarin bulunmasi icin su kosullarin saglanmasi gerekiyor:
Isim nitelenmis(qualified name) olarak kullanilacak. 
Asagidaki operatorlerden biri ile birlikte kullanilmasi gerekiyor:
- "."
- "->"
- "::(scope resolution operator)". C'de yoktu.
*/

int main()
{
	Nec mynec;
	Nec *mynec;
	mynec.mx; // Buradaki "." operatoru
}


/****************************************************************/
/*
"::" cozunurluk operatoru belkide C++ 'in en cok kullanilan operatorü.
Iki farkli sekilde kullanilabiliyor:	
	::x ile derleyiciye sadece global isim alaninda ara demis oluyoruz.
*/
int x = 34;
int main()
{
	int x = 12; // name hiding(tavsiye edilmeyen bir kullanim!)
	x++;// local x
	::x++; // global olan x e atifta bulunmus olduk.
}


/****************************************************************/
class Myclass{
public:
	int x;
}

int main()
{
		Myclass::x = 5; // Error! Illegal reference to non-static member 'Myclass::x'
}
