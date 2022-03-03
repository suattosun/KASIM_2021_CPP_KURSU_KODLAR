/***************************************************************************************************************************************/

											Namespace(devam)
											
/***************************************************************************************************************************************/


/*
Namespace ADL
*/

namespace Nec
{
	class A{
	public:

	};

	void func(A);
}

void func(Nec::A);
int main()
{
	Nec::A ax;
	func(ax); //gecersiz. ambiguity. 
	/*Free func ile ADL ile bulunan Nec namespace içindeki fonsiyon arasında
	seçme önceliği yoktur bu yüzden ambiguty.*/

}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

/*
nested namespace: namespace içinde olusturulan namespace'lere denir.
*/

namespace nec {

	namespace proj {
		int x;
	}
}

int main()
{
	nec::proj::x = 10;
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* c++11'den sonra yeni kurallar getirildi.
*/

namespace A::B::C {
	int x;
}

namespace A::B {
	int y;
}

namespace A {
	int z;
}
int main()
{
	A::B::C::x = 10;
	A::B::y = 20;
	A::z = 30;
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* inline namespace
*/

namespace nec {

	inline namespace proj {  //proj namespace inline namespace'dir.
		int a, b, c;
	}
}

int main()
{
	nec::a = 10;  //inline sayesinde visiable hale gelir.
}


/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* inline namespace
*/

namespace nec {

	inline namespace proj {  //proj namespace inline namespace'dir.
		int a, b, c;
		inline namespace er {
			int x;
		}
	}
}

int main()
{
	nec::a = 10;  //inline sayesinde visiable hale gelir.

	nec::proj::x;  //inline er sayesinde visiable hale geldi.
}


/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* inline namespace
*/

inline namespace nec {

	inline namespace proj {  //proj namespace inline namespace'dir.
		int a, b, c;
		inline namespace er {
			int x;
		}
	}
}

int main()
{
	x = 10;  //inline namespace ile x visiable hale geldi.
}


/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* inline namespace :
* 
* using namespace bilgirimi ile visiable duruma gelen namespaceler ADL'e tabii olmazlar.
* Ancak inline olarak bildirilen namespaceler ADL'e tabii olurlar.
*/
#include <iostream>
namespace A {

		class myclass {

		};
	namespace B {

		void func(myclass)
		{
			std::cout << "A::B::func(myclass)\n";
		}
	}

	using namespace B; // A namespace'inde doğrudan görülebilir durumda. ADL'e tabi değil.

	inline namespace C {
		
		void bar(myclass)
		{
			std::cout << "A::C::bar(myclass)\n";
		}
	}
}
int main() {
	A::myclass ax;
	bar(ax);   //inline ADL'e gecerli
	func(ax);  //using namespace ADL tabii değil
}



/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* inline namespace : 
* inline bildirimi değiştirerek versiyon atlanabilir.
*/
#include <iostream>

namespace Nec {
	inline namespace ver1 {
		class  myclass {

		};
	}

	namespace ver2 {
		class myclass {

		};
	}
}

int main() {
	Nec::myclass x;

}



/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* inline namespace : 
* önişlemci kodları ile inline değiştirilebilir.
*/
#include <iostream>


#define VER1        //VER1 define hale getirildiğinde ver1 namespace inline hale gelecek.
namespace Nec {

#ifdef VER1
	inline 
#endif
	namespace ver1 {
		class  myclass {

		};
	}
#ifdef VER2
	inline
#endif
	namespace ver2 {
		class myclass {

		};
	}
}

int main() {
	Nec::myclass x;

}



/***************************************************************************************************************************************/
/***************************************************************************************************************************************/

/*
* unnamed namespace
*/
#include <iostream>

/* unnamed namespace'de tanımlanan değişkenler iç bağlantıya aittir.*/
namespace {
	int x=80;
}

int main() {

	std::cout << ::x;
}

/***************************************************************************************************************************************/
/***************************************************************************************************************************************/


/*
* namespace alias
*/
#include <iostream>

namespace c_system_prog {
	int a, b, c;

}

namespace csd = c_system_prog;  //namespace alias. Artık csd ismi "="atmonun sağındaki namespace isminine eş isimdir.

int main() {
	c_system_prog::a = 1;

	csd::a = 14;
}



/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* namespace alias
*/
#include <iostream>

namespace c_system_prog {
	namespace project {
		namespace details {

			int a;
		}
	}
}

namespace details = c_system_prog::project::details;
int main() {
	c_system_prog::project::details::a = 2; //uzun uzun yapmamak için kullanılabilir.
	details::a = 10;

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* namespace alias
*/
#include <iostream>

namespace Std {
	namespace Ranges {
		namespace Views {
			int x;
		}
	}
	namespace Views = Ranges::Views;
}

int main()
{
	Std::Ranges::Views::x = 19;

	Std::Views::x = 2; //namespace alias sayesinde direk olarak views'e erişilebilir.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* namespace alias
*/
#include <iostream>

namespace nec {
	namespace ver1 {

		class myclass {};
	}

	namespace ver2 {

		class myclass{};
	}

}

namespace Cur = nec::ver2;

int main()
{
	Cur::myclass x;

}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
/*
* namespace alias
*/
#include <iostream>
#include<ranges>

int main()
{
	namespace rng = std::ranges;  //sadece main fonksiyonun içinde rng (namespace alias) kullanılabilir.
}
/***************************************************************************************************************************************/
/***************************************************************************************************************************************/
