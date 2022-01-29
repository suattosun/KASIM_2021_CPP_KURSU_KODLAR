/* 
* C'de farklı pointer türleri arasında dönüşüm de söz konusudur.
* Bu durumda yine UB davranışlara karşı dikkatli olmak gerekir.
*/
#include <stdio.h>

struct Data{
    int a, b, c;
};

int main(void)
{
    struct Data mydata = {1, 54, 6};
    char* p = (char*)&mydata; //mydata struct Data türünden olmasına karşın adresi char* türünden bir pointer'a aktarıldı.
    //Bunun c++'daki karşılığı reinterpret cast.
}