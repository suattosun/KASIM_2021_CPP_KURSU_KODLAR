/***********************************************************************************/
					/*reference semantic*/
/***********************************************************************************/

#include <iostream>
int main()
{
	int x = 10;
	int y = 45;

	int* p = &x;
	// *p demek x demek
	std::cout << "*p =" << *p << "	" << "x = " << x << "\n";

	int& r = x;
	// artýk r demek x demek
	std::cout << "r =" << r << "	" << "x = " << x << "\n";

	++r; //++x
	std::cout << "r =" << r << "	" << "x = " << x << "\n";

	r = y; //x = y ;
	std::cout << "r =" << r << "	" << "x = " << x << "\n";
}

/***********************************************************************************/

int main()
{
	int x = 10;
	int& r = x;	//copy initialization
	int& r1{ x };	//brace initialization
	int& r2(x);     //direct initialization

	/*dinamik ömürlü nesnelerede referans alýnabilir. */
	int* p = new int;
	int& r = *p;

}
/***********************************************************************************/
int main()
{
	int x = 10;
	int& r = x;	//buradaki & bir operator degil declarator.

	int* p = &r; //buradaki * bir operator deðil bir declarator ve buradaki & bir operatör(address of)

}
/***********************************************************************************/

int main()
{
	/*--------------------------------------------------------
	*	references must be initialized
	*	references cannot be default initialized
	---------------------------------------------------------*/

	double dval = 2.43;
	int& r = dval;	//gecersiz
	int* p = &dval; //geçersiz

	unsigned iny x = 10;
	int& r = x;	//geçersiz ayný türden olmak zorunda 

	int& r = 10; //geçersiz	ilk deðer veren ifade L value expression olmak zorunda 10 bir PR value expression'dýr.

}

/***********************************************************************************/
int main()
{
	int a[]{ 1, 2, 3, 4 };
	int* p = a;		//geçerli
	int& r1 = a[2];	//geçerli
	int& r2 = *p;	//geçerli		 
}

/***********************************************************************************/
#include <iostream>
int main()
{
	int x = 10;
	int* p{ &x };

	int*& r = p;	//r demek p demek. p'nin türü int* 

	++* r;
	std::cout << " x = " << x << '\n';
}

/***********************************************************************************/

int main()
{
	int x = 10;
	int* p = &x;
	int** ptr = &p;	/*pointer to pointer var.*/

	/*dogrudan reference to reference yok*/
	int y = 20;
	int& r1 = y;	//r1 demek y demek
	int& r2 = r1;   //r2 demek de y demek
}

/***********************************************************************************/

#include <iostream>
int main() {

	int x = 10;
	int& r1 = x;
	int& r2 = r1;
	int& r3 = r2;

	++r1;
	++r2;
	++r3;
	std::cout << " x = " << x << '\n';
}

/***********************************************************************************/
int main()
{
	/*bir diziye referans oluþturulabilir mi ?*/
	/* evet */
	int ar[]{ 1, 2, 3, 4, 5 }; // ar'nin türü ar[5]

	int(*p)[5] = &ar;	/*pointer to array*/
	/* (*p) demek a demek */

	int(&r)[5] = ar;
	/*r a'nýn yerine geçen bir isim*/

	r[3] = 34; //ar[3] = 34;

	int* ptr = r;	//array decay	
	//int *ptr = a;	//array decay

}
/***********************************************************************************/
int main()
{
	int ar[]{ 1, 2, 3, 4, 5 }; // ar'nin türü ar[5]

	int(&r)[5] = ar;
	auto& r = ar;	//oto type deduction

}
/***********************************************************************************/
int main()
{
	int ar[]{ 1, 2, 3, 4, 5 }; // ar'nin türü ar[5]

	/*dizinin ilk elemanina pointer ve reference alma*/
	int* p = ar;
	int* p2 = &ar[0];
	int& r1 = *ar;
	int& r2 = ar[0];

	/*diziye reference alma*/
	int(&r3)[5] = ar;

}
/***********************************************************************************/
#include <iostream>
/*bir fonksiyonun parametresinin reference olmasý yada pointer olmasý assembly kodunu deðiþtirmez*/
/*call by reference*/

/*bir fonksiyonun parametresinin reference olmasý*/
void bar(int& r)
{
	r = 888;
}

/*bir fonksiyonun parametresinin pointer olmasý*/
void func(int* ptr)
{
	*ptr = 999;
}

int main()
{
	int ival{ 3 };
	std::cout << "ival = " << ival << '\n';
	func(&ival);
	std::cout << "ival = " << ival << '\n';

	int g{ 13 };
	std::cout << "ival = " << ival << '\n';
	bar(g);
	std::cout << "ival = " << ival << '\n';
}
/***********************************************************************************/
#include <iostream>
/*call by value*/
void foo(int x)
{
	x = 999;
}

/*call by reference*/
void bar(int& x)
{
	x = 888;
}
int main()
{
	int ival{ 3 };
	std::cout << "ival = " << ival << "\n";
	foo(ival);
	std::cout << "ival = " << ival << "\n";

	bar(ival);
	std::cout << "ival = " << ival << "\n";
}
/***********************************************************************************/
#include <iostream>
/*nesnelerin deðerlerini takas eden fonksiyonu pointer semantigi kullanarak yapýlmasý*/
void swap(int* p, int* q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
int main()
{
	int a = 456, b = 678;
	std::cout << "a = " << a << "  b=" << b << "\n";
	swap(&a, &b);
	std::cout << "a = " << a << "  b=" << b << "\n";
}
/***********************************************************************************/
#include <iostream>
/*iki nesnenin degerini takas eden fonksiyonu reference semantigi kullanarak yapilmasi*/
void swap(int& p, int& q)
{
	int temp = p;
	p = q;
	q = temp;
}
int main()
{
	int a = 456, b = 678;
	std::cout << "a = " << a << "  b=" << b << "\n";
	swap(a, b);
	std::cout << "a = " << a << "  b=" << b << "\n";
}
/***********************************************************************************/

#include <iostream>
int g = 10;

int* foo(void)
{
	//code
	return &g;
}


int main()
{
	int* p = foo();
	std::cout << " g = " << g << "\n";

	*p = 999;

	std::cout << " g = " << g << "\n";
}
/***********************************************************************************/
#include <iostream>
int g = 10;

int* foo(void)
{
	//code
	return &g;
}


int main()
{
	int* p = foo();
	std::cout << " g = " << g << "\n";

	*foo() = 999;	//operator onceligi kurallarýna gore içerik operatorun operaný foo() ifadeside g nesnesinin adresini dondurdugu için
					//*foo() adresindeki nesneye eriþmiþ olduk

	std::cout << " g = " << g << "\n";
}
/***********************************************************************************/
int* scan_int(void)
{
	int x;
	printf("bir tam sayi giriniz: ");
	scanf("%d", &x);

	return &x; //hayatý biten bir nesnenin (x'in) adresini donduruyoruz undefined behavior
}

/***********************************************************************************/

#include <iostream>
int g = 10;

int& foo(void)
{
	//code
	return g;
}


int main()
{
	std::cout << " g = " << g << "\n";
	int x = foo(); // burada x demek g demek degil cunku x bir reference degil.
	x = 777;
	std::cout << " g = " << g << "\n";
	int& r = foo(); // fonksyion cagrý ifadesi bir L value expression (foo()) oldugundan bir reference baglayabildik
	/*c++ dilinde geri dönüþ türü bir sol taraf referans türü olan fonksiyonlara yapýlan cagrý ifadeleri L value expression'dir*/
	++r;
	std::cout << " g = " << g << "\n";
}

/***********************************************************************************/
/*otomatik omurlu bir nesnenin adresini degistirmek yanlýþ ise, otomatik omurlu bir nesneye referans donen bir fonksiyonda
tamamen ayný sekýlde yanlýþ. undefined behaviour*/
int& foo(int x)
{
	++x;
	return x;	//undefined behaviour. otomatik ömürlü nesneni dondurmesi 
}

int* func(int x)
{
	++x;
	return &x; //undefined behaviour. otomatik ömürlü nesneni dondurmesi 
}

/***********************************************************************************/
/*
fonksiyonun geri dönüþ deðeri L value reference(sol taraf referans) olacaksa aþaðýdaki senaryolardan birinin olmasý gerekir;
a ) statik ömürlü bir nesneye referans dönebilir.
i)global deðiþkenler
ii) statik yerel deðiþkenler
iii) string literalleri

b) dinamik ömürlü bir nesneye referans dönebilir.

c) caðýran koddan aldýðý nesneye referans dönebilir.Aþþaðýdaki kod bloðunda oldugu gibi.
*/
#include <iostream>
int& foo(int& r)
{
	++r;
	return r;
}

int main() {
	int x = 20;
	int& r = foo(x);

	std::cout << " r = " << r << "\n";
	r *= 2;
	std::cout << " r = " << r << "\n";

}
/***********************************************************************************/
/* yukarýdaki kod blogunun pointer semantigi kullanýlarak yazýlmasý */
#include <iostream>
int* foo(int* r)
{
	++* r;
	return r;
}

int main() {
	int x = 20;
	int* r = foo(&x);

	std::cout << " *r = " << *r << "\n";
	*r *= 2;
	std::cout << " r = " << *r << "\n";

}
/***********************************************************************************/
/*Eray ÇINAR*/