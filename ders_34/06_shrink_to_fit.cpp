/**********************    shrink_to_fit   *********************/

/*
    silme sirasinda capacity dusurulmuyordu
    istersek biz resize ile dusurebilirdik
    Modern C++ oncesi bu swap trick denilen , o zamanin mulakatlarinda cok meshur bir trick ile yapilabiliyordu
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(100'000);
    
    std::cout << "ivec.size()=" << ivec.size() << "\n";
    std::cout << "ivec.capacity()=" << ivec.capacity() << "\n";

    ivec.erase(ivec.begin(), ivec.end()-5);

    std::cout << "\n";
    std::cout << "ivec.size()=" << ivec.size() << "\n";
    std::cout << "ivec.capacity()=" << ivec.capacity() << "\n";
}

/*
    Ekran ciktisi:
    ivec.size()=100000
    ivec.capacity()=100000

    ivec.size()=5
    ivec.capacity()=100000

    - eger container'in bir daha 100.00 deger tutacagini dusunmuyorsak capacity i shrink edebiliriz.
    svec.resize(svec.size()) esit midir shrink?
    bu sadece size i dusurur, capacity i degil.
*/

/****************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(100'000);
    
    std::cout << "ivec.size()=" << ivec.size() << "\n";
    std::cout << "ivec.capacity()=" << ivec.capacity() << "\n";

    ivec.erase(ivec.begin(), ivec.end()-5);
    ivec.shrink_to_fit(); //shrink_to_fit sayesinde bu sefer capacity de dusecek!

    std::cout << "\n";
    std::cout << "ivec.size()=" << ivec.size() << "\n";
    std::cout << "ivec.capacity()=" << ivec.capacity() << "\n";
}

/*
    Ekran ciktisi:
    ivec.size()=100000
    ivec.capacity()=100000

    ivec.size()=5
    ivec.capacity()=5 --> shrink_to_fit sayesinde bu sefer capacity de dusmus oldu!
*/


/****************************************************************************/
// Modern C++ oncesi bu swap trick denilen , o zamanin mulakatlarinda cok meshur bir trick ile yapilabiliyordu
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(100'000);
    
    std::cout << "ivec.size()=" << ivec.size() << "\n";
    std::cout << "ivec.capacity()=" << ivec.capacity() << "\n";

    ivec.erase(ivec.begin(), ivec.end()-5);
    
    std::cout << "\nModern C++ oncesi, meshur swap trick!\n";
    vector<int>{ivec}.swap(ivec);

    std::cout << "ivec.size()=" << ivec.size() << "\n";
    std::cout << "ivec.capacity()=" << ivec.capacity() << "\n";
}

/*
    Ekran ciktisi:
    ivec.size()=100000
    ivec.capacity()=100000

    Modern C++ oncesi, meshur swap trick!
    ivec.size()=5
    ivec.capacity()=5
*/
