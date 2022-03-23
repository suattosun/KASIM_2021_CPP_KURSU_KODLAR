/**********************    transform algorithm-2   *********************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "nutility.h"

using namespace std;

int square(int x)
{
    return x*x;
}

int main()
{
    vector<int> ivec{1,4,7,9,12,15,20};
    list<int> ilist(ivec.size());

    int n;
    std::cin >> n;
    transform(ivec.begin(), ivec.end(), ilist.begin(), [n](int a){return a*n;});
    print(ilist);
}

/*
    Ekran ciktisi:
    n=11
    11 44 77 99 132 165 220
*/

/***************************************************************/
// bu da uyelerin yerinde degistigi versiyonu

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "nutility.h"

using namespace std;

int square(int x)
{
    return x*x;
}

int main()
{
    vector<int> ivec{1,4,7,9,12,15,20};

    int n;
    std::cin >> n;
    transform(ivec.begin(), ivec.end(), ivec.begin(), [n](int a){return a*n;});
    print(ivec);
}

/*
    Ekran ciktisi:
    n=5
    5 20 35 45 60 75 100
*/
