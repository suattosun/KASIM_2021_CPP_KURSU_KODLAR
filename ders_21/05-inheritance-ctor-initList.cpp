#include <iostream>


class Base {
public:
	Base(int x)
	{
		std::cout << "Base(int x) x ="<<x<<'\n';
	}
	Base(double x)
	{
		std::cout << "Base(double x) x =" << x << '\n';
	}
	Base(int a, int b)
	{
		std::cout << "Base(int a, int b) x =" << a <<" b = "<<b<< '\n';
	}

};

class Der :public Base {
public:
	Der():Base(10)
	{
		//
	}
	//Der() :Base{ 10 } // Kume parantezi ile init etme C++11 ile eklendi
	//{
	//	//
	//}

	Der(int x):Base(x,x)
	{
	
	}
};

int main()
{
	Der myder;
	Der myder2{ 4 };


}
