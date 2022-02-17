/*
* non-static veri elemanları (data memebers) sınıfın fiilen içindedir yani her sınıf için ayrıdır.
* Fakat static data elemanları sınıf başına tektir.
*/

//myclass.h
class Myclass {
public: 
    static int x;//tipik olarak static veri elemanını sınıf içinde bildiriyoruz ve 
    //cpp dosyasında tanımını yapıyoruz
};

//myclass.cpp
int Myclass::x; //tanımda static keyword kullanılmayacak!!! Diğer türlü syntax error.
//Aşağıdaki tanımlarda tabiki mümkün:
//int Myclass::x = 77;
//int Myclass::x(77);
//int Myclass::x{77};

//client.cpp
int main()
{
    Myclass::x = 10; //Eğer x'in tanımı yapılmaz ise linker hatası alınır. 
    //Çünkü henüz x için yer ayrılmamış olur.
}
