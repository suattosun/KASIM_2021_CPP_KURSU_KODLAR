class Nec {

public:
	virtual void func() = 0;
};

// abstract class can be only used with pointer or reference semantics:
void foo(Nec*);
void foo2(Nec&);

int main() {

	Nec mynec;	// syntax error as Nec is an abstract class which cannot be instantiated

}