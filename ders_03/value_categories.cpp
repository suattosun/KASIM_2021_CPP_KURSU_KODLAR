/***********************************************************************************/
					/*Value Categories*/
/***********************************************************************************/
/*
const L value ref = Hem L value hemde R value ile ilk deger verebilirim.
L value ref = L value ifadeler ile ilk deger verebilirim.
R value ref = R value ifadeler ile ilk deger verebilirim.
*/
/***********************************************************************************/
int main() {

	int x = 10;
	int&& r = x; //gecersiz. R value referansa L value expression ilk deger verilemez.

	int&& r = 10;
}
/***********************************************************************************/
#include <iostream>

template<typename T>
struct ValCat {
	static constexpr const char* p = "PR value";
};

template <typename T>
struct ValCat <T&> {
	static constexpr const char* p = "L value";
};

template <typename T>
struct ValCat <T&&> {
	static constexpr const char* p = "X value";
};
#define  print_val_cat(expr)   std::cout << "value category of expr '" #expr "' is : " << ValCat<decltype((expr))>::p << '\n'

#include <iostream>

/*necatieragin/cpp-kursu-kodlar/value_categories/ repostory'de ifadenin value kategorisini ekrana yazan program bulunmakta*/


//PR value
//X value
//L value

int foo();
int& bar();
int&& func();

int main() {

	int x{}; //l value expression 
	print_val_cat(x);

	print_val_cat(x + 5); //pr value 

	int a[120];
	print_val_cat(a); //l value

	print_val_cat(++x); //l value expression
	print_val_cat(x++); //PR value expression

	print_val_cat(--x); //l value expression
	print_val_cat(x--); //PR value expression

	int y;
	print_val_cat((x, y));	//L value expression

	print_val_cat(foo()); //PR value
	print_val_cat(bar()); //L value 
	print_val_cat(func()); //X value 

	int&& r = 10;
	print_val_cat(r);    //l value expression

	print_val_cat(nullptr); //PR value 
}
/***********************************************************************************/
int main() {

	int x = 10;

	int& r1 = ++x; //gecerli L value reference, L value expression baglanabilir.
	int& r2 = x++; //gecersiz L value reference, R value expression baglanamaz.
	int&& r2 = --x; //gecersiz R value reference, L value expression baglanamaz.

}
/***********************************************************************************/
int main() {
	int x = 10;
	int y = 10;
	int z = 10;

	int& r = (x > 5) ? y : z; //gecerli kosul operatoru ile olusuturulan ifade L value expression.
}
/***********************************************************************************/
/*Eray ÇINAR*/