#ifndef MENIU_H
#define MENIU_H

#include <bits/stdc++.h>
#include "bautura.h"
#include "mancare.h"
// Implementarea clasei Meniu

class Meniu{
public:
    friend class Comanda;
    int countListaMancare;
    int countListaBautura;
    int countListaDesert;
    std::vector<Bautura*> listaBautura;
    std::vector<Mancare*> listaMancare;
    std::vector<Desert*> listaDesert;
public:
    Meniu() : countListaMancare(0), countListaDesert(0), countListaBautura(0){}
    Meniu(int , int , int);
    Meniu(const Meniu &);
    void testPrint(){
        for(auto i : listaMancare)
            std::cout << i << " ";
        for(auto i : listaBautura)
            std::cout << i << " ";
        for(auto i : listaDesert)
            std::cout << i << " ";
    }
    friend std::istream & operator >> (std::istream &, Meniu &);
    friend std::ostream & operator << (std::ostream &, Meniu &);
    Meniu & operator=(const Meniu &);  
    ~Meniu();
};

#endif