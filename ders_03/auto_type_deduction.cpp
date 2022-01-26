/***********************************************************************************/
						/* Auto type deduction*/
/***********************************************************************************/
int main() {
	/*auto ile default initialization yapýlamaz.*/
	auto x; //gecersiz.

	auto y = 12;  //copy init
	auto z{ 12 }; //brace init
	auto c(12);  //direct init
}
/***********************************************************************************/
int main() {
	auto x1 = 12; /*x1 türü int*/
	auto x2 = 3.4; /*x2 türü double*/
	auto x3 = 3.4L; /* x3'ün türü long double*/
	auto x4 = 'A'; /*x4 türü char*/
	auto x5 = nullptr; /* x5 türü nullptr_t*/
	auto x6 = 10 > 5; /*bool*/
}
/***********************************************************************************/

int main() {
	char c = 'A';

	auto x1 = c; /*x1 türü char*/
	auto x2 = +c; /*x2 türü int*/

}
/***********************************************************************************/
int main() {
	int x = 10;
	double d = 3.4;

	auto x = x > 5 ? 3 : d;  /*x türü double*/
}
/***********************************************************************************/
int main() {
	int x = 10;
	int& r = x;

	auto a1 = r; /* r'nin türü int & olmasýna karþýn referanslýk düþer. a'nýn türü int'dir*/

	const int y = 10;
	auto a2 = y;	/*referanslýk gibi const'da düþer. a nin türü int */

	const int& cr = x;
	auto a3 = cr;  /*const ve ref düser a3 türü yine int*/

}
/***********************************************************************************/
int main() {
	int a[] = { 1, 2, 3 };

	auto b = a; /*array decay olur b'nin türü (int*) */

}
/***********************************************************************************/
int main() {
	const int a[] = { 1, 2, 3 };

	auto b = a; /*b'nin türü const int* */

}
/***********************************************************************************/
int main() {

	auto x = "mesut"; // x'in türü const char * 

}
/***********************************************************************************/
int foo(int);
int main() {

	auto x = foo; // x'türü int (*)(int) fonksiyon adresi türü.
	auto y = &foo; // x ve y nin türleri aynýdýr.

}
/***********************************************************************************/
int main() {

	int a[10][20];

	auto x = a; // x'in türü int (*)[20] 

}
/***********************************************************************************/
/* auto &  */

int main() {

	int ival{};

	auto& x = ival; // auto ya karþýlýk gelen tür int. x'in türü int & 

	const int ivec{};

	/*constluk dusmez nedeni auto& */
	auto& c = ivec; // autoya karsýlýk gelen tür const int. c nin türü const int& 
}
/***********************************************************************************/
int main() {

	int a[10]{};


	auto& x = a; // auto karsýlýgý int[10] bu durumda x'in türü int (&x)[10] 
}
/***********************************************************************************/

int main() {

	auto& r = "veysel"; //autoya karsýlýk gelen tür const char[7], r'nin türü const char (&r)[7]

}
/***********************************************************************************/
/*Eray ÇINAR*/