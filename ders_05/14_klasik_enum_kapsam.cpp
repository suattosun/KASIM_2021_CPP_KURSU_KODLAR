/*
* Klasik enum türlerinin kendi kapsamları olmadığı için isim çakışması gibi problemler oluşabilir.
*/

#include <iostream>

enum ScreenColor {gray, red, blue, magenta, black};
enum TrafficLight {green, yellow, red}; //red her iki enum türünde de bulunduğu için redefination hatası oluşacaktır.

int main()
{
	
}