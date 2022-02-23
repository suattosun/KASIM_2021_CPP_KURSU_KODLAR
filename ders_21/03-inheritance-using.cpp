#include <iostream>

class Base {
public:
	void func(int x)
	{
		std::cout << "Base::func(int) x = " << x << '\n';
	}
};

class Der : public Base {
public:
	using Base::func; //func fonksiyonunu scope'a enjekte etmis olduk.
	void func(double x)
	{
		std::cout << "Der::func(double) x = " << x << '\n';
	}
};

int main()
{
	Der myder;
	myder.func(4);
	myder.func(5.1);
	//func fonksiyonu overload edilmis oldu.

}
