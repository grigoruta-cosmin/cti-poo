#include <bits/stdc++.h>
#include "banca.h"

int Cont::numarCont = 0;

int main(){
    GestiuneConturi<ContCurent> gestiuneContCurent;
    ContCurent * ptrCont = new ContCurent();
    std::cout << dynamic_cast<ContEconomii *>(ptrCont);
    // gestiuneContCurent.adaugaCont();
    // gestiuneContCurent.efectueazaTranzactieLaContul(0);
    // gestiuneContCurent.efectueazaTranzactieLaContul(0);
    // gestiuneContCurent.efectueazaTranzactieLaContul(0);
    // gestiuneContCurent.adaugaCont();
    // gestiuneContCurent.efectueazaTranzactieLaContul(1);
    // gestiuneContCurent.efectueazaTranzactieLaContul(1);
    // gestiuneContCurent.afiseazaConturi();
    ContCurent test("Andrei", 1000, 0, 0, 0);
    ContEconomii test1("Sivliu", 1000, 1, 0.3);
    std::cout << test << std::endl;
    std::cout << test1 << std::endl;
    Banca b;
    b += test;
    b += test1;
    return 0;
}