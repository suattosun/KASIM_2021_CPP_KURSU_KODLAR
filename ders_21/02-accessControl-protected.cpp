#include <iostream>


class Base {
private:
	void func(int);
	int  mx;
protected:
	void f();
public:

};

class Der :public Base {
	void foo()
	{
		//auto a = mx; //gecersiz
		f();
	}
};

int main()
{
	
}
