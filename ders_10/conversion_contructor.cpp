/**************************************************************************************
*							Conversion contructor;
/**************************************************************************************/

/*
* Sınıfın parametreli constructor'ı special member function degildir.
*/


class myclass {
public:
	myclass();

	/*sınıfın special member constructorı degildir.*/
	myclass(int); 
	/*Genel olarak conversion contructor denir.*/
};
 
int main()
{

}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
class myclass {
public:
	myclass() = default;

	myclass(int); 
};
 
int main()
{
	myclass x;
	x = 5; /*conversion ctor sayesinde myclass-int dönüsümü gercekleşti.*/
	/* derleyici tarafında gerceklesen işlemler;
	*	myclass temp(5);		burada derleyici gecici nesne oluşturur(temp semboliktir)
	*	x = temp;				x'e temp nesnesi atandı		
	*	temp.~mylcass();		temp nesnesi silindi.
	*/
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
#include <iostream>
/*
* Kodun çıktısı:
*	Default constructor this : 012FF80F				--> myclass x; nesnesinin hayata gelmesi
	myclass(int x) x = 5 this : 012FF80E			--> derleyicinin olusturgunu gecici nesnenin adresi
	copy assingment : 012FF80F & other = 012FF80E	--> gecici nesnenin x nesnesine atanması
	myclass destructor this : 012FF80E				--> gecici nesnenin hayatının son bulması
	myclass destructor this : 012FF80F				--> x nesnesinin hayatının son bulması
*/
class myclass {
public:
	myclass() { std::cout << "Default constructor this : " << this << "\n"; };
	myclass(int x)
	{
		std::cout << "myclass(int x) x = " << x << " this : " << this << "\n";
	}

	~myclass()
	{
		std::cout << "myclass destructor this : " << this << "\n";
	}
	
	myclass& operator=(const myclass& other)
	{
		std::cout << "copy assingment : " << this << " & other = " << &other << "\n";
		return *this;
	}
};
 
int main()
{
	myclass x;
	x = 5; 
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
#include <iostream>

class myclass {
public:
	myclass(int x)
	{
		std::cout << "myclass(int x) x = " << x << " this : " << this << "\n";
	}
};
void func(myclass m)
{

}

void foo(const myclass& r)
{

}
myclass bar()
{
	return 10;
}
int main()
{
	myclass m1(10);		//gecerli
	myclass m2 = 10;	//gecerli
	func(10);			//gecerli
	foo(20);			//gecerli
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
#include <iostream>
/*
* Conversion contructor otomatik tür dönüşümü bazen istenebilir(çok az oranda).
*/
class counter{
public:
	counter(int);
};
int main()
{
	counter x(0);
	int i = 100;
	x = i;	/*Burada dönüşüm otomatik olarak yapılır.*/
	/*ancak otomatik dönüşümün sorun teşkil ettiği senaryolarda bu hatayı bulmak çok zor olabilir. */
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*Eray ÇINAR*/