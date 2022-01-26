#include <iostream>

/*
	how compiler implements virtual dispatch mechanism: by using virtual table pointer in each
		polymorphic class and a virtual function table per class (in all derived classes too)

	vptr is a table pointer (is in object), holds virtual function's table address (created on heap)
	virtual function table is a lookup table accessed by index: called like: car->vptr[1];
		these indexes are obtained during compile time

	virtual function table pointer is base pointer type and all derived classes have it
	virtual function table is like :
			0
			1	&Mercedes::start
			2	&Mercedes::run
			2	&Mercedes::stop
	if you do not override any virtual function, derived vptr will show base vtable, but this time your
		derived class will be pure virtual and you cannot create an object of it

	a polymorphic class is 4B larger than its concrete version as it holds virtual function table's address
	note that, a class, even if you do not write any members, has the size of 1, so that the compiler
		can locate it in memory

	virtual dispatch mechanism costs:
		obj size will increase by sizeof(ptr), and for each class vtable size at heap
		indirection is done twice for car->vptr[1]; 1. to get the object by dereferencing pointer and
			2. to call the function by index
			note that compiler can optimize it with de-virtualization and instead of doing car->vptr[1];
				it can just directly call that function there
		runtime polymorphism is very effective when objects are created dynamically on heap, and it is
			done generally like that
		otherwise it is good to create object on stack which is way effective than creating on heap
		so it depends on what you need, if you are writing coin trading codes where nanoseconds are
			important, ofc do not use virtual dispatch mechanism, rather create your objects on stack

	RTTI: run time type information:
		you should not need to know an object type during runtime; if you need, that means you have
		issues with oop. if you need there is RTTI toolset like typeid(), dynamic_cast

	static vs dynamic type:
		static type is related to compile time, dynamic is related to runtime
			compile time controls are done according to code and static types like concrete
				function checks and parameters etc
			runtime checks are done accroding to dynamic types like for "car.run();" whose run()
				will be called is decided dynamically at runtime
		dynamic type comes with runtime polymorphism
		we have compile time polymorphism as well like function overloading and
			templates (generic programming)

*/
using namespace std;
class Base {
	int x, y;
public:
	virtual void func();	// comment out these virtual functions and check size
	virtual void foo();		// make these functions non-virtual and check size
};

class Der : public Base {
	
};

int main() {

	cout << "sizeof(Base) : " << sizeof(Base) << "\n";
	cout << "sizeof(Der) : " << sizeof(Der) << "\n";
	cout << "sizeof(int*) : " << sizeof(int*) << "\n";

}