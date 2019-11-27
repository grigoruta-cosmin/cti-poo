#ifndef COMANDA_H
#define COMANDA_H

// Implementarea clasei Comanda;
#include <bits/stdc++.h>
#include "meniu.h"

class Comanda{
public:
    int countComandaMancare;
    int countComandaBautura;
    int countComandaDesert;
    double notaDePlata;
    Meniu meniu;
    std::vector<Mancare *> comandaMancare;
    std::vector<Bautura *> comandaBautura;
    std::vector<Desert *> comandaDesert;
public:
    Comanda();
    Comanda(int, int, int, double);
    Comanda(const Comanda &);
    void setMeniu(Meniu &meniuR){meniu = meniuR;}
    void afiseazaComanda();
    void setComanda();
    void calculeazaNota();
    double get_notaDePlata() const {return notaDePlata;}
    Comanda & operator = (const Comanda &);
    void testPrint(){
        for(auto i : comandaBautura)
            std::cout << i << " ";
        for(auto i : comandaDesert)
            std::cout << i << " ";
        for(auto i : comandaMancare)
            std::cout << i << " ";
    }
    friend std::istream & operator >> (std::istream &, Comanda &);
    friend std::ostream & operator << (std::ostream &, Comanda &);
    ~Comanda();
};

#endif