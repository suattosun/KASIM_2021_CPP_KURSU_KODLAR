/*
* Tür çıkarımı yapmamın bir diğer yolu da decltype specifier kullanmaktır.
* auto anahtar sözcüğü ile yapılan tür çıkarım kurallarından farklıdır.
*/
int x = 5;

decltype(x) foo(decltype(x)); //geri dönüş tipi ve parametresi
//decltype(x)'in yani int türünden olan fonksiyon bildirimi

int main()
{
    //veya
    decltype(x) y = 20;
}
