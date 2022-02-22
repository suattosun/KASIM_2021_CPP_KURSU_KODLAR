
/**************************************************************************************
*							Explicit Conversion Constructor keyword;
/**************************************************************************************/

/*
* Dönüşüm olsun ama otomatik(implicitly) olmasın istersek
* explicit constructor.
*/
class counter{
public:
	explicit counter(int);
	/*explicit only : sadece explicit dönüşüme izin veren implicit dönüşüme izin vermeyen*/
};

int main()
{
	counter x(0);
	int i = 100;
	x = i;		//geçersiz. Artık otomatik dönüşüm yok.

	x = static_cast<counter> (i); //geçerli.
	x = (counter)10;			  //geçerli.
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
*/
class myclass{
public:
	explicit myclass(int);

};

int main()
{
	myclass m1(10); //direct init gecerli
	myclass m2{ 10 }; //brace init gecerli
	myclass m3 = 10;  //copy init gecersiz.
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* copy initialization ile nesne oluşturulduğunda explicit contructor
* overload sete dahil edilmez.
*/
class myclass{
public:
	explicit myclass(int);
	myclass(double);
	myclass(long);
};

int main()
{
	myclass x = 14; //geçersiz. Burada ki syntax hatası explicit conversion ctor overload resolution'a girmemesidir.
	/*yani myclass(double) ve myclass(long) ctor ambiguity oldugu için hata alırız.*/
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Eğer bir dönüşüm normalde syntax hata ise ancak siz bir fonksiyon bildirdiğiniz için
* geçerli oluyorsa yani derleyici ilgili dönüşümü sizin bildirdiğiniz fonksiyona çağrı yaparak
* gerçekleştiriyorsa böyle dönüşümlere user-defined conversion denir.
* 
* Eğer dönüşüm dilin kurallarınca legal ise örneğin double'dan int'e, int'den double'a
* böyle dönüşümlere standart conversion denir.
*/
class myclass{
public:
	 myclass(int);
};

int main()
{

	myclass mx(12);
	mx = 20;		//user-defined conversion

	int ival = 4.5;	//standart conversion
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* c++ dilinde bir dönüşümün implicit olarak yapılıp yapılmayacağı aşağıdaki kurala tabidir;
* Eğer dönüşüm aşağıdaki sekansla ile yapılabiliyor ise ;
*		önce standart conversion --> user_defined conversion
*		önce user-defined conversion --> standart conversion
* Derleyici asla iki defa user-defined conversion uygulamaz
*/
class myclass{
public:
	 myclass(int);
};

int main()
{

	myclass mx(12);
	mx = 2.4;		//user-defined conversion.
	/*burada double türünden int türüne standart conversion*/
	/*int türünden myclass türünede user-defined conversion yapılır.*/
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
*/
class myclass{
public:
	 myclass(){}
	 myclass(bool);
};

int main()
{
	myclass mx;
	int ival;
	
	mx = &ival; /* int* türünden bool türüne dönüşüm gerçekleşicek.   */
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

/*
*/
class A{
public:
};

class B {
public:
	B(){}
	B(A) {}//conversion contructor
};

class C {
public:
	C(){}
	C(B) {} //conversion constructor
};
int main()
{
	A ax;
	B bx;
	C cx;
	bx = ax; //gecerli
	cx = bx; //gecerli

	cx = ax; //gecersiz. Sebebi arka arkaya 2 defa user-defined conversion yapılmaz
	
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*Eray ÇINAR*/