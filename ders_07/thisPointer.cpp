

// this pointer ile chaining uygulamasi (diger programlama dillerinde fluent API olarak geciyor)

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
