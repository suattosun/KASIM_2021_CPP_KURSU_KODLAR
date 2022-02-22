#include <iostream>

//myclass.h
class Myclass{
public:
    //int a[]; //geçersiz. Çünkü incomplete tip olamaz
    static int a[]; //fakat sınıf içerisinde olmadığından sadece bu bir bildirim.

    //Myclass m; //Geçersiz. Çünkü yine incomplete type. Instance oluşturamayız.
    Myclass *p; //Fakat pointer tanımlamamızda bir engel yok (C'de struct'larda da bu şekilde)
    static Myclass m; //Yine bu geçerli çünkü tanımlması sınıf dışında olacak. Bu bir bildirim. 
};

//myclass.cpp
int Myclass::a[10]; 
//veya
//int Myclass::a[] {10, 20 ,30};

int main()
{

}
