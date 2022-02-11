/****************	this & "*this"  ****************/

/*
Soru: this pointer i neden var?
Global bir fonksiyona icinde bulundugumuz fonksiyon hangi nesne icin cagrilmis 
bu bilgiyi gondermenin baska bir yolu yok!
*/

class Myclass {
private:
public:
		void func(int);
};

voif f(Myclass*);
voif g(Myclass &);

void Myclass::func(int x)
{
	f(this);
}

int main()
{
	Myclass m;
	m.func(12);
}

/****************************************************************/
// Bunun boyle oldugunu ispatlayan bir uygulama:

#include <iostream>

class Myclass {
private:
public:
		void func(int);
};

void f(Myclass* p)
{
	std::cout << "f cagrildi p = " << p << "\n";
}

void g(Myclass& r)
{
	std::cout << "g cagrildi &r = " << &r << "\n";
}

void Myclass::func(int x)
{
	std::cout << "Myclass::func(int) this = " << this << "\n";
	f(this);
	g(*this);
}

int main()
{
	Myclass m;
	
	std::cout << "&m = " << &m << "\n";
	
	m.func(12);
}

/*
Ekran ciktisi:
&m = 0x7ffd4413a837
Myclass::func(int) this = 0x7ffd4413a837
f cagrildi p = 0x7ffd4413a837
g cagrildi &r = 0x7ffd4413a837
*/

/****************************************************************/
/*
	this'in 2.kullanim alani:
	java, c# ta da kullanilan bu yapiya fluent API deniliyor. 
	C++ ta daha cok **chaining** deniliyor.
	x.foo().func().f(); // eger return value Myclass&(this) olursa olur.

	x.foo().func().f();

	x.foo();
	x.func();
	x.f();
*/

// Chain yapisinin belirli faydalari var ama suan o konuya girilmeyecek.

// Geri donus degeri referans tipinde olmali.
// Cunku donus degeri olarak lvalue degiskene ihtiyac var.

/****************************************************************/
#include <iostream>

class Myclass {
private:
public:
	Myclass& foo();
	Myclass& func();
	Myclass& bar();
};

Myclass& Myclass::foo()
{
	std::cout << "Myclass::foo() \n";
	
	return *this;
}

Myclass& Myclass::func()
{
	std::cout << "Myclass::func() \n";
	
	return *this;
}

Myclass& Myclass::bar()
{
	std::cout << "Myclass::bar() \n";
	
	return *this;
}

int main()
{
	Myclass m;
	
	m.bar().foo().func();
}


/*
 Ekran ciktisi:
 Myclass::bar() 
 Myclass::foo() 
 Myclass::func() 

 func. larin geri donus degeri referans degil de Myclass* olsaydi:
 nokta operatoru yerine pointer dan dolayi "->" operatoru kullanmamiz gerekecekti.
*/

/****************************************************************/
/*
func. larin geri donus degeri referans degil de Myclass* olsaydi:
nokta operatoru yerine pointer dan dolayi "->" operatoru kullanmamiz gerekecekti.
Ekran ciktisi tamamen ayni!
*/

#include <iostream>

class Myclass {
private:
public:
	Myclass* foo();
	Myclass* func();
	Myclass* bar();
};

Myclass* Myclass::foo()
{
	std::cout << "Myclass::foo() \n";
	
	return this;
}

Myclass* Myclass::func()
{
	std::cout << "Myclass::func() \n";
	
	return this;
}

Myclass* Myclass::bar()
{
	std::cout << "Myclass::bar() \n";
	
	return this;
}

int main()
{
	Myclass m;
	
	m.bar()->foo()->func();
}



/****************************************************************/
/*
This'i kullandigimda adeta assembly kodda olan, fonksyoun gizli parametresi olan
ama burada gorunmeyen pointer i kullanmis oluyorum.
*/

/*********		Soru: Bu kod legal mi?		*********/ 

class Myclass {
private:
public:
	void func();
};

void Myclass::func()
{
	Myclass m;
	//this = &m; // Koddaki comment acilirsa ne olur?
}

/*
Cevap: this, lvalue olmasi gerekirken pr value oldugundan hata aliyoruz.
Not: This pointer'ini atama operatorunun sol operandi yapamazsiniz!

peki onceki soruda 
*this = m: olsa ne olurdu?
Gecerli olurdu. Cunku *this bir lvalue degiskenidir.
*/


/****************************************************************/
/*
Chaining yapisina ornek olarak, 
bu yapiyi surekli cout fonksiyon cagrilamizda kullaniyoruz.
cout surekli kendini donuyor.
*/

#include <iostream>

int main()
{
	int x = 5;
	double d = 8.9;
	
	std::cout << "x = " << x << " d= " << d << "\n"; // operator overloading
	
	std::cout.operator<<(x).operator<<(d);
}
