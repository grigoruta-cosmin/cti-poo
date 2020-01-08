#include "banca.h"

Banca::Banca(const Banca &other){
    denumireBanca = other.denumireBanca;
    cc = other.cc;
    ce = other.ce;
}

Banca & Banca::operator=(const Banca &other){
    if(this != &other){
        denumireBanca = other.denumireBanca;
        cc = other.cc;
        ce = other.ce; 
    }
    return *this;
}

Banca & Banca::operator+=(const Cont &other){
    try{
        ContCurent c = dynamic_cast<const ContCurent &>(other);
        std::cout << c.getNumeDetinator();
        std::cout << std::endl << std::endl;
        cc.adaugaCont(c);
    }catch(std::bad_cast& e){
        ce.adaugaCont(dynamic_cast<const ContEconomii&>(other));
    }  
}

std::ostream & operator<<(std::ostream &os, const Banca &other){
    os << other.denumireBanca << std::endl;
    os << other.cc << std::endl;
    os << other.ce << std::endl;
    return os;
}