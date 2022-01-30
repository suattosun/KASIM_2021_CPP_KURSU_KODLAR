/*
* C++ C'deki klasik enum türlerini de destekler.
* C++'da int türünden enum türüne ve farklı enum türleri arasında doğrudan bir dönüşüm yoktur.
* Fakat, enum türünden int türüne bir dönüşüm vardır.
*/

#include <iostream>

enum Color {Red, Blue, Black};
enum Font {Arial, Verdana, Calibri};

int main()
{
    Color mycolor1 = Red; //geçerli 
    Color mycolor2 = 2; //geçerli değil
	
    Font myfont = mycolor1; //geçerli değil

    int ival = mycolor1; //fakat bu geçerli. C++ dizaynı gençlik kusurlarından biri :) Yalnız, kapsamlanırılmış enum'da durum 
    //bu şekilde değil.
}