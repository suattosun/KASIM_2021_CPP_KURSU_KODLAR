
//inline expansion uygulanip uygulanmamasi ile ilgili ornek



//necati.h boyle olursa -->
class Myclass{
	void set(int);
	int get()const;
private:
	int mx;
};

// ve  necati.cpp boyle olursa -->
void Myclass::set(int x)
{
	mx = x;
}
int Myclass::get()const
{
	return mx;
}

//main.cpp
#include "necati.h"
int main()
{
	Myclass m;
	m.set(12);
	auto val = m.get();
}

// Yukaridaki dosyalama biciminde set ve get fonksiyonlarinin inline expansion olma
//ihtimali yoktur.

////////////////////////////////////////////////////////
// Fonksiyonun inline olmasi icin:
// Function definition veya function declaration'da veya her ikisinde inline anahtar sozcugu 
// kullanilmasi gerekmektedir.

//necati.h boyle olursa -->
class Myclass {
	inline void set(int);
	inline int get()const;
private:
	int mx;
};

inline void Myclass::set(int x)
{
	mx = x;
}
inline int Myclass::get()const
{
	return mx;
}
//Bu durumda fonksiyonlar inline olur ve ODR ihlal edilmez.

///////////////////////////
// fonksiyonu inline yapmanin diger yolu da sinif icinde tanimlamaktir

//necati.h 
class Myclass {
	inline void set(int)
	{
		mx = x;
	}
	inline int get()const
	{
		return mx;
	}
private:
	int mx;
};
// Bu durumda da set ve get fonksiyonlarý inline olur ve ODR ihlal edilmez.

