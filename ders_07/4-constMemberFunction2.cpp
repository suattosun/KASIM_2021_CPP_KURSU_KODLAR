

// const member function ornegi
// Sinifin non-const uye fonksiyonu sinifin uye fonksiyonlarini cagirabilir.
// Sinifin const uye fonksiyonu sinifin non-const uye fonksiyonlarini cagiramaz.

// Const bir sinif nesnesi icin yalnizca sinifin const uye islevlerini cagirabilir.
// Const bir sinif nesnesi icin yalnizca sinifin non-const uye islevlerini cagiramayiz.


//myclass.h
class Myclass {
public:
	void foo()const;
	void func();

	Myclass& foo(int)const;
	const Myclass* func(int)const;

private:
	int mx;

};

//myclass.cpp
void Myclass::func()
{
	foo(); // legal
}


void Myclass::foo()const
{
	func(); //sentaks hatasi.  
}


Myclass& Myclass::foo(int)const
{
	//..
	return *this; //sentaks hatasi
	//const olmayan sol taraf referansini const nesneye baglamaya
	//calistigimizdan sentaks hatasi.
}

const Myclass* Myclass::func(int)const
{
	return this; // legal
}
