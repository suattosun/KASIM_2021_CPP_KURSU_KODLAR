/***************************************************************************************************************************************/

											Nested Types
											
/***************************************************************************************************************************************/
/*
* nested types
* 
*/
#include <iostream>

class myclass {

	class Nested {
		//......
	};

	enum Color{Blue, Black, White};     //nested type

	enum class Pos{On, Off, Hold};    //nested type

	typedef int itype;				 //nested type
	using Word = long;				//nested type
	//....
};

int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
* 1) Bu türler class scope içinde dolası ile isim arama kuralları class scopa göre yapılır.
*/
#include <iostream>

class myclass {
public:
	class Nested {
		//......
	};
};

int main()
{
	Nested x; //gecersiz.
	myclass::Nested x; //gecerli
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
* 1) Bu türler class scope içinde dolası ile isim arama kuralları class scopa göre yapılır.
* 2)şüphesiz ait oldugu scopa ilişkin kullanım vurgulanır.
*/
#include <iostream>

class myclass {
public:
	class Nested {
		//......
	};
private:
};

int main()
{
	myclass::Nested x; //
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
* 1) Bu türler class scope içinde dolası ile isim arama kuralları class scopa göre yapılır.
* 2)şüphesiz ait oldugu scopa ilişkin kullanım vurgulanır.
* 3) erişim kontrolüne tabi
*/
#include <iostream>

class myclass {
	class private_nested {

	};
public:

	class Nested {
		//......
	};
};

int main()
{
	myclass::Nested x;  //public oldugu icin accessible halde.

	myclass::private_nested x; //inaccessible

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
* auto ile private türü kullanılması.
*/

class myclass {

	class Nested {
		//......
	};
public:

	static Nested func();
};

int main()
{
	/*Access control dogrudan isimle ilgili ortada isim olmadığı için gecerli.*/
	auto x = myclass::func();  //gecerli

	/*fiilen isim var "myclass::Nested" inaccessible*/
	myclass::Nested x = myclass::func(); //gecersiz
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
*/

typedef int Nested;

class myclass {

	Nested mx; //buradaki mx int türünden. Nested sınıfı ısım aramada bulunamadı.

	class Nested {
		//......
	};

};

int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
*/

class myclass {

public:

	class Nested {
		//...
	};

	Nested mx; //gecerli
	myclass::Nested xx; //gecerli
};
int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
*/

class myclass {

public:

	class Nested {
	public:
		void foo();
	};
};

/*bu şekilde tanımlanabilir.*/
void myclass::Nested::foo() {

}

int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
*/

class myclass {

public:

	class Nested {
	public:
		void foo(Nested);
	};
};

//void myclass::Nested::foo(myclass::Nested x)
void myclass::Nested::foo(Nested x) {

}

int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
*/

class myclass {

public:

	class Nested {
	public:
		Nested foo(Nested x);
	};
};

//Nested myclass::Nested::foo(Nested x)  //gecersiz
myclass::Nested myclass::Nested::foo(Nested x)  //gecerli
{

}

int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types
*/

class myclass {
public:
	class Nested; //myclass::Nested için forward declaration 
};
int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types & access control
*/

class nec {
public:
	class A {
	private:
		void func();
	};

	void foo()
	{
		A ax;
		ax.func();		//inaccessible. Nested type sahip olmak nested type private bolumune erişim hakkı vermıyor.
	}
};


int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types & access control
* - enclosing class, nested classın private bolumune erişemez.
* - nested class, enclosing class'ın private bolumune erişebilir.
*/

class nec {  //enclosing class
	
	static int x;
	static void foo();
	void func();

	class A {  //nested class
		void func()
		{
			x = 10;  //gecerli

			foo();	 //gecerli
			nec n;    //gecerli
			n.func();	//gecerli

		}
	};

};


int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* nested types & access control
*/

class nec {  
	void foo()
	{
		A ax;  //gecerli
	}

	class A {
		//..
	};
};


int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
