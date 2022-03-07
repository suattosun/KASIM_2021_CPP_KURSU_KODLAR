/********************************	reference collapsing hilesi ********************************/

// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi siddetle tavsiye ederim !!! 

// Reference collapsing kurallarini anlatmak icin soyle bir hile yapiliyor:

int main()
{
    using  mytype = int&;
    int ival{};

    mytype& x = ival;
}


// OR:

int main()
{
    using  mytype = int&;
    int ival{};

    mytype& x; //error message: "'x' declared as reference but not initialized"
}

/*
    Yukaridaki ornekte mytype dedigimiz degisken int gibi bir tür ama "int&" türünde. Dolayisi ile bu ifadenin acilimi aslinda su sekilde:
    mytype & x --> int& & x(sol taraf referansina sol taraf referansi durumu)
    bu da collapsing kurallarinin uygulanmasini gerektiriyor. Sonuc:

    using mytype = int&;
    mytype & x;

    **& ve & --> sonuc x sol taraf reference'i olacak**
    ve syntax hatasi olusacak!
*/

// Or:

using mytype = int&&;
int ival{};

mytype& x = ival; // lvalue ref. e deger atadigimdan hata yok.

// Yorumlamasi:
// **&& ve & --> sonuc x sol taraf reference'i olacak**

// kodu degistirelim,
// OR:

using mytype = int&&;
int ival{};

mytype&& x = 10;

// && ve && --> sonuc x SAG taraf reference'i olacak
/*
    Tekrar etmek gerekirse:
    a- template argument deduction sirasinda
    b- using yada typedef tanimlari yapildiginda reference collapsing kurallari devreye giriyor ve cozumleme yapiliyor.
    Ozet: Sadece sag ref to sag ref = Sag taraf ref
    else
    sol taraf ref olacak!
*/
