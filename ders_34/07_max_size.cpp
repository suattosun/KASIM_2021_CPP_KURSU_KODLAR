/**********************    max_size   *********************/

/*
    non-static member func.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
        
    std::cout << "ivec.max_size()=" << ivec.max_size() << "\n";    
}

/*
Saban: Benim derleyicimdeki ekran ciktisi:
ivec.max_size()=2305843009213693951
*/