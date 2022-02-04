

// this pointer ile fluent API uygulamasi

class Myclass {
public:
	Myclass& func()
	{
		///..
		return *this;
	}
	Myclass& foo()
	{
		///...
		return *this;
	}
	Myclass& bar()
	{
		///...
		return *this;
	}
};

int main()
{
	Myclass m;
	m.foo().bar().func();
}