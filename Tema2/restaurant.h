#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "masa.h"

class Restaurant{
    int numarulDeMese;
    std::string nume;
    std::vector<Masa> vectorMese;
    static Meniu meniuRestaurant;
public:
    Restaurant();
    Restaurant(int, std::string);
    void obtineComanda(int);
    void afisMeseOcupate();
    void clientPleaca(int);
    void intraClienti(int);
    void notaToataMasa(int);
    friend std::istream & operator >> (std::istream &, Restaurant &);
    friend std::ostream & operator << (std::ostream &, Restaurant &);
    ~Restaurant() = default;
};

// Meniu Restaurant::meniuRestaurant;

#endif