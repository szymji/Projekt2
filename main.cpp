#include <iostream>
#include "tablica.h"

using namespace std;

int main()
{

    Tablica tab;
    for(int i=0;i<5;i++){
        tab.Add(1);
        tab.Add(2);
        tab.Add(3);
    }
    tab.Add(2);
    tab.Add(4);
    tab.Add(4);
    tab.cRemove();
    tab.Print();
    return 0;
}
