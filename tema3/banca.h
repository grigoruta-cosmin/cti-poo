#ifndef BANCA_H
#define BANCA_H
#include "gestiuneconturi.h"

class Banca{
    std::string denumireBanca;
    GestiuneConturi<ContCurent> cc;
    GestiuneConturi<ContEconomii> ce;
public:
    Banca() = default;
    Banca(std::string denumire) : denumireBanca(denumire){}
    Banca(const Banca &);
    Banca & operator=(const Cont &);
    Banca & operator+=(const Cont &);
    friend std::ostream & operator<<(std::ostream &, const Banca &);
    friend std::istream & operator>>(std::istream &, Banca &);
    ~Banca() = default;
};
#endif