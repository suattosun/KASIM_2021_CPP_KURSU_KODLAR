
// "mutable" anahtar sozcugunun kullanimina ornek

class Myclass {
public:
	void func()const;
private:
	//int debug_call_count = 0;
	mutable int debug_call_count = 0;

};

void Myclass::func()const
{
	++debug_call_count; // legal, yukarida mutable anahtar sozcugu kullanildigi icin.
}


