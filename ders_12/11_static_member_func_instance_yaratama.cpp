/*
* Statik üye fonksiyonların sınıfın private bölümüne nasıl erişeceği ile ilgili farklı bir örnek
* Sınıfın constructor'ları neden private yapılabilir sorusuna cevap.
* Bu şekilde doğrudan değil bir statik fonksiyon üzerinden instance yaratma yapılabilir.
*/

class Myclass {
public:
    static Myclass foo();
private:
    Myclass() {} //private default ctor
};

Myclass Myclass::foo()
{
    Myclass m;
    return m;
}

int main()
{
    Myclass a{Myclass::foo()};
}
