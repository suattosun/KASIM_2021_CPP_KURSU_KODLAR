/*
* enum class bir sınıf türü değildir !!! 
* Bunu ispatlama için compile time'da bir türün özelliklerini 
* elde etmeye yarayan aşağıdaki kod kullanıldı
*/

#include <type_traits>

using namespace std;

enum class Color{Blue};

int main()
{
    constexpr bool b = is_class_v<Color>; //sonuç false
    //Çünkü Color bir sınıf değildir!!!
}
