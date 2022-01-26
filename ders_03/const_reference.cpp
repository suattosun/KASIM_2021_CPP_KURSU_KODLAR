int main() {

	int a[] = { 0, 1, 3, };
	int(*p)[3] = &a; /*pointer to array. *p demek a dizisi demek*/
	int* ptr = a;	 /**ptr a dizisinin ilk elemaný */

	/*pointer aritmetiðine bakýldýgýnda ptr int kadar artarken p dizinin toplam boyutu kadar artar*/
	printf("%p %p\n", ptr, ptr + 1);
	printf("%p %p\n", p, p + 1);
}
/***********************************************************************************/
int main() {

	int a[] = { 1, 2, 3, 4 };
	int(*p)[4] = &a; /*pointer to array*/

	(*p)[2] = 99;
	int* ptr = *p;	//ptr demek a demek
}
/***********************************************************************************/
int main() {

	int a[] = { 1, 2, 3, 4 };
	int(*p)[4] = &a; /*pointer to array*/
	int* ptr;

	std::cout << "sizeof(*ptr) =" << sizeof(*ptr) << "\n";
	std::cout << "sizeof(*p) =" << sizeof(*p) << "\n";
}
/***********************************************************************************/

/***********************************************************************************/
					/*Const reference*/
/***********************************************************************************/
int main() {

	int x = 10;
	int* p = &x;

	const int* cp = &x;	//pointer to const int 
						//low level const 
	/* *cp'yi salt okuma amaçlý kullanabilirsiniz. */

	/*
		* void func(T *p);	mutater funtion, set function yada setter olarak adlanrýlýr bu fonksyionlar
		  out param

		* void foo(const T*p); accessor, getter, get function olarak adlandýrýlýr bu fonksyionlar
		  input param
	*/
}
/***********************************************************************************/

#include <iostream>
/*const sol taraf referanslarý*/
/* const L value references*/
int main() {
	int x = 10;
	const int& r = x; //r demek x demek 

	int ival = r;	//r'yi set edilmedi, r salt access amaçlý kullanýldý.
	ival = r + 3;

	r = 9;	//gecersiz r set edilemez.

}
/***********************************************************************************/

int main() {
	double d = 3.4;
	int x;
	x = d;	/*narrowing conversion deger kaybý yasanacaktýr.Derleyici uyarý mesajý verir.*/

	int* p = &d; /*gecersiz. türlerin ayný olmasý lazým. C'de legal ancak yanlýþ*/
	int& r = d;	 /*gecersiz.*/
}
/***********************************************************************************/

int main() {

	int x = 10;
	double& r = x;	/*gecersiz. Türlerin ayný olmasý gerekir.*/

	const double& r = x;	//gecerli!!
	/*neden gecerli? derleyicinin ürettiði kod
	const double&r = x;
	{
		const double temp = x;
		const double &r = temp;
	}
	*/

}
/***********************************************************************************/

int main() {

	//L value reference'a R value expression ile ilk deðer verilmiþ.
	//ancak biliyoruz ki reference nesneleri  l value expression ile ilk deðer verilir.
	int& r = 5;	//geçersiz

	const int& r = 5; //gecerli
	/*derleyicinin ürettiði kod.
	const int& r = 5;
	{
		const int temp = 5;
		const int &r = temp;
	}
	*/

}
/***********************************************************************************/

/*foo fonksiyonuna sadece L value  kategorisindeki ifadeler ile çaðýrabilirim.*/
void foo(T&);

/*ancak bar fonksiyonunu hem L value hemde R value deðer kategorisindeki ifadeler ile çaðýrabilirim.*/
void bar(const T&);

/***********************************************************************************/
void pswap(int** ptr1, int** ptr2)
{
	int* ptemp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = ptemp;
}

int main() {

	int x = 10, y = 20;
	int* p1 = &x, * p2 = &y;
	/*oyle bir fonksiyon olsun ki p1 ve p2 degiskenlerini swap etsin*/
	pswap(&p1, &p2);

}
/***********************************************************************************/
/*yukarýdaký kod blogunun reference semantýgý ile yazýlmasý.*/
void pswap(int*& r1, int*& r2)
{
	int* ptemp = r1;
	r1 = r2;
	r2 = ptemp;
}

int main() {

	int x = 10, y = 20;
	int* p1 = &x, * p2 = &y;
	/*oyle bir fonksiyon olsun ki p1 ve p2 degiskenlerini swap etsin*/
	pswap(p1, p2);

}
/***********************************************************************************/
/*
Pointer semantigi ve reference semantigi farklýlýklarý;
i) pointer to pointer var ancak reference to reference yok!
ii) pointer array olabilir ama reference array olamaz ileride bu ihtiyacý
C++ dilinde standart kütüphanesi std::reference_wrapper bakýlacaktýr.
iii) nullptr var ancak null reference yok.
iv) referencelar rebindable deðildir.referansa bir nesne baglandýgýnda scope boyunca baska bir nesne baglanamaz.
*/
/***********************************************************************************/
int foo(int);
int main() {
	/*fonksiyon pointer'ý*/
	int (*fp)(int) = foo;

	/*fonksiyon reference'ý*/
	int(&fpr)(int) = foo;
}
/***********************************************************************************/

int main() {

	int x = 10, y = 20;
	int* const p = &x; /*p baska bir nesneye baglanamaz.*/
	//p = &y; //gecersiz

}
/***********************************************************************************/
/*Eray ÇINAR*/