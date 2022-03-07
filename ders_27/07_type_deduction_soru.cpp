// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

//Soru: T'nin ve function in parametre türleri nedir?

#include

template<typename T>
void func(T &&);

int main()
{
    int ival = 5;
    func(ival);
}


// T --> int &
// function parameter türü --> int &

/* 
    Soru:
    auto&& x = ival; // buradaki x'in türü nedir?

    x rvalue ref degil!
    x Universal Reference. Cikarim nasil yapiliyor?
    auto yerine auto ref gelecek. Cikarim?
    sag taraf ref e & sol taraf ref geldiginden cikarim SOL TARAF ref. olacak.

    - reference a referans kurallari asagidaki gibidir. sadece sag ref e sag ref durumunda sag taraf ref olusuyor. onun disinda hep sol taraf ref
        
    ```
    Reference Collapsing Table
    T&      &        T&
    T&      &&       T&
    T&&      &       T&
    T&&     &&       T&&
 */