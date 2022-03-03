/***************************************************************************************************************************************/

											Composition (Containment)
											
/***************************************************************************************************************************************/
/*
* Composition (containment)
*/

class Nec {

};

class myclass {
public:
	Nec x;

};


int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
*
* 
*							Classlar arasındaki ilişkileri niteleyen terimler
* depandancy:  Bir sınıfın belirli bir operasyon için başka bir sınıfı kullanması ilişkisi.
* association: Birbirlerinin farkında olan iki sınıfın birbirleri manipülasyon için kullanıyorsa 
* aggregation: İki sınıfıntan biri diğerinin sahibi ise adlandırılan terim.  Her aggregation bir association.
* composition: İki sınıf arasında ömürsel bir birliktelik olması. 
*/
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
* Başka sınıf türünden elemana sahip olan sınıf eleman olan sınıfın private bolumune erişim hakkı vermez.
*/
class A {
public:
	void pubfoo();

private:
	void prifunc();
};

class B {
public:
	void f() {
		ax.pubfoo();		//gecerlli
		ax.prifunc();		//inaccessible gecersiz.
	}
private:
	A ax;
};

int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
*/
//dikkat! non-static data member comlepte type olması gerekir.

class A; //incomplate type , tamamlanmamış tür

class B {
	A ax;	//gecersiz. complete type olması gerekir.
	A* ptr;	//gecerli
	A& ra;	//gecerli
};
int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
* hayata gelme sırası
*/
class member {

};

class owner {
public:
	~owner()
	{
		//burada mx kullanılabilir. mx hayata gelmıs durumda
	}
	member mx;
};


int main()
{

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
*/

class member {
public:
	member(int);
};

class myclass {

	/*myclass default ctor derleyici yazacak ve derleyici sınıfın üyelerini default init eder.*/
	/*  derleyici mx default init etmesi gecersiz ise(member default ctor yok) derleyici myclassın default ctor delete eder. */
	member mx; //gecerli
};
int main()
{
	myclass m;   //syntax hatası.default ctor delete edildiği icin.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
*/

class myclass {
public:
	myclass(int);
};
int main()
{
	myclass m;   //gecersiz. myclass default ctor derleyici tarafından yazılmaz.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
*/

class myclass {
public:

private:
	const int x;
};


int main()
{
	myclass m;  //gecersiz. derleyicinin default ctor data memberları default init edicek ancak
				//const int x default init etmek mumkun degıl derletici default ctor delete eder.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
*/
#include <iostream>
class member{
public:
	member() {
		std::cout << "Member ctor\n";
	}

	~member() {
		std::cout << "Member dtor\n";
	}

};

class owner {
public:
	member mx;

};

int main()
{
	owner x;  //memberın ctor ve dtor calısacak. cıktıyı inceleyin.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
* owner sınıfı ile member sınıfı fiziksel olarakta aynı bellek alanında.
*/
#include <iostream>
class member{
	int x, y, z, t;

};

class owner {
	member mx;
	member my;
};

int main()
{
	std::cout << "sizeof(member) : " << sizeof(member)<< "\n";
	std::cout << "sizeof(owner) : "  <<sizeof(owner) << "\n";
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* Composition (containment)
* 
*/
#include <iostream>

class member {
public:
	member() {
		std::cout << "Member ctor\n";
	}
	~member() {
		std::cout << "Member dtor\n";
	}
};

class owner {
public:
	owner() {
		std::cout << "owner ctor\n";
	}
	~owner() {
		std::cout << "owner dtor\n";
	}
private:
	member mx;
};
int main()
{
	owner ax;  //çıktıyı gözlemleyin.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
