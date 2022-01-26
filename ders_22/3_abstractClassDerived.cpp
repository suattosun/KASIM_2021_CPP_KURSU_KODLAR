/*
	you need to override all pure virtual functions of the base class so that your derived
	class can be a concrete class
*/

class Base {

public:
	virtual void func() = 0;
};

// if derived class does not implement all pure virtual functions in the base class, it becomes an abstract class too
class Der : public Base {
};

int main() {
	Der myder;	// syntax error as Der is an abstract class too
}