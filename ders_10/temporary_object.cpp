/**************************************************************************************
*							Temporary Object
/**************************************************************************************/

/*
* temporary object: içindeki bulundukları ifadenin yürütülmesi tamamlanınca hayatları biter.
*/
#include <iostream>
class myclass {
public:
	myclass(){}
	myclass(int) { }
	~myclass() { std::cout << "~mycass()\n"; }
};
int main()
{
	myclass a;
	a = 21; /*burada derleyici bir temporary object oluşturur.*/
	/*çıktıda iki adet destructor calıştıgını gözmlenebilir.*/
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

/*
* lifetime extension : Eğer bir geçici nesneyi bir referansa bağlarsak
*					   referans olan ismin kapsamının sonuna kadar geçici nesnenin hayatı devam eder.
*/
#include <iostream>
class myclass {
public:
	myclass(){}
	myclass(int) { }
	~myclass() { std::cout << "~mycass()\n"; }
};
int main()
{
	std::cout << "main devam ediyor\n";
	//{  //parantezleri yorum satırından kaldırarak çıktıyı inceleyin.
	const myclass& r = 12;
	/*referans olan nesnenin scopuna kadar temporary object hayatına devam eder buna lifetime extension denir.*/
	//}
	std::cout << "main devam ediyor\n";
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
*/
#include <iostream>
class myclass {
public:
	myclass(){}
	myclass(int) { }
	~myclass() { std::cout << "~mycass()\n"; }
};
int main()
{
	myclass(12);	//bu bir geçici nesnedir.
	myclass();     //geçici nesne

}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Geçici nesne oluşturan ifadeler PR value expression'dır.
* Dolayısı bir L value referans, bir geçici nesne bağlanamaz.
* Ancak const L value referans ve R value referans 'a bağlanabilir.
*/
#include <iostream>
class myclass {
public:
};
int main()
{
	//myclass& r = myclass{};  //geçersiz. L value referans'a bağlanamaz..
	const myclass& rr = myclass{};	//geçerli ve life extension.
	myclass&& r = myclass{};	//gecerli.
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
*/
class myclass {
public:
};

void func(myclass&);
void foo(const myclass&);
void bar(myclass&&);


int main()
{
	func(myclass{}); //geçersiz.
	foo(myclass{});
	bar(myclass{});
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Eğer geçici nesne oluşturma syntax'ı olmasa idi. 
* Bu durumda kendimizin oluşturduğu tüm nesnelerin isimleri olucaktı.
*
* Eğer bir nesneye isim verememizi gerektiricek ikna edici bir senaryo
* 	söz konusu değil ise isimlendirilmiş bir nesne yerine bir geçici nesne kullanın.
*/
#include <string>

void func(const std::string& s);


int main()
{
	std::string myname{ "necati ergin" };
	func(myname);  

	//burada myname nesnesi burda kullanılmayacaksa kötü bir kod olarak yorumlanabilir.
	//ayrıca myname nesnesi heap'te tutulacaktır ve myname ismi ile bir nesne olusturdugumuzda hata olacaktır.

	func(std::string{ "eray" });  //bu problemler olmaz
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*Eray ÇINAR*/