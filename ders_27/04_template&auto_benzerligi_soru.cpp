/********************************	template argument deduction  ********************************/

// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 


/* 
    Soru:
    Buradaki x'in tipi nedir?
*/

template<typename T>
void func(T x)
{

}

int main()
{
	const int x = 10;
	func(x); // auto icin deduction dusunuldugunde denk ifade "auto y = x;"
}

/* 
    Cevap:
    int x tir. const luk autoda oldugu gibi düser. Imlec func ifadesinin uzerine geldiginde, int oldugunu gorebiliyoruz.
 */