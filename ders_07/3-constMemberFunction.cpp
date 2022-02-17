

// const member function ornegi



//myclass.h
class Myclass {
public:
	void foo()const;
	void func();
private:
	int mx;

};
//myclass.cpp

void Myclass::foo()const
{
	// this->mx = 45; // sentaks hatasi
	//mx = 45; // sentaks hatasi

	Myclass m;
	m.mx = 20; // sentaks hatasi degil.

}
///////////////////////----------------------------//////////////////////
