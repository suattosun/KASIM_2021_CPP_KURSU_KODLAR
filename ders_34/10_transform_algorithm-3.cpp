/**********************    transform algorithm-3   *********************/

// bu arada turlerin ayni olmasi da gerekmiyor.    
// amacimiz yazilarin uzunlugunu bu bagli lsteye eklemek

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "nutility.h"

int square(int x)
{
    return x*x;
}

int main()
{
    std::vector<std::string> svec;
    rfill(svec, 20, rtown);
    std::list<size_t> lenlist(svec.size());

    std::transform(svec.begin(), svec.end(), lenlist.begin(), [](const std::string& str){return str.length();});

    print(svec);
    std::cout << "\n";
    print(lenlist);
}

/*
    Ekran ciktisi:
    trabzon kocaeli kirklareli mersin edirne karabuk konya kars sakarya adana sanliurfa karabuk antalya nevsehir bartin antalya hatay tekirdag mus hatay 
    7 7 10 6 6 7 5 4 7 5 9 7 7 8 6 7 5 8 3 5
*/

