#include <bits/stdc++.h>
#include "bautura.h"
#include "comanda.h"
#include "meniu.h"
#include "masa.h"
#include "restaurant.h"

int main(){
    Meniu meniu;
    Comanda com;
    std::cin >> meniu;
    com.setMeniu(meniu);
    com.setComanda();
    for(auto i : com.comandaMancare){
        std::cout << i->get_denumire() << " ";
        if(typeid(*i) == typeid(Ciorba))
            std::cout << "merge"<< std::endl;
        else 
            std::cout << "nu merge" << std::endl;
    }
    std::vector<Mancare *> vectorTest;
    vectorTest.push_back(new Ciorba());
    if(typeid(*vectorTest[0]) == typeid(Ciorba))
        std::cout << "aici merge" << std::endl;
    std::cout << "debug:" << com.comandaBautura.size() << std::endl;
    return 0;
}