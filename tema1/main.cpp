#include <bits/stdc++.h>
#include "graf_ponderat.h"
#include "list.h"
#include "muchie_pon.h"

int main(){
    Graf_ponderat graf;
    std::cin >> graf;
    //graf.sortVectorMuchii();
    graf.calculeazaMatricePonderiMinime();
    graf.afisareMatrice();
    graf.scriuDrum(1,4);
    return 0;
}