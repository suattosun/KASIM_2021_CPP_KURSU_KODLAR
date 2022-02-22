
/**************************************************************************************
*							Copy Elision
/**************************************************************************************/

/*
*	Copy elision:
* Bir kodun verimini yükselten optimizasyondur.
* C++17 standartlarından sonra dilin kuralı haline gelmiştir ve
* Mandatory copy elision denir.
* 
* Eğer bir fonksiyonun parametre değişkeni bir sınıf türünden ise ve bu fonksiyon argüman olarak
* bir R value expression olan bir sınıf nesnesi ile çağrılırsa mandatory copy elision devreye girer.
* Yani aynı nesneyi kullanmış oluruz.
*/
#include <iostream>
class myclass {
public:
	myclass() {
		std::cout << "default ctor\n";
	}

	myclass(const myclass&)
	{
		std::cout << "copy ctor\n";
	}

	myclass(myclass&&)
	{
		std::cout << "move ctor\n";
	}
};

void foo(myclass)
{

}
int main()
{
	foo(myclass{});  //copy contructor nede move construcotor cagrılmayacak
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* fonksiyon çağrısındaki arguman olan ifadenin ne olduguna bağlı olarak olabilecekşer;
*  - Parametre için copy constructor çağrılır.
*  - Parametre için move contructor çağrılması.
*  - Copy yada move memberların cagrılmaması. Geçici nesne kullanarak.
*/
#include <iostream>
class myclass{
public:
	myclass(){
		std::cout << "default ctor\n";
	}
	myclass(const myclass&) {
		std::cout << "copy ctor\n";
	}
	myclass(myclass&&)
	{
		std::cout << "move ctor\n";
	}
};

/*modern c++'da fonksiyonun parametresinin pointer yada referans olmaması bir çok durumda tercih edilir.*/
void func(myclass val)
{

}
int main()
{
	myclass x;
	func(x);			// copy ctor cagrıldı.

	func(std::move(x)); // move ctor cagrıldı.

	func(myclass{});    //move yada copy ctor cagrılmayacak.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
