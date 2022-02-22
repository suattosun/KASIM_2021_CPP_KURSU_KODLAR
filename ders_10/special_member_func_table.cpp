/*******************************************
* 		Special Member Function:
* contructor
* destructor
* copy constructor
* Move constructor
* copy assingment 
* move assingment
*******************************************/


class myclass { 
public:
	myclass(){}
	myclass(const myclass&); //copy constructor
	myclass(myclass&&); //move constructor

	myclass& operator=(const myclass&); //copy assingment
	myclass& operator=(myclass&&); //copy assingment
};
int main()
{
	myclass m1, m2;

	m1 = m2;  //L value expression ile atama yapıldıgından copy consturtor çağrılır.

	m1 = std::move(m2); // R value expression ile atama yapıldığından move consturctor çağrılır.
	/*std::move() : fonksiyonu tek yaptığı L value expression'ı R value expr dönüştürmek.*/
	/*move dosen't move*/
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
class myclass { 
public:
	//..
};
myclass foo();

int main()
{
	myclass mx;
	//atama operatorunun sag tarafındaki ifade pr value expre'dir ve move assingment çalışacaktır.
	mx = foo();
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

class myclass {
public:
	/*aşağıgaki hepsi user declared*/
	//myclass();
	//myclass(){}
	//myclass() = default;
	//myclass() = delete;
};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 1. satırın açıklaması;
1) Eğer hiç bir special member function yazmaz iseniz tüm special funcları derleyici yazar.

*/

/*tüm special functionları derleyici yazar.*/
class base {
public:
};

/*myclass sınıfı ile base sınıfın arasında bir fark yoktur. base sınıfının special member functionlarını derleyici aşağıdaki gibi yazar.*/
class myclass {
public:
	myclass(); //default constructor
	~myclass();	//destructor
	myclass(const myclass&); //copy constructor
	myclass(myclass&&); //move constructor
	myclass& operator=(const myclass&); //copy assingment
	myclass& operator=(myclass&&); //move assingment
};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 2.satırın açıklaması;
Eğer constructor yazarsanız derleyici default constructor yazmaz diğer fonksiyonları yazar.

*/

class myclass {
public:
	myclass(int);
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  myclass(int);
//	~myclass();	//destructor
//	myclass(const myclass&); //copy constructor
//	myclass(myclass&&); //move constructor
//	myclass& operator=(const myclass&); //copy assingment
//	myclass& operator=(myclass&&); //move assingment
//};

int main()
{
	myclass a; /*buradan default contructorun olmadıgını anlayabiliriz.*/
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 3.satırın açıklaması;
Eğer default construtor yazariseniz derleyici geriye kalan fonksiyonları yazar.
*/

class myclass {
public:
	myclass();
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  myclass();
//  ~myclass();	//destructor
//	myclass(const myclass&); //copy constructor
//	myclass(myclass&&); //move constructor
//	myclass& operator=(const myclass&); //copy assingment
//	myclass& operator=(myclass&&); //move assingment
//};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 4.satırın açıklaması;
Eğer siz destructor yazariseniz, derleyici move assingment ve move constructor yazmaz.
copy constructor ve copy assigment(kırmızı renkte) deprecated edilmiş dikkat!
*/

class myclass {
public:
	~myclass();
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  myclass();
//  ~myclass();	//destructor
//	myclass(const myclass&); //copy constructor
//	myclass& operator=(const myclass&); //copy assingment
//};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

/*
TABLO.PNG 5.satırın açıklaması;
Eğer siz copy constructor yazariseniz, default constructor, move assingment ve move contructor yazmaz.
 copy assigment(kırmızı renkte) deprecated edilmiş dikkat!
*/

class myclass {
public:
	myclass(const myclass&);
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  ~myclass();	//destructor
//	myclass(const myclass&); //copy constructor
//	myclass& operator=(const myclass&); //copy assingment
//};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 6.satırın açıklaması;
Eğer siz copy assingment yazariseniz, move assingment ve move contructor yazmaz.
 copy constructor(kırmızı renkte) deprecated edilmiş dikkat!
*/

class myclass {
public:
	myclass& operator=(const myclass&); //copy assingment 
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  myclass(); //default constructor
//  ~myclass();	//destructor
//	myclass(const myclass&); //copy constructor
//	myclass& operator=(const myclass&); //copy assingment
//};

int main()
{
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 7.satırın açıklaması;
Eğer siz move consturctor yazariseniz, default constructor yazmaz ve copy constructor ve copy assingment delete eder.
copy constructor ve copy assingment delete edilmesine dikkat!
*/

class myclass {
public:
	myclass(myclass&&); //move constructor
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  ~myclass();	//destructor
//	myclass(const myclass&) = delete; //copy constructor
//	myclass& operator=(const myclass&) = delete; //copy assingment
//	myclass(myclass&&); //move constructor
//};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
TABLO.PNG 8.satırın açıklaması;
Eğer siz move assingment yazariseniz, move constructor yazamaz ve copy assigment ve copy constructor delete eder.
copy constructor ve copy assingment delete edilmesine dikkat!
*/

class myclass {
public:
	myclass& operator=(myclass&&);//move assingment
};

/*aşağıdaki fonksiyonla üstteki fonksiyon arasında bir fark yoktur.*/
//class myclass {
//public:
//  myclass(); //default constructor
//  ~myclass();	//destructor
//	myclass(const myclass&) = delete; //copy constructor
//	myclass& operator=(const myclass&) = delete; //copy assingment
//	myclass& operator=(myclass&&); //move assingment
//};

int main()
{
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/



/*					Tablo.png çıkarılacak önemli sonuçlar:
1)Eğer bir sınıf aşağıdaki 3 fonksiyondan birini bildirirsek o sınıfın taşıyan özel fonksiyonları yoktur.
  * destructor
  * copy assingment 
  * copy constructor
2) Eğer move constructor ve move assingment sadece birini bildirirsek
derleyici copy memberları delete eder. 

3) Derleyicinin destructor member fonksyionunu her durumda default eder.*/


/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

/*
	move-only classes 
Eğer move memberları user-declared edilir ise copy memberlar delete edilir.
*/

class myclass {
public:
	myclass();

	myclass(myclass&&);
	myclass& operator=(myclass&&);
};

int main()
{

}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Eğer ne taşıma nede kopyalama yapılmamasını istiyorsanız move memberları delete edin.
*/

class myclass {
public:
	myclass();

	myclass(const myclass&) = delete;
	myclass& operator=(const myclass&) = delete;

};
 
int main()
{

}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Eğer sadece kopyalanabilirliği olması taşıma işlemi olmamasını istiyorsak sadece copy memberları declared etmek yeterli.
*/

class myclass {
public:
	myclass();

	myclass(const myclass&);
	myclass& operator=(const myclass&);

};
 
int main()
{

}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/


 /* Move memberları hiç bir zaman delete etmeyin. Move memberları delete ederek kazanım olarak 
 hiç bir şey olmayacaktır. Eğer taşıma özelliği olmamasını istiyorsanız copy memberları user-declared olması yeterli.
 (Tablo5. ve Tablo6. sıra açıklaması)*/
 

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

 //Move semantics hakkında slayt web adresi : https://www.slideshare.net/ripplelabs/howard-hinnant-accu2014
 
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*Eray ÇINAR*/